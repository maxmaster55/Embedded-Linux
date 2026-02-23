.section .text.boot
.global _start

_start:
    // Disable interrupts
    msr daifset, 0xF


    // Call main
    bl main

hang:
    wfe
    b hang
