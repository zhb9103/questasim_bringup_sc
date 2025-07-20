
# GPP = /opt/simulation/questasim/questasim/gcc-7.4.0-linux/bin/g++
# GPP = /opt/simulation/questasim/questasim/gcc-7.4.0-linux_x86_64/bin/g++
GPP = g++
all: clean comp sim

SYSTEMC_HOME=/opt/simulation/systemc-2.3.2

CXXFLAGS=-Wno-deprecated -DVCSYSTEMC=1 -fPIC -shared -Wall -g -I. -I$(SYSTEMC_HOME)/include 
#CXXFLAGS=-Wno-deprecated -DVCSYSTEMC=1 -fPIC -Wall -g -I. -I$(SYSTEMC_HOME)/include
LDFLAGS=-L$(SYSTEMC_HOME)/lib-linux64 -lsystemc -lpthread

comp:
	# create library
	#vdel -all
	vlib work
	#compile SystemVerilog source file
	vlog +acc -work work -dpiheader dpiheader.h -f filelist.fl
	# compile and link C source files
	$(GPP) $(CXXFLAGS) -I/opt/simulation/questasim/questasim/include  main.cpp hvl_sc_top.cpp -o libhvl_sc_top.so $(LDFLAGS)


sim:
	# start and run simulation
	# vsim -gblso "libhvl_sc_top.so" hdl_top -scstacksize '32 Mb' -do run.do -c
	vsim -gblso "libhvl_sc_top.so" hdl_top -do run.do -c
	# vsim hdl_top -ldflags "libhvl_sc_top.so" -ldflags "-Wl,-rpath,/opt/simulation/systemc-2.3.2/lib-linux64 -L/opt/simulation/systemc-2.3.2/lib-linux64 -lsystemc" -do run.do -c


clean:
	rm -rf *.ref work transcript .*.swp *.o *.out *.so *.vstf *.log || TRUE

