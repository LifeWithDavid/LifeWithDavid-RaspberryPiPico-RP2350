To compile for rp2040:
cmake -G "NMake Makefiles" ..
nmake

To compile for rp2350-arm:
cmake -DPICO_BOARD=pico2 -DPICO_PLATFORM=rp2350-arm-s -G "NMake Makefiles" ..
nmake

To compile for rp2350-riscv:
cmake -DPICO_PLATFORM=rp2350-riscv -DPICO_TOOLCHAIN_PATH=F:\Users\tools\bin -G “NMake Makefiles” ..
nmake