


module hdl_test();

export "DPI-C" function test_func;


function void test_func();
  $display("#%d test_func.", $time);
endfunction


endmodule

