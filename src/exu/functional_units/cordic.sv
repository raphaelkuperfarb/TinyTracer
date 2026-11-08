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
reg [4:0] j;
reg [3:0] iteration;
reg signed [15:0] x, y, z;
reg signed [15:0] x_next, y_next, z_next;
reg signed [15:0] negative_x, negative_y;
reg signed [15:0] x_shifted, y_shifted;
reg x_subtract, y_subtract;
reg z_subtract;
reg [15:0] one_shifted;
reg repeated;
wire start;
reg [3:0] k, l, shift_diff, shift_next, shift_q, shift_base;
reg [3:0] div_amt, sqrt_amt;
reg div_shift, sqrt_shift;
reg shift_right_next, shift_right_q;
reg tooBig;
reg signed [15:0] ym, xp, normalized;
reg [15:0] sh_in, sh_pre, sh_out;
reg [16:0] sh_r;
reg [3:0] sh_amt;
reg sh_left;
reg signed [16:0] postscale_x;
reg signed [30:0] postscale_39x, postscale_product;
reg [15:0] postscale_result;
reg angle_shift;
reg angle_shift_q;
reg [1:0] opcode;
reg format;

assign start = fu.req_valid && !(fu.req_opcode == 2'b01 && fu.req_op1[15] == 1'b1);

