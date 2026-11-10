`default_nettype wire

module cordic #(
    parameter int WLEN=tinytracer_pkg::WLEN,
    parameter int ITER=tinytracer_pkg::WLEN
) (
    input  logic        clk,
    input  logic        rst_n,
    input  logic        start,
    input  logic [1:0]  opcode,
    input  logic [WLEN-1:0] A_in,
    input  logic [WLEN-1:0] B_in,
    output logic [WLEN-1:0] ans,
    output logic        busy,

    // FU <-> CORDIC Interface
    fu_if.server        fu
);

localparam [15:0] ATAN_LUT [0:15] = '{
    16'h3244,  // i=0   atan(2^-0)  = 0.785398
    16'h1DAC,  // i=1   0.463648
    16'h0FAE,  // i=2   0.244979
    16'h07F5,  // i=3   0.124355
    16'h03FF,  // i=4   0.062419
    16'h0200,  // i=5   0.031240
    16'h0100,  // i=6   0.015624
    16'h0080,  // i=7   0.007812
    16'h0040,  // i=8   0.003906
    16'h0020,  // i=9   0.001953
    16'h0010,  // i=10  0.000977
    16'h0008,  // i=11  0.000488
    16'h0004,  // i=12  0.000244
    16'h0002,  // i=13  0.000122
    16'h0001,  // i=14  0.000061
    16'h0001   // i=15  0.0000305
};


localparam [15:0] ATANH_LUT [0:15] = '{
    16'h2328,
    16'h1059,
    16'h080B, 
    16'h0401,
    16'h0200,
    16'h0100,
    16'h0080,
    16'h0040,
    16'h0020,
    16'h0010,
    16'h0008,
    16'h0004,
    16'h0002, 
    16'h0001,
    16'h0001,
    16'h0001
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
reg [15:0] x, y, z;
reg [15:0] x_next, y_next, z_next;
reg repeated;
reg signed [5:0] k, k_next;        // normalization shift, held for REVERT
reg flip, flip_next;               // cosine angle folded by +-pi, held for REVERT
reg signed [31:0] scale_input;     // signed copy of x
reg signed [31:0] scale_result;    // wider scaling result

// ---------------------------------------------------------------------------
// NORMALIZE
// ---------------------------------------------------------------------------
// Leading-one detect: index of the highest set bit (0 when v == 0)
function automatic [3:0] msb_index(input [15:0] v);
    integer i;
    begin
        msb_index = 4'd0;
        for (i = 0; i < 16; i = i + 1)
            if (v[i]) msb_index = i[3:0];
    end
endfunction

wire [15:0] div_x  = B_in[15] ? -B_in : B_in;
wire [15:0] div_y  = B_in[15] ? -A_in : A_in;
wire [3:0]  div_px = msb_index(div_x);
wire [3:0]  div_py = msb_index(div_y[15] ? -div_y : div_y);
wire [4:0]  div_k  = (div_py >= div_px) ? (div_py - div_px + 5'd1) : 5'd0;

// Cosine: fold the angle into [-pi/2, pi/2] with +-pi, cos(B -+ pi) = -cos(B).
// pi doesn't fit signed Q2.14, but the 16-bit sum wraps to the right value.
localparam [15:0] PI      = 16'd51472;
localparam [15:0] HALF_PI = 16'd25736; 
wire cos_hi = $signed(B_in) >  $signed(HALF_PI);
wire cos_lo = $signed(B_in) < -$signed(HALF_PI);

// Square root: w' = w * 2^(-2k) in [0.5, 2), k = ceil((p - F) / 2)
wire [3:0]        sq_p = msb_index(A_in);
wire signed [5:0] sq_f = (fu.req_fmt == tinytracer_pkg::FMT_DIR) ? 6'sd14 : 6'sd7;
wire signed [5:0] sq_k = ($signed({2'b00, sq_p}) - sq_f + 6'sd1) >>> 1;
wire signed [5:0] sq_s = 6'sd14 - sq_f - (sq_k <<< 1);
wire [15:0]       sq_w = (sq_s >= 0) ? (A_in << sq_s) : (A_in >> -sq_s);



always @(posedge clk) begin
    if (!rst_n) begin
        current_state <= IDLE;
        cycles_completed <= 4'b0;
        repeated <= 1'b0;
        j <= 1;
    end else begin
        current_state <= next_state;
        
        x <= x_next;
        y <= y_next;
        z <= z_next;
        k <= k_next;
        flip <= flip_next;

        cycles_completed <= cycles_completed + 1;
        if (current_state == LOOP) begin
            if ((~cycles_completed[1] & cycles_completed[2] & ~(cycles_completed[3]^cycles_completed[0])) && fu.req_opcode == 2'b11 && !repeated)  begin// 4 or 13
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
    next_state = current_state;
    case(current_state)
        IDLE: if (start) next_state = INIT;
        INIT: next_state = NORMALIZE;
        NORMALIZE: next_state = LOOP;
        LOOP:
        begin
            if (cycles_completed == ITER-1) 
                next_state = REVERT;
            else
                next_state = LOOP;
        end
        REVERT: next_state = POSTSCALE;
        POSTSCALE: next_state = IDLE;
        default: next_state = IDLE;
    endcase
end    

always @(*) begin
    x_next = x;
    y_next = y;
    z_next = z;
    k_next = k;
    flip_next = flip;
    scale_input = {{16{x[15]}}, x}; // preserve sign
    scale_result = scale_input;     // default: no scaling
    case(current_state)
        IDLE: begin
            
        end
        INIT: begin
            
        end
        NORMALIZE: begin
            z_next = 16'h0000;
            k_next = 6'sd0;
            flip_next = 1'b0;
            case (opcode)
                tinytracer_pkg::CORDIC_DIV: begin
                    x_next = div_x;
                    y_next = $signed(div_y) >>> div_k;
                    k_next = {1'b0, div_k};
                end
                tinytracer_pkg::CORDIC_COS: begin
                    x_next = A_in;
                    y_next = 16'h0000;
                    z_next = cos_hi ? (B_in - PI) : cos_lo ? (B_in + PI) : B_in;
                    flip_next = cos_hi | cos_lo;
                end
                tinytracer_pkg::CORDIC_MAG: begin
                    x_next = A_in[15] ? -A_in : A_in;
                    y_next = B_in[15] ? -B_in : B_in;
                end
                tinytracer_pkg::CORDIC_SQRT: begin
                    x_next = sq_w + 16'h1000;   // w' + 0.25
                    y_next = sq_w - 16'h1000;   // w' - 0.25
                    k_next = sq_k;
                end
            endcase
        end
        LOOP: begin
            if (fu.req_opcode[1:0] == 2'b00) begin
                fu.req_ready = 0;
                if (y[15]== 1'b1) begin
                    y_next = y + (x >>> cycles_completed);
                    z_next = z - (16'h4000 >>> cycles_completed);
                end else begin
                    y_next = y - (x >>> cycles_completed);
                    z_next = z + (16'h4000 >>> cycles_completed);
                end
            end else if (fu.req_opcode[1:0] == 2'b01) begin
                if (z[15]== 1'b1) begin
                    x_next = x + (y >>> cycles_completed);
                    y_next = y - (x >>> cycles_completed);
                    z_next = z + ATAN_LUT[cycles_completed];
                end else begin
                    x_next = x - (y >>> cycles_completed);
                    y_next = y + (x >>> cycles_completed);
                    z_next = z - ATAN_LUT[cycles_completed];
                end
            end else if (fu.req_opcode[1:0] == 2'b10) begin
                if (y[15]== 1'b1) begin
                    x_next = x - (y >>> cycles_completed);
                    y_next = y + (x >>> cycles_completed);
                    z_next = z - ATAN_LUT[cycles_completed];
                end else begin
                    x_next = x + (y >>> cycles_completed);
                    y_next = y - (x >>> cycles_completed);
                    z_next = z + ATAN_LUT[cycles_completed];
                end
            end else if (fu.req_opcode[1:0] == 2'b11) begin
                if (y[15]== 1'b1) begin
                    x_next = x + (y >>> cycles_completed + 1);
                    y_next = y + (x >>> cycles_completed + 1);
                    z_next = z - ATANH_LUT[cycles_completed];
                end else begin
                    x_next = x - (y >>> j);
                    y_next = y - (x >>> j);
                    z_next = z + ATANH_LUT[j-1];
                end
            end
        end 
        REVERT: begin
            
        end
        POSTSCALE: begin
            // cosine / vector magnitude
            if (fu.req_opcode[1:0] == 2'b01 ||
                fu.req_opcode[1:0] == 2'b10) begin
                scale_result = (scale_input >>> 1)
                            + (scale_input >>> 3)
                            - (scale_input >>> 6)
                            - (scale_input >>> 9)
                            - (scale_input >>> 13);

            // square root
            end else if (fu.req_opcode[1:0] == 2'b11) begin
                scale_result = scale_input
                            + (scale_input >>> 2)
                            - (scale_input >>> 5)
                            - (scale_input >>> 7)
                            - (scale_input >>> 8)
                            + (scale_input >>> 11);
            end

            // saturate before storing in 16 bits
            if (scale_result > 32'sd32767) begin
                x_next = 16'h7FFF;
            end else if (scale_result < -32'sd32768) begin
                x_next = 16'h8000;
            end else begin
                x_next = scale_result[15:0];
            end
        end
    endcase
end

endmodule
