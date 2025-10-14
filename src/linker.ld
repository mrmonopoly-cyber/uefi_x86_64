/* src/linker.ld */
ENTRY(_start)

SECTIONS {
  . = 1M;               /* Load at 1 MiB (GRUB default) */

  .text : ALIGN(4K) {
    *(.multiboot_header)
    *(.text*)
  }

  .rodata : ALIGN(4K) {
    *(.rodata*)
  }

  .data : ALIGN(4K) {
    *(.data*)
  }

  .bss : ALIGN(4K) {
    *(COMMON)
    *(.bss*)
  }
}

