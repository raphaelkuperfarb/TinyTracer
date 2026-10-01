`default_nettype wire

module clkdiv (
    input  logic       clk,
    input  logic       rst_n,

    input  logic [7:0] b,
    input  logic [7:0] c,
    output logic       q
);

reg [7:0] sr;
reg [7:0] d;

always @(*) begin
    if (sr[7]) begin
        d = b;
    end else begin
        d = -c;
    end
end

always @(posedge clk) begin
    if (!rst_n) begin
        sr <= 0;
        q <= 0;
    end else  begin
        sr <= sr + d;
        if (sr[7]) begin
            q <= ~q;
        end
    end
        

end


endmodule
