# blinky (bare metal)

Embedded Linux course task for the ITI.

uses tftp to load a file named `rpi_app` and runs it


## Why choose the load address to be 0x00080000?

- because it is the default address in the varible `kernel_addr_r`.
- it is the same address defined in the linker script.

## Why do we need to start with an assembly file first?
- to setup to processor to run the application ie: 
    - stop the interrupts
    - init the bss (if needed)
    - init the stack pointer


to use this just run `make`