#pragma once

#ifdef __i386__
#   pragma message("Compiling for 32-bit (PE32)")
#   define __SIZE_OF_POINTER 4
#elif __x86_64__
#   pragma message("Compiling for 64-bit (PE32+)")
#   define __SIZE_OF_POINTER 8
#else
#   error "Unknown architecture!"
#endif // __i386__
