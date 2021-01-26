#include <verilated.h>
#include <verilated_vcd_c.h>
#include "Vtop.h"

vluint64_t simTime;

double sc_time_stamp () { return simTime; }

int main (int argc, char** argv) {
    Verilated::commandArgs(argc, argv);

    Vtop dut;
    dut.eval();
    dut.eval();

    Verilated::traceEverOn(true);
    VerilatedVcdC tfp;
    dut.trace(&tfp, 99);
    tfp.open("data.vcd");

    while (simTime <= 100 && !Verilated::gotFinish()) {
        dut.clk = !dut.clk;
        dut.eval();
        tfp.dump(simTime);
        ++simTime;
    }

    tfp.close();
    return 0;
}
