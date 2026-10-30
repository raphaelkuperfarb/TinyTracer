`default_nettype wire

// Standalone Tiny Tapeout wrapper for exercising the CORDIC functional unit.
// Pin protocol:
//   ui_in[7:6]  opcode: 00 DIV, 01 SQRT, 10 COS, 11 MAG
//   ui_in[5]    format
//   ui_in[4]    write uio_in as an operand byte
//   ui_in[3:2]  byte select: 00 A low, 01 A high, 10 B low, 11 B high
//   ui_in[1]    one-cycle start pulse
//   ui_in[0]    clear result-valid, returning uio to input mode
//   uio_in      operand byte during writes
//   uo_out      result low byte
//   uio_out     result high byte; uio_oe becomes 8'hFF when result is ready
// Keep opcode/format selected through the one-cycle start pulse.
module tt_um_cordic (
    input  wire [7:0] ui_in,
    output wire [7:0] uo_out,
    input  wire [7:0] uio_in,
    output wire [7:0] uio_out,
    output wire [7:0] uio_oe,
    input  wire       ena,
    input  wire       clk,
    input  wire       rst_n
);
    fu_if fu();

    logic [15:0] op1_q, op2_q;
    logic [15:0] result_q;
    logic result_valid;
    logic fmt_q;

    assign fu.req_valid = ui_in[1] && !result_valid;
    assign fu.req_opcode = {1'b0, ui_in[7:6]};
    assign fu.req_op1 = op1_q;
    assign fu.req_op2 = op2_q;
    assign fu.req_fmt = tinytracer_pkg::fmt_t'(ui_in[1] ? ui_in[5] : fmt_q);

    cordic u_cordic (
        .clk   (clk),
        .rst_n (rst_n),
        .fu    (fu)
    );

    always @(posedge clk) begin
        if (!rst_n) begin
            op1_q <= 16'b0;
            op2_q <= 16'b0;
            result_q <= 16'b0;
            result_valid <= 1'b0;
            fmt_q <= 1'b0;
        end else begin
            if (ui_in[4]) begin
                case (ui_in[3:2])
                    2'b00: op1_q[7:0]  <= uio_in;
                    2'b01: op1_q[15:8] <= uio_in;
                    2'b10: op2_q[7:0]  <= uio_in;
                    2'b11: op2_q[15:8] <= uio_in;
                endcase
            end

            if (ui_in[0])
                result_valid <= 1'b0;
            else if (fu.resp_done) begin
                result_q <= fu.resp_result;
                result_valid <= 1'b1;
            end

            if (ui_in[1] && fu.req_ready)
                fmt_q <= ui_in[5];
        end
    end

    assign uo_out = result_q[7:0];
    assign uio_out = result_q[15:8];
    assign uio_oe = result_valid ? 8'hFF : 8'h00;

    wire _unused = ena;
endmodule

`default_nettype wire
