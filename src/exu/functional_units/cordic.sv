`default_nettype wire

module cordic #(
    parameter int ITER=tinytracer_pkg::WLEN
) (
    input  logic        clk,
    input  logic        rst_n,

    // FU <-> CORDIC Interface
    fu_if.server        fu
);

// Packed tables keep the original LUT values while avoiding unpacked
// parameter arrays, which the GDS Yosys frontend does not parse here.
// Entries are concatenated in reverse index order so index 0 is the low word.
localparam [255:0] ATAN_LUT = {
    16'h0001,
    16'h0001,
    16'h0002,
    16'h0004,
    16'h0008,
    16'h0010,
    16'h0020,
    16'h0040,
    16'h0080,
    16'h0100,
    16'h0200,
    16'h03FF,
    16'h07F5,
    16'h0FAE,
    16'h1DAC,
    16'h3244
};

localparam [255:0] ATANH_LUT = {
    16'h0001,
    16'h0001,
    16'h0001,
    16'h0002,
    16'h0004,
    16'h0008,
    16'h0010,
    16'h0020,
    16'h0040,
    16'h0080,
    16'h0100,
    16'h0200,
    16'h0401,
    16'h080B,
    16'h1059,
    16'h2328
};

parameter   IDLE = 3'b000,
            INIT = 3'b001,
            NORMALIZE = 3'b011,
            LOOP = 3'b010,
            REVERT = 3'b110,
            POSTSCALE = 3'b100;


reg [2:0] current_state, next_state;
reg [3:0] cycles_completed;
reg [3:0] j;
reg signed [15:0] x, y, z;
reg signed [15:0] x_next, y_next, z_next;
reg repeated;
wire start;
reg [3:0] k, l, shift_next, shift_q;
reg shift_right_next, shift_right_q;
reg tooBig;
reg signed [15:0] ym, xp, normalized;
reg signed [31:0] postscale_product, postscale_result;
reg neg_q, neg_next;
reg angleShift;
reg [1:0] opcode;
reg format;


assign start = fu.req_valid && !(fu.req_opcode == 2'b01 && fu.req_op1[15] == 1'b1);

always @(posedge clk) begin
    if (!rst_n) begin
        current_state <= IDLE;
        cycles_completed <= 4'b0;
        repeated <= 1'b0;
        j <= 4'b0001;
        shift_q <= 4'b0;
        shift_right_q <= 1'b0;
        opcode <= 2'b00;
        x <= 16'sd0;
        y <= 16'sd0;
        z <= 16'sd0;
        neg_q <= 1'b0;
    end else begin
        current_state <= next_state;
        
        x <= x_next;
        y <= y_next;
        z <= z_next;
        shift_q <= shift_next;
        shift_right_q <= shift_right_next;
        neg_q <= neg_next;

        if (current_state == IDLE && start) begin
            opcode <= fu.req_opcode[1:0];
            format <= fu.req_fmt;
            cycles_completed <= 4'b0;
            repeated <= 1'b0;
            j <= 4'b0001;
            shift_q <= 4'b0;
            shift_right_q <= 1'b0;
            neg_q <= 1'b0;
        end else if (current_state == LOOP) begin
            cycles_completed <= cycles_completed + 1;
            if ((~cycles_completed[1] & cycles_completed[2] & ~(cycles_completed[3]^cycles_completed[0])) 
                && opcode == 2'b01 && !repeated)  begin// 4 or 13
                j <= j;
                repeated <= 1'b1;
            end else begin
                j <=  j+1;
                repeated <= 1'b0;
            end
        end
    end
end

always @(*) begin 
    next_state = IDLE;
    case(current_state)
        IDLE:
        begin
            if (start)
                next_state = INIT;
            else
                next_state = IDLE;
        end
        INIT:
            next_state = NORMALIZE;
        NORMALIZE:
            next_state = LOOP;
        LOOP:
        begin
            if (cycles_completed == ITER-1) 
                next_state = REVERT;
            else
                next_state = LOOP;
        end
        REVERT:
            next_state = POSTSCALE;
        POSTSCALE:
            next_state = IDLE;
    endcase
end    

always @(*) begin
    fu.req_ready = 1'b0;
    fu.resp_done = 1'b0;
    fu.resp_result = 16'b0;
    x_next = x;
    y_next = y;
    z_next = z;
    shift_next = shift_q;
    shift_right_next = shift_right_q;
    neg_next = neg_q;
    k = 4'b0;
    l = 4'b0;
    tooBig = 1'b0;
    ym = 16'sd0;
    xp = 16'sd0;
    angleShift = 1'b0;
    normalized = x;
    postscale_product = 32'sd0;
    postscale_result = 32'sd0;
    case(current_state)
        IDLE:
            fu.req_ready = 1'b1;
        INIT:
        begin
            if (opcode == 2'b00) begin
                x_next = fu.req_op2;
                y_next = fu.req_op1;
                z_next = 16'h0000;
            end else if (opcode == 2'b10) begin
                x_next = 16'h26DD;
                y_next = 16'h0000;
                z_next = fu.req_op2;
            end else if (opcode == 2'b11) begin
                x_next = fu.req_op1;
                y_next = fu.req_op2;
                z_next = 16'h0000;
            end else begin
                x_next = fu.req_op1;
                y_next = fu.req_op1;
                z_next = 16'h0000;
            end
        end
        NORMALIZE:
        begin
            if (opcode == 2'b00) begin
                neg_next = x[15];
                ym = y[15] ? ~y : y;
                xp = neg_next ? -x : x;
                k = 0; l = 0;
                for (int i = 0; i < 15; i++) begin
                    if (xp[i])  
                        k = i;
                end
                for (int h = 0; h < 15; h++) begin
                    if (y[h]) 
                        l = h;
                end
                if (ym > x) begin
                    if (ym[14]) begin
                        y_next  = y >>> 1;
                        x_next  = xp <<< (14 - k);        
                        shift_next = 15 - k;
                    end else begin
                        x_next  = xp <<< (l - k + 1);
                        shift_next = l-k+1;
                    end
                end
            end else if (opcode == 2'b10) begin
                angleShift = (z > 16'sh6F92 || z < 16'sh906E);
                if (angleShift) 
                    z_next = z + (z[15] ? 17'h0C910 : 17'h136F0);
            end else if (opcode == 2'b11) begin
                x_next = x[15]? -x:x ;
                y_next = y[15]? -y:y ;
            end else if (opcode == 2'b01) begin
                tooBig = |x[14:8];
                normalized = x;
                    if (((tooBig | (~x[6] & ~x[7])) & ~format) 
                        | ((~x[13] & ~x[14]) & format)) begin //under 0.5 or over 2
                        for (int i = 0; i < 15; i++) begin
                            if (x[i]) 
                                k = i;
                        end
                        if (format) begin
                            shift_next = k[0] ? 13-k : 14-k;
                            shift_right_next = 1'b0;
                            normalized = x <<< shift_next;
                        end else if (tooBig) begin
                            shift_next = k - (k[0] ? 7 : 6);
                            shift_right_next = 1'b1;
                            normalized = x >>> shift_next;
                        end else begin
                            shift_next = (k[0] ? 7 : 6) - k;
                            shift_right_next = 1'b0;
                            normalized = x <<< shift_next;
                        end
                    end
                    if (format) begin
                        x_next = normalized + 16'h1000;
                        y_next = normalized - 16'h1000;
                    end else begin
                        x_next = normalized + 16'h0020;
                        y_next = normalized - 16'h0020;
                    end
                end
            end
        LOOP:
            if (opcode == 2'b00) begin
                if (y[15]== 1'b1) begin
                    y_next = y + (x >>> cycles_completed);
                    z_next = z - (16'h4000 >>> cycles_completed);
                end else begin
                    y_next = y - (x >>> cycles_completed);
                    z_next = z + (16'h4000 >>> cycles_completed);
                end
            end else if (opcode == 2'b10) begin
                if (z[15]== 1'b1) begin
                    x_next = x + (y >>> cycles_completed);
                    y_next = y - (x >>> cycles_completed);
                    z_next = z + ATAN_LUT[{cycles_completed, 4'b0} +: 16];
                end else begin
                    x_next = x - (y >>> cycles_completed);
                    y_next = y + (x >>> cycles_completed);
                    z_next = z - ATAN_LUT[{cycles_completed, 4'b0} +: 16];
                end
            end else if (opcode == 2'b11) begin
                if (y[15]== 1'b1) begin
                    x_next = x - (y >>> cycles_completed);
                    y_next = y + (x >>> cycles_completed);
                    z_next = z - ATAN_LUT[{cycles_completed, 4'b0} +: 16];
                end else begin
                    x_next = x + (y >>> cycles_completed);
                    y_next = y - (x >>> cycles_completed);
                    z_next = z + ATAN_LUT[{cycles_completed, 4'b0} +: 16];
                end
            end else begin
                if (y[15]== 1'b1) begin
                    x_next = x + (y >>> j);
                    y_next = y + (x >>> j);
                    z_next = z - ATANH_LUT[{(j - 4'd1), 4'b0} +: 16];
                end else begin
                    x_next = x - (y >>> j);
                    y_next = y - (x >>> j);
                    z_next = z + ATANH_LUT[{(j - 4'd1), 4'b0} +: 16];
                end
            end
        REVERT:
        begin
            if (opcode ==  2'b00) begin
                z_next = z <<< shift_q;
            end else if (opcode == 2'b10) begin
                x_next = angleShift? -x : x;
                y_next = angleShift? -y : y;
            end else if (opcode == 2'b01) begin
                x_next = shift_right_q? x <<< ((shift_q) >>> 1'b1) : x >>> ((shift_q) >>> 1'b1);
            end
        end
        POSTSCALE:
        begin
            if (opcode == 2'b11) begin
                // Magnitude gain correction: 0.60725 ~= 9945 / 2^14.
                postscale_product =
                    ({16'b0, x} <<< 13)
                  + ({16'b0, x} <<< 11)
                  - ({16'b0, x} <<< 8)
                  - ({16'b0, x} <<< 5)
                  - ({16'b0, x} <<< 3)
                  +  {16'b0, x};
                postscale_result = postscale_product >>> 14;
                if (postscale_result > 32'sd32767)
                    x_next = 16'h7FFF;
                else if (postscale_result < -32'sd32768)
                    x_next = 16'h8000;
                else
                    x_next = postscale_result[15:0];
            end else if (opcode == 2'b01) begin
                // Square-root gain correction: 1.2075 ~= 19784 / 2^14.
                postscale_product =
                    ({16'b0, x} <<< 14)
                  + ({16'b0, x} <<< 12)
                  - ({16'b0, x} <<< 9)
                  - ({16'b0, x} <<< 7)
                  - ({16'b0, x} <<< 6)
                  + ({16'b0, x} <<< 3);
                postscale_result = postscale_product >>> 14;
                if (postscale_result > 32'sd32767)
                    x_next = 16'h7FFF;
                else if (postscale_result < -32'sd32768)
                    x_next = 16'h8000;
                else
                    x_next = postscale_result[15:0];
            end

            fu.resp_done = 1'b1;
            case (opcode)
                2'b00: fu.resp_result = z;
                2'b01: fu.resp_result = x_next;
                2'b10: fu.resp_result = x;
                2'b11: fu.resp_result = x_next;
            endcase
        end
        

    endcase
    
end

endmodule
