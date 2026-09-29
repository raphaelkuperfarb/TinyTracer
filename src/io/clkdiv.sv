`default_nettype wire

module clkdiv (
    input  logic       clk,
    input  logic       rst_n,

    input  logic [7:0] b,
    input  logic [7:0] c,
    output logic       q
);

reg [7:0] sr;
wire [7:0]d;

always @(posedge clk) begin
    if (!rst_n) begin
        d <= ~sr ; 
        q <= 0;
    end else if (sr[7]) begin
        e <= b;
        q <= ~q;
    end else d <= ~c + 1'b1;
    sr <= sr + d;
end


endmodule
