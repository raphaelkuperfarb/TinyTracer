`default_nettype wire

module clkdiv (
    input  logic       clk,
    input  logic       rst_n,

    input  logic [7:0] b,
    input  logic [7:0] c,
    output logic       q
);

reg [7:0] sr;

always @(posedge clk) begin
    if (!rst_n) begin
        e <= ~sr ; 
        q <= 0;
    end else if (sr[7]) begin
        e <= c;
        q <= ~q;
    end else e <= ~d + 1'b1;
    sr <= sr + e
end


endmodule
