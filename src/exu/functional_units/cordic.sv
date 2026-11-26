`default_nettype wire

module cordic #(
    parameter int ITER=tinytracer_pkg::WLEN
) (
    input  logic        clk,
    input  logic        rst_n,

    fu_if.server        fu
);

localparam int G = 4;
localparam int W = 16 + G;
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
localparam [W-1:0] SQRT_C_DIR = W'(16'h1000) << G;
localparam [W-1:0] SQRT_C_POS = W'(16'h0020) << G;

parameter   IDLE = 3'b000,
            INIT = 3'b001,
            NORMALIZE = 3'b011,
            LOOP = 3'b010,
            REVERT = 3'b110,
            POSTSCALE = 3'b100;

reg [2:0] current_state, next_state;
reg [4:0] j;
reg [4:0] iteration;
reg signed [W-1:0] x, y;
reg signed [W-1:0] x_next, y_next;
reg signed [15:0] z, z_next;
reg signed [W-1:0] negative_x, negative_y;
reg signed [W-1:0] x_shifted, y_shifted;
reg x_subtract, y_subtract;
reg z_subtract;
reg [15:0] one_shifted;
reg [15:0] z_sum;
reg repeated;
wire start;
reg [3:0] k, l, shift_diff, shift_next, shift_q, shift_base;
reg div_shift, sqrt_shift;
reg [3:0] sqrt_amt;
reg shift_right_next, shift_right_q;
reg tooBig;
reg signed [W-1:0] ym, xp, normalized;
reg [W-1:0] sh_in, sh_pre, sh_out;
reg [W:0] sh_r;
reg [4:0] sh_amt;
reg sh_left;
reg signed [W:0] postscale_x;
reg signed [W+14:0] postscale_39x, postscale_product;
reg [15:0] postscale_result;
reg angle_shift;
reg angle_shift_q;
reg [1:0] opcode;
reg format;

assign start = fu.req_valid && !(fu.req_opcode == 2'b01 && fu.req_op1[15] == 1'b1);

always @(posedge clk or negedge rst_n) begin
    if (!rst_n) begin
        current_state <= IDLE;
        x <= '0;
        y <= '0;
        z <= '0;
        shift_q <= 4'b0;
        shift_right_q <= 1'b0;
        angle_shift_q <= 1'b0;
        opcode <= 2'b0;
        format <= 1'b0;
        repeated <= 1'b0;
        j <= 5'b0;
    end else begin
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
            j <= {4'b0, fu.req_opcode[1:0] == 2'b01};
        end else if (current_state == LOOP) begin
            if ((~j[1] & j[2] & ~(j[3]^j[0]))
                && opcode == 2'b01 && !repeated)  begin
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
    // Saturating negation: -(-2.0) has no two's-complement value, so it gives the largest positive.
    negative_x = (x == {1'b1, {(W-1){1'b0}}}) ? {1'b0, {(W-1){1'b1}}} : -x;
    negative_y = (y == {1'b1, {(W-1){1'b0}}}) ? {1'b0, {(W-1){1'b1}}} : -y;
    x_subtract = 1'b0;
    y_subtract = 1'b0;
    z_subtract = 1'b0;
    shift_next = shift_q;
    shift_right_next = shift_right_q;
    k = 4'b0;
    l = 4'b0;
    angle_shift = 1'b0;
    normalized = x;
    x_shifted = '0;
    y_shifted = '0;
    postscale_x = '0;
    postscale_39x = '0;
    postscale_product = '0;
    postscale_result = 16'b0;

    iteration = j;

    xp = x[W-1] ? negative_x : x;
    ym = y[W-1] ? negative_y : y;
    for (int i = 0; i < 15; i++) begin
        if (xp[G+i])
            k = i;
        if (ym[G+i])
            l = i;
    end
    shift_diff = l - k;
    tooBig = format ? x[G+14] : |x[G+14:G+8];
    shift_base = (format ? 4'd12 : 4'd6) | k[0];
    div_shift = (l >= k);
    sqrt_shift = tooBig | ~(format ? (x[G+12] | x[G+13]) : (x[G+6] | x[G+7]));
    sqrt_amt = tooBig ? k - shift_base : shift_base - k;

    sh_in = x;
    sh_amt = iteration;
    sh_left = 1'b0;
    if (current_state == NORMALIZE) begin
        if (opcode == 2'b00) begin
            sh_in = xp;
            sh_amt = 5'd0;
            sh_left = 1'b1;
            if (div_shift)
                sh_amt = {1'b0, (l == 4'd14) ? shift_diff : shift_diff + 1'b1};
        end else begin
            sh_amt = sqrt_shift ? {1'b0, sqrt_amt} : 5'd0;
            sh_left = ~tooBig;
        end
    end else if (current_state == REVERT) begin
        if (opcode == 2'b00) begin
            sh_in = {z, {G{1'b0}}};
            sh_amt = {1'b0, shift_q};
            sh_left = 1'b1;
        end else begin
            sh_amt = {2'b0, shift_q[3:1]};
            sh_left = shift_right_q;
        end
    end
    for (int i = 0; i < W; i++)
        sh_pre[i] = sh_left ? sh_in[W-1-i] : sh_in[i];
    sh_r = $signed({~sh_left & sh_in[W-1], sh_pre}) >>> sh_amt;
    for (int i = 0; i < W; i++)
        sh_out[i] = sh_left ? sh_r[W-1-i] : sh_r[i];

    one_shifted = (16'h4000 >>> iteration);
    if (current_state == LOOP)
        z_subtract = (opcode == 2'b10) ? ~z[15] : y[W-1];
    z_sum = z + z_subtract + (((current_state == LOOP) ? (opcode[1] ? ATAN_LUT[{iteration[3:0], 4'b0} +: 16] : one_shifted)
                                                       : (z[15] ? 16'hC910 : 16'h36F0)) ^ {16{z_subtract}});

    case(current_state)
        IDLE:
            fu.req_ready = 1'b1;
        INIT:
        begin
            if (opcode == 2'b00) begin
                x_next = {fu.req_op2, {G{1'b0}}};
                y_next = {fu.req_op1, {G{1'b0}}};
                z_next = '0;
            end else if (opcode == 2'b10) begin
                x_next = {fu.req_op1, {G{1'b0}}};
                y_next = '0;
                z_next = fu.req_op2;
            end else if (opcode == 2'b11) begin
                x_next = {fu.req_op1, {G{1'b0}}};
                y_next = {fu.req_op2, {G{1'b0}}};
                z_next = '0;
            end else begin
                x_next = {fu.req_op1, {G{1'b0}}};
                y_next = {fu.req_op1, {G{1'b0}}};
                z_next = '0;
            end
        end
        NORMALIZE:
        begin
            shift_next = 4'b0;
            shift_right_next = 1'b0;
            if (opcode == 2'b00) begin
                x_next = sh_out;
                if (x[W-1]) begin
                    y_next = negative_y;
                end
                if (div_shift) begin
                    shift_next = shift_diff + 1'b1;
                    if (l == 4'd14) begin
                        normalized = y_next >>> 1;
                        y_next = normalized;
                    end
                end
            end else if (opcode == 2'b10) begin
                angle_shift = (z > 16'sh6F92 || z < 16'sh906E);
                if (angle_shift)
                    z_next = z_sum;
            end else if (opcode == 2'b11) begin
                // Quarter the inputs: the CORDIC gain (1.647) would push x past 2.0
                // for magnitudes above 1.214. POSTSCALE multiplies the result back by 4.
                x_next = $unsigned(xp) >> 2;  // unsigned: |-2.0| = 0x80000 reads as +2.0
                y_next = $unsigned(ym) >> 2;
            end else if (opcode == 2'b01) begin
                if (sqrt_shift) begin
                    shift_next = sqrt_amt;
                    shift_right_next = tooBig;
                end
                normalized = sh_out;
                x_next = normalized + (format ? SQRT_C_DIR : SQRT_C_POS);
                y_next = normalized - (format ? SQRT_C_DIR : SQRT_C_POS);
            end
        end
        LOOP:
        begin
            x_shifted = sh_out;
            y_shifted = ((opcode == 2'b01) ? ym : y) >>> iteration;
            y_subtract = (opcode == 2'b10) ? z[15] : ~y[W-1];
            x_subtract = (opcode == 2'b01) ? 1'b1 : (opcode[0] ? y[W-1] : ~z[15]);
            x_next = (opcode == 2'b00)? x : (x + (y_shifted ^ {W{x_subtract}}) + x_subtract);
            y_next = y + (x_shifted ^ {W{y_subtract}}) + y_subtract;
            z_next = z_sum;
        end
        REVERT:
        begin
            if (opcode ==  2'b00) begin
                if (|((z ^ {16{z[15]}}) & (16'hFFFF << (4'd15 - shift_q))))
                    z_next = z[15] ? 16'h8000 : 16'h7FFF;
                else
                    z_next = sh_out[W-1:G];
            end else if (opcode == 2'b10) begin
                x_next = angle_shift_q ? negative_x : x;
            end else if (opcode == 2'b01) begin
                x_next = sh_out;
            end
        end
        POSTSCALE:
        begin
            if (opcode[0] | opcode[1]) begin
                postscale_x = {opcode[1] & x[W-1], x};
                postscale_39x = (postscale_x <<< 5) + (postscale_x <<< 3) - postscale_x;
                postscale_product = (opcode[1] ? (postscale_39x <<< 8) : (postscale_39x <<< 9))
                                  - (opcode[1] ? postscale_39x : (postscale_39x <<< 3))
                                  + (opcode[1] ? (postscale_x <<< 2) : (postscale_x <<< 7));
                if (opcode == 2'b11) begin
                    // mag: result x 4 (inputs were quartered), never negative
                    if ((|postscale_product[W+14:W+11]) | (&postscale_product[W+10:W-5]))
                        postscale_result = 16'h7FFF;
                    else
                        postscale_result = postscale_product[W+11:W-4] + postscale_product[W-5];
                end else if ((~opcode[1] & (postscale_product[W+14] | postscale_product[W+13]))
                    | (~postscale_product[W+13] & (&postscale_product[W+12:W-3])))
                    postscale_result = 16'h7FFF;
                else
                    postscale_result = postscale_product[W+13:W-2] + postscale_product[W-3];
                fu.resp_result = postscale_result;
            end else begin
                fu.resp_result = z;
            end

            fu.resp_done = 1'b1;
        end

    endcase

end

endmodule
