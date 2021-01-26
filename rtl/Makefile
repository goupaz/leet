CFLAGS = -Wno-undefined-bool-conversion

all:
	verilator -cc top.v --trace --exe branch.v ../main.cpp -CFLAGS "$(CFLAGS)" --top-module top
	make -C obj_dir -f Vtop.mk

clean:
	rm -rf obj_dir data.vcd
