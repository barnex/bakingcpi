
# This is the kernel starting point.
# Calls main(), then enters infinite loop.


.section .init
.globl _start
_start:

# set-up stack
mov sp,#0x8000

# call main
bl main

# halt (infinite loop)
loop$:
b loop$

