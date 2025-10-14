/* src/boot.S */
.section .multiboot_header
.align 8
.long 0xe85250d6             /* magic number (Multiboot2) */
.long 0                      /* architecture = 0 (i386) */
.long header_end - header_start
.long -(0xe85250d6 + 0 + (header_end - header_start))  /* checksum */

header_start:

/* Optional: end tag (required by spec) */
.align 8
.short 0
.short 0
.long 8

header_end:

.section .text
.global _start
.type _start, @function
_start:
    cli                     /* Disable interrupts */
    mov $stack_top, %esp     /* Set stack pointer */
    //call kmain               /* Jump to C code */
.hang:
    hlt
    jmp .hang

.section .bss
.align 16
stack_bottom:
.skip 16384                  /* 16 KiB stack */
stack_top:

