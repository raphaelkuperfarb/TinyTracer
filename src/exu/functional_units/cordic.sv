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
wire start = fu.req_valid;
reg [1:0] opcode;                  // opcode latched on start, held for the whole op
reg [4:0] j;                       // LOOP iteration counter
reg signed [15:0] x, y, z;
reg signed [15:0] x_next, y_next, z_next;
reg repeated;
// LOOP-only signals (from cordic-raph-tests, not shared with other states)
reg [3:0] iteration;
reg signed [15:0] ym;
reg signed [15:0] x_shifted, y_shifted;
reg x_subtract, y_subtract, z_subtract;
reg [15:0] one_shifted;
reg [15:0] z_sum;
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

wire [15:0] div_x  = fu.req_op2[15] ? -fu.req_op2 : fu.req_op2;
wire [15:0] div_y  = fu.req_op2[15] ? -fu.req_op1 : fu.req_op1;
wire [3:0]  div_px = msb_index(div_x);
wire [3:0]  div_py = msb_index(div_y[15] ? -div_y : div_y);
wire [4:0]  div_k  = (div_py >= div_px) ? (div_py - div_px + 5'd1) : 5'd0;

// Cosine: fold the angle into [-pi/2, pi/2] with +-pi, cos(B -+ pi) = -cos(B).
// pi doesn't fit signed Q2.14, but the 16-bit sum wraps to the right value.
localparam [15:0] PI      = 16'd51472;
localparam [15:0] HALF_PI = 16'd25736; 
wire cos_hi = $signed(fu.req_op2) >  $signed(HALF_PI);
wire cos_lo = $signed(fu.req_op2) < -$signed(HALF_PI);

// Square root: w' = w * 2^(-2k) in [0.5, 2), k = ceil((p - F) / 2)
wire [3:0]        sq_p = msb_index(fu.req_op1);
wire signed [5:0] sq_f = (fu.req_fmt == tinytracer_pkg::FMT_DIR) ? 6'sd14 : 6'sd7;
wire signed [5:0] sq_k = ($signed({2'b00, sq_p}) - sq_f + 6'sd1) >>> 1;
wire signed [5:0] sq_s = 6'sd14 - sq_f - (sq_k <<< 1);
wire [15:0]       sq_w = (sq_s >= 0) ? (fu.req_op1 << sq_s) : (fu.req_op1 >> -sq_s);


always @(posedge clk) begin
    if (!rst_n) begin
        current_state <= IDLE;
        opcode <= 2'b0;
        repeated <= 1'b0;
        j <= 5'b0;
    end else begin
        current_state <= next_state;

        x <= x_next;
        y <= y_next;
        z <= z_next;
        k <= k_next;
        flip <= flip_next;

        if (current_state == IDLE && start) begin
            opcode <= fu.req_opcode[1:0];
            repeated <= 1'b0;
            j <= {4'b0, fu.req_opcode[1:0] == 2'b01}; // sqrt starts at i = 1, the rest at i = 0
        end else if (current_state == LOOP) begin
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
    next_state = current_state;
    case(current_state)
        IDLE: if (start) next_state = INIT;
        INIT: next_state = NORMALIZE;
        NORMALIZE: next_state = LOOP;
        LOOP:
        begin
            if (opcode == 2'b01) begin
                if (j == ITER)
                    next_state = REVERT;
                else
                    next_state = LOOP;
            end else begin
                if (j == ITER - 1)
                    next_state = REVERT;
                else
                    next_state = LOOP;
            end
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
    iteration = 4'b0;
    ym = 16'b0;
    x_shifted = 16'b0;
    y_shifted = 16'b0;
    x_subtract = 1'b0;
    y_subtract = 1'b0;
    z_subtract = 1'b0;
    one_shifted = 16'b0;
    z_sum = 16'b0;
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
                    x_next = fu.req_op1;
                    y_next = 16'h0000;
                    z_next = cos_hi ? (fu.req_op2 - PI) : cos_lo ? (fu.req_op2 + PI) : fu.req_op2;
                    flip_next = cos_hi | cos_lo;
                end
                tinytracer_pkg::CORDIC_MAG: begin
                    x_next = fu.req_op1[15] ? -fu.req_op1 : fu.req_op1;
                    y_next = fu.req_op2[15] ? -fu.req_op2 : fu.req_op2;
                end
                tinytracer_pkg::CORDIC_SQRT: begin
                    x_next = sq_w + 16'h1000;   // w' + 0.25
                    y_next = sq_w - 16'h1000;   // w' - 0.25
                    k_next = sq_k;
                end
            endcase
        end
        LOOP: begin
            // Shifting a 16-bit value right by 16 gives the same result as by 15,
            // so the i = 16 step of sqrt can use a 4-bit shift amount.
            iteration = j[3:0] | {4{j[4]}};
            ym = y[15] ? -y : y;
            x_shifted = x >>> iteration;
            y_shifted = ((opcode == 2'b01) ? ym : y) >>> iteration;
            y_subtract = (opcode == 2'b10) ? z[15] : ~y[15];
            x_subtract = (opcode == 2'b01) ? 1'b1 : (opcode[0] ? y[15] : ~z[15]);
            x_next = (opcode == 2'b00)? x : (x + (y_shifted ^ {16{x_subtract}}) + x_subtract);
            y_next = y + (x_shifted ^ {16{y_subtract}}) + y_subtract;
            one_shifted = (16'h4000 >>> iteration);
            z_subtract = (opcode == 2'b10) ? ~z[15] : y[15];
            z_sum = z + z_subtract + ((opcode[1] ? ATAN_LUT[{iteration, 4'b0} +: 16] : one_shifted) ^ {16{z_subtract}});
            z_next = z_sum;
        end
        REVERT: begin
            
        end
        POSTSCALE: begin
            // cosine / vector magnitude
            if (opcode == tinytracer_pkg::CORDIC_COS ||
                opcode == tinytracer_pkg::CORDIC_MAG) begin
                scale_result = (scale_input >>> 1)
                            + (scale_input >>> 3)
                            - (scale_input >>> 6)
                            - (scale_input >>> 9)
                            - (scale_input >>> 13);

            // square root
            end else if (opcode == tinytracer_pkg::CORDIC_SQRT) begin
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
