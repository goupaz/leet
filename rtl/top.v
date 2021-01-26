module top (
    input clk,
    output out
);

// a little 0-to-7 counter
reg [3:0] counter;
always @(posedge clk)
    counter <= counter + 1;
wire in = counter[3];

// falling edge detector
reg inPrev;
always @(posedge clk)
    inPrev <= in;
assign out = ~in & inPrev;

endmodule
