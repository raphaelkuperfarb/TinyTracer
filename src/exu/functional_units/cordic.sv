`default_nettype wire

module cordic #(
    parameter int ITER=tinytracer_pkg::WLEN
) (
    input  logic        clk,
    input  logic        rst_n,

    // FU <-> CORDIC Interface
    fu_if.server        fu
);


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


parameter   IDLE = 3'b000,
            INIT = 3'b001,
            NORMALIZE = 3'b011,
            LOOP = 3'b010,
            REVERT = 3'b110,
            POSTSCALE = 3'b100;


reg [2:0] current_state, next_state;
reg [3:0] cycles_completed;
reg [4:0] j;
reg [4:0] iteration;
reg signed [15:0] x, y, z;
reg signed [15:0] x_next, y_next, z_next;
reg signed [15:0] negative_x, negative_y;
reg signed [15:0] x_shifted, y_shifted;
reg [3:0] shift_by;
reg x_subtract, y_subtract;
reg z_subtract;
reg [15:0] one_shifted;
reg signed [15:0] x_minus_yshifted, x_plus_yshifted;
reg signed [15:0] y_minus_xshifted, y_plus_xshifted;
reg repeated;
wire start;
reg [3:0] k, l, shift_diff, shift_next, shift_q, shift_base;
reg shift_right_next, shift_right_q;
reg tooBig;
reg signed [15:0] ym, xp, normalized;
reg signed [31:0] postscale_product, postscale_result;
reg angle_shift;
reg angle_shift_q;
reg [1:0] opcode;
reg format;

assign start = fu.req_valid && !(fu.req_opcode == 2'b01 && fu.req_op1[15] == 1'b1);

always @(posedge clk) begin
    if (!rst_n) begin
        current_state <= IDLE;
        cycles_completed <= 4'b0;
        repeated <= 1'b0;
        j <= 5'b00001;
        shift_q <= 4'b0;
        shift_right_q <= 1'b0;
        opcode <= 2'b00;
        x <= 16'sd0;
        y <= 16'sd0;
        z <= 16'sd0;
        angle_shift_q <= 1'b0;
    end else begin
        current_state <= next_state;
        
        x <= x_next;
        y <= y_next;
        z <= z_next;
        shift_q <= shift_next;
        shift_right_q <= shift_right_next;

        if (current_state == NORMALIZE && opcode == 2'b10)
            angle_shift_q <= angle_shift;

        if (current_state == IDLE && start) begin
            opcode <= fu.req_opcode[1:0];
            format <= fu.req_fmt;
            cycles_completed <= 4'b0;
            repeated <= 1'b0;
            j <= 4'b0001;
            shift_q <= 4'b0;
            shift_right_q <= 1'b0;
            angle_shift_q <= 1'b0;
        end else if (current_state == LOOP) begin
            cycles_completed <= cycles_completed + 1;
            if ((~j[1] & j[2] & ~(j[3]^j[0])) 
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
            if (opcode == 2'b01) begin
                if (j == ITER)
                    next_state = REVERT;
                else
                    next_state = LOOP;
            end else begin
                if (cycles_completed == ITER - 1)
                    next_state = REVERT;
                else
                    next_state = LOOP;
end
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
    iteration = 5'd0;
    negative_x = -x;
    negative_y = -y;
    x_subtract = 1'b0;
    y_subtract = 1'b0;
    z_subtract = 1'b0;
    shift_next = shift_q;
    shift_right_next = shift_right_q;
    k = 4'b0;
    l = 4'b0;
    shift_diff = 4'b0;
    shift_base = 4'b0;
    tooBig = 1'b0;
    ym = 16'b0;
    xp = 16'b0;
    angle_shift = 1'b0;
    normalized = x;
    one_shifted = 16'b0;
    x_shifted = 16'b0;
    y_shifted = 16'b0;
    shift_by = 4'b0;
    x_minus_yshifted = 16'b0;
    x_plus_yshifted = 16'b0;
    y_minus_xshifted = 16'b0;
    y_plus_xshifted = 16'b0;
    postscale_product = 32'b0;
    postscale_result = 32'b0;
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
                x_next = fu.req_op1;
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
            if (~opcode[1]) begin
                xp = x[15] ? negative_x : x;
                for (int i = 0; i < 15; i++) begin
                    if (xp[i])
                        k = i;
                end
            end
            if (opcode == 2'b00) begin
                x_next = xp;
                if (x[15]) begin
                    y_next = negative_y;
                end
                ym = y[15] ? negative_y : y;
                for (int i = 0; i < 15; i++) begin
                    if (ym[i])
                        l = i;
                end
                if (l >= k) begin
                    shift_diff = l - k;
                    shift_next = shift_diff + 1'b1;
                    if (l == 4'd14) begin
                        normalized = ym >>> 1;
                        y_next = y_next[15] ? -normalized : normalized;
                    end
                    x_next = xp <<< ((l == 4'd14) ? shift_diff : shift_next);
                end
            end else if (opcode == 2'b10) begin
                angle_shift = (z > 16'sh6F92 || z < 16'sh906E);
                if (angle_shift) 
                    z_next = z + (z[15] ? 17'h0C910 : 17'h136F0);
            end else if (opcode == 2'b11) begin
                x_next = x[15] ? negative_x : x;
                y_next = y[15] ? negative_y : y;
            end else if (opcode == 2'b01) begin
                tooBig = |x[14:8];
                normalized = x;
                shift_base = k[0] ? 4'd7 : 4'd6;
                if (((tooBig | ~(x[6] | x[7])) & ~format)
                    | (~(x[13] | x[14]) & format)) begin // under 0.5 or over 2
                    shift_next = (format ? (k[0] ? 4'd13 : 4'd14) : (tooBig ? k : shift_base))
                               - ((format | ~tooBig) ? k : shift_base);
                    shift_right_next = ~format & tooBig;
                    normalized = shift_right_next ? (x >>> shift_next) : (x <<< shift_next);
                end
                x_next = normalized + (format ? 16'h1000 : 16'h0020);
                y_next = normalized - (format ? 16'h1000 : 16'h0020);
                end
            end
        LOOP:
        begin
            iteration = (opcode == 2'b01) ? j : {1'b0, cycles_completed};
            one_shifted = (16'h4000 >>> iteration);
            x_shifted = (x >>> iteration);
            y_shifted = (((opcode == 2'b01 && y[15]) ? negative_y : y) >>> iteration);
            y_subtract = (opcode == 2'b10) ? z[15] : ~y[15];
            x_subtract = (opcode == 2'b01) ? 1'b1 : (opcode[0] ? y[15] : ~z[15]);
            z_subtract = (opcode == 2'b10) ? ~z[15] : y[15];
            x_next = (opcode == 2'b00)? x : (x + (y_shifted ^ {16{x_subtract}}) + x_subtract);
            y_next = y + (x_shifted ^ {16{y_subtract}}) + y_subtract;
            z_next = z + z_subtract + ((opcode[1] ? ATAN_LUT[{iteration, 4'b0} +: 16] : one_shifted) ^ {16{z_subtract}})  ;
        end
        REVERT:
        begin
            if (opcode ==  2'b00) begin
                if (|((z ^ {16{z[15]}}) & (16'hFFFF <<< (~shift_q))))
                    z_next = z[15] ? 16'h8000 : 16'h7FFF;
                else
                    z_next = z <<< shift_q;
            end else if (opcode == 2'b10) begin
                x_next = angle_shift_q ? negative_x : x;
            end else if (opcode == 2'b01) begin
                x_next = shift_right_q? (x <<< ((shift_q) >>> 1)) : (x >>> ((shift_q) >>> 1));
            end
        end
        POSTSCALE:
        begin
            // Magnitude gain correction: 0.60725 ~= 9945 / 2^14. Square-root gain correction: 1.2075 ~= 19784 / 2^14.
            if (opcode[0] | opcode[1]) begin
                postscale_product =
                       (opcode[1] ? ({{16{x[15]}}, x} <<< 13) : ({16'b0, x} <<< 14))
                    +  (opcode[1] ? ({{16{x[15]}}, x} <<< 11) : ({16'b0, x} <<< 12))
                    -  (opcode[1] ? ({{16{x[15]}}, x} <<< 8) : ({16'b0, x} <<< 9))
                    -  (opcode[1] ? ({{16{x[15]}}, x} <<< 5) : ({16'b0, x} <<< 7))
                    -  (opcode[1] ? ({{16{x[15]}}, x} <<< 3) : ({16'b0, x} <<< 6))
                    +  (opcode[1] ? {{16{x[15]}}, x} : ({16'b0, x} <<< 3));
                postscale_result = postscale_product >>> 14;
                if (postscale_result > 32'sd32767)
                    x_next = 16'h7FFF;
                else if (postscale_result < -32'sd32768)
                    x_next = 16'h8000;
                else
                    x_next = postscale_result[15:0];
                fu.resp_result = x_next;
            end else begin
                fu.resp_result = z;
            end 

            fu.resp_done = 1'b1;
        end
        

    endcase
    
end

endmodule
