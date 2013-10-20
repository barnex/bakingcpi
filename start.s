
# This is the kernel starting point.
# Calls main(), then enters infinite loop.


.section .init
.globl _start
_start:

b __start$

.section .text
__start$:

# set-up stack
mov sp,#0x8000

# call C function void start()
bl start


# halt (infinite loop)
loop$:
b loop$

