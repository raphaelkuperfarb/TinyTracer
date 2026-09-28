`default_nettype none

module tt_um_clkdiv (
    input  wire [7:0] ui_in,
    output wire [7:0] uo_out,
    input  wire [7:0] uio_in,
    output wire [7:0] uio_out,
    output wire [7:0] uio_oe,
    input  wire       ena,
    input  wire       clk,
    input  wire       rst_n
);

    wire q;

    clkdiv divider (
        .clk  (clk),
        .rst_n(rst_n),
        .b    (ui_in),
        .c    (uio_in),
        .q    (q)
    );

    assign uo_out  = {7'b0, q};
    assign uio_out = 8'b0;
    assign uio_oe  = 8'b0;

    wire _unused = ena;

endmodule