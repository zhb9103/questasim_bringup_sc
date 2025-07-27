/*
    Created by Bill.Zhang
    in 2025;
*/



#define SC_INCLUDE_DYNAMIC_PROCESSES
#define SC_INCLUDE_FX
#include "systemc.h"
#include "dpiheader.h"
#include <string>
#include "svdpi.h"
#include "hvl_sc_top.h"


extern "C"
{
    void dpi_sc_main();
    int hdl_time_tick();
}


P_HVL_SC_TOP p_hvl_sc_top;

int sc_main(int argc, char* argv[]) {

    //instantiate user TB in this wrapper
    printf("hello systemc.\n");

    svSetScope(svGetScopeFromName("hdl_top"));
    top_func();
    svSetScope(svGetScopeFromName("hdl_top.hdl_test"));
    test_func();

    p_hvl_sc_top=new hvl_sc_top("hvl_sc_top");
    return 0;
}

void dpi_sc_main()
{
    sc_elab_and_sim(0,nullptr);
}

int hdl_time_tick()
{
    sc_start(1, SC_NS);
    return 0;
}
