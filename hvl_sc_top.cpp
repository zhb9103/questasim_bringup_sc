/*
    Created by Bill.Zhang
    in 2025;
*/



#include "hvl_sc_top.h"


int hdl_time_tick()
{
    sc_start(1, SC_NS);
    return 0;
}


void hvl_sc_top::thread1()
{
    for(int i=0;i<2;i++)
    {
        wait(1,SC_NS);
        printf("thread1.\n");
    }
}

void hvl_sc_top::thread2()
{
    for(int i=0;i<2;i++)
    {
        wait(1,SC_NS);
        printf("thread2.\n");
    }
}


