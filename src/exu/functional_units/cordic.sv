`default_nettype wire

module cordic #(
    parameter int ITER=tinytracer_pkg::WLEN
) (
    input  logic        clk,
    input  logic        rst_n,

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
reg [15:0] x, y, z;
reg [15:0] x_next, y_next, z_next;


always @(posedge clk) begin
    if (!rst_n) begin
        current_state <= IDLE;
        cycles_completed <= 0;
    end else begin
        current_state <= next_state;
        if (next_state == LOOP) begin
            if ((~cycles_completed[1] & cycles_completed[2] & ~(cycles_completed[3]^cycles_completed[0])) && opcode == 2'b11) // 4 or 13
                cycles_completed <= cycles_completed;
            else
                cycles_completed <= cycles_completed + 1;
            x <= x_next;
            y <= y_next;
            z <= z_next;
        end
    end
end

always @(*) begin 
    case(current_state)
        LOOP:
        begin
            if (cycles_completed == ITER-1) 
                next_state = REVERT;
            else
                next_state = LOOP;
        end
    endcase
end    

always @(*) begin
    case(current_state)
        LOOP:
            if (fu.req_opcode[1:0] == 2'b00) begin
                fu.req_ready = 0;
                x_next = x;
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
                    z_next = z + ARCTAN_LUT[cycles_completed];
                end else begin
                    x_next = x - (y >>> cycles_completed);
                    y_next = y + (x >>> cycles_completed);
                    z_next = z - ARCTAN_LUT[cycles_completed];
                end
            end else if (fu.req_opcode[1:0] == 2'b10) begin
                if (y[15]== 1'b1) begin
                    x_next = x - (y >>> cycles_completed);
                    y_next = y + (x >>> cycles_completed);
                    z_next = z - ARCTAN_LUT[cycles_completed];
                end else begin
                    x_next = x + (y >>> cycles_completed);
                    y_next = y - (x >>> cycles_completed);
                    z_next = z + ARCTAN_LUT[cycles_completed];
                end
            end else if (fu.req_opcode[1:0] = 2'b11) begin
                if (y[15]== 1'b1) begin
                    x_next = x + (y >>> cycles_completed);
                    y_next = y + (x >>> cycles_completed);
                    z_next = z - ARCTANH_LUT[cycles_completed];
                end else begin
                    x_next = x - (y >>> cycles_completed);
                    y_next = y - (x >>> cycles_completed);
                    z_next = z + ARCTANH_LUT[cycles_completed];
                end
            end

            
    endcase
    
end

endmodule
