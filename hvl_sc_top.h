
#ifndef __HVL_SC_TOP_H__
#define __HVL_SC_TOP_H__


#define SC_INCLUDE_DYNAMIC_PROCESSES
#define SC_INCLUDE_FX
#include "systemc.h"
#include "dpiheader.h"
#include "svdpi.h"
#include <string>
#include <tlm.h>


extern "C" 
{
    int hdl_time_tick();
}


//SC_MODULE(hvl_sc_top)
// replace with below:
typedef class hvl_sc_top: public sc_module
{
    void thread1();
    void thread2();

public:
    //SC_CTOR(hvl_sc_top) 
    // replace with below:
    SC_HAS_PROCESS(hvl_sc_top);
    hvl_sc_top(sc_module_name module_name):sc_module(module_name)
    {
        SC_THREAD(thread1);
        SC_THREAD(thread2);
    }
    
    ~hvl_sc_top() {};

} *P_HVL_SC_TOP;

extern P_HVL_SC_TOP p_hvl_sc_top;


#endif