// Only the FSM is reset: every datapath register is loaded before it is read.
always @(posedge clk) begin
    if (!rst_n)
        current_state <= IDLE;
    else
        current_state <= next_state;

    x <= x_next;
    y <= y_next;
    z <= z_next;
    shift_q <= shift_next;
    shift_right_q <= shift_right_next;

    if (current_state == NORMALIZE)
        angle_shift_q <= angle_shift;

    if (current_state == IDLE && start) begin
        opcode <= fu.req_opcode[1:0];
        format <= fu.req_fmt;
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
                if (j == ITER - 1)
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
    negative_x = -x;
    negative_y = -y;
    x_subtract = 1'b0;
    y_subtract = 1'b0;
    z_subtract = 1'b0;
    shift_next = shift_q;
    shift_right_next = shift_right_q;
    k = 4'b0;
    l = 4'b0;
    angle_shift = 1'b0;
    normalized = x;
    one_shifted = 16'b0;
    x_shifted = 16'b0;
    y_shifted = 16'b0;
    postscale_x = 17'b0;
    postscale_39x = 31'b0;
    postscale_product = 31'b0;
    postscale_result = 16'b0;

    // Shifting a 16-bit value right by 16 gives the same result as by 15,
    // so the i = 16 step of sqrt can use a 4-bit shift amount.
    iteration = j[3:0] | {4{j[4]}};

    // Normalization decode, used by NORMALIZE and by the shifter below.
    xp = x[15] ? negative_x : x;
    ym = y[15] ? negative_y : y;
    for (int i = 0; i < 15; i++) begin
        if (xp[i])
            k = i;
        if (ym[i])
            l = i;
    end
    div_shift = (l >= k);
    shift_diff = l - k;
    div_amt = (l == 4'd14) ? shift_diff : shift_diff + 1'b1;
    tooBig = |x[14:8];
    shift_base = k[0] ? 4'd7 : 4'd6;
    sqrt_shift = ((tooBig | ~(x[6] | x[7])) & ~format)
               | (~(x[13] | x[14]) & format); // under 0.5 or over 2
    sqrt_amt = (format ? (k[0] ? 4'd13 : 4'd14) : (tooBig ? k : shift_base))
             - ((format | ~tooBig) ? k : shift_base);

    // One barrel shifter, shared by every state that shifts x or z by a
    // variable amount. sh_out = sh_left ? (sh_in << sh_amt) : (sh_in >>> sh_amt);
    // a left shift is a right shift of the bit-reversed value.
    sh_in = x;
    sh_amt = iteration;
    sh_left = 1'b0;
    if (current_state == NORMALIZE) begin
        if (opcode == 2'b00) begin
            sh_in = xp;
            sh_amt = div_shift ? div_amt : 4'd0;
            sh_left = 1'b1;
        end else begin
            sh_amt = sqrt_shift ? sqrt_amt : 4'd0;
            sh_left = format | ~tooBig;
        end
    end else if (current_state == REVERT) begin
        if (opcode == 2'b00) begin
            sh_in = z;
            sh_amt = shift_q;
            sh_left = 1'b1;
        end else begin
            sh_amt = shift_q >> 1;
            sh_left = shift_right_q;
        end
    end
    for (int i = 0; i < 16; i++)
        sh_pre[i] = sh_left ? sh_in[15-i] : sh_in[i];
    sh_r = $signed({~sh_left & sh_in[15], sh_pre}) >>> sh_amt;
    for (int i = 0; i < 16; i++)
        sh_out[i] = sh_left ? sh_r[15-i] : sh_r[i];

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
            shift_next = 4'b0;
            shift_right_next = 1'b0;
            if (opcode == 2'b00) begin
                x_next = sh_out;
                if (x[15]) begin
                    y_next = negative_y;
                end
                if (div_shift) begin
                    shift_next = shift_diff + 1'b1;
                    if (l == 4'd14) begin
                        // y / 2 rounded toward zero, with the sign of y / x
                        normalized = (y_next >>> 1) + $signed({15'b0, y_next[15] & y_next[0]});
                        y_next = normalized;
                    end
                end
            end else if (opcode == 2'b10) begin
                angle_shift = (z > 16'sh6F92 || z < 16'sh906E);
                if (angle_shift)
                    z_next = z + (z[15] ? 17'h0C910 : 17'h136F0);
            end else if (opcode == 2'b11) begin
                x_next = xp;
                y_next = ym;
            end else if (opcode == 2'b01) begin
                if (sqrt_shift) begin
                    shift_next = sqrt_amt;
                    shift_right_next = ~format & tooBig;
                end
                normalized = sh_out;
                x_next = normalized + (format ? 16'h1000 : 16'h0020);
                y_next = normalized - (format ? 16'h1000 : 16'h0020);
            end
        end
        LOOP:
        begin
            one_shifted = (16'h4000 >>> iteration);
            x_shifted = sh_out;
            y_shifted = ((opcode == 2'b01) ? ym : y) >>> iteration;
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
                    z_next = sh_out;
            end else if (opcode == 2'b10) begin
                x_next = angle_shift_q ? negative_x : x;
            end else if (opcode == 2'b01) begin
                x_next = sh_out;
            end
        end
        POSTSCALE:
        begin
            // Magnitude gain correction: 0.60725 ~= 9945 / 2^14. Square-root gain correction: 1.2075 ~= 19784 / 2^14.
            // With t = 39x:  9945x = 255t = (t << 8) - t,  19784x = (t << 9) - (t << 3) + (x << 7).
            if (opcode[0] | opcode[1]) begin
                postscale_x = {opcode[1] & x[15], x}; // signed for cos/mag, unsigned for sqrt
                postscale_39x = (postscale_x <<< 5) + (postscale_x <<< 3) - postscale_x;
                postscale_product = (opcode[1] ? (postscale_39x <<< 8) : (postscale_39x <<< 9))
                                  - (opcode[1] ? postscale_39x : (postscale_39x <<< 3))
                                  + (opcode[1] ? 31'sd0 : (postscale_x <<< 7));
                // Cos/mag can't overflow (|x| * 9945 / 2^14 < 2^15). Sqrt is never
                // negative, so it only saturates high, when bit 29 or 30 is set.
                if (~opcode[1] & (postscale_product[30] | postscale_product[29]))
                    postscale_result = 16'h7FFF;
                else
                    postscale_result = postscale_product[29:14];
                fu.resp_result = postscale_result;
            end else begin
                fu.resp_result = z;
            end

            fu.resp_done = 1'b1;
        end


    endcase

end

endmodule
