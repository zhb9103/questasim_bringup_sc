/*
    Created by Bill.Zhang
    in 2025;
*/

`timescale 1ns/1ns

module hdl_top;


import "DPI-C" function void dpi_sc_main();
import "DPI-C" context task hdl_time_tick();



reg clk;
reg rst;


initial begin
  fork
    dpi_sc_main();
  join
end

initial begin
  clk='b0;
  forever begin
    #1 clk=~clk;
  end
end

always @(posedge clk or negedge rst) begin
  if(!rst) begin
    ;
  end
  else begin
    hdl_time_tick();
  end
end

initial
begin
  rst='b0;
  $display("#%d starting test.", $time);
  #10;
  rst='b1;
  #2000;
  $display("#%d end test.", $time);
  $finish;
end 
endmodule
