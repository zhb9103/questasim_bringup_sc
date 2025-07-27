/*
    Created by Bill.Zhang
    in 2025;
*/



#include "hvl_sc_top.h"





void hvl_sc_top::thread1()
{
    svSetScope(svGetScopeFromName("hdl_top"));
    top_func();
    svSetScope(svGetScopeFromName("hdl_top.hdl_test"));
    test_func();
    wait(1,SC_NS);
}

void hvl_sc_top::thread2()
{
    wait(1,SC_NS);
}


