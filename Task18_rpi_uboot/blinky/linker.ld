ENTRY(_start)

SECTIONS
{
    /* kernel addr */
    . = 0x80000;

    .text :
    {
        KEEP(*(.text.boot))
        *(.text*)
    }

    .rodata :
    {
        *(.rodata*)
    }

    .data :
    {
        *(.data*)
    }

    .bss :
    {
        __bss_start = .;
        *(.bss*)
        *(COMMON)
        __bss_end = .;
    }

    /* Stack (4KB) */
    . = ALIGN(8);
    stack_bottom = .;
    . += 0x1000;
    stack_top = .;
}
