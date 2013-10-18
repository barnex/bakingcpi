/******************************************************************************
*	gpio.s
*	 by Alex Chadwick
*
*	A sample assembly code implementation of the ok03 operating system.
*	See main.s for details.
*
*	gpio.s contains the rountines for manipulation of the GPIO ports.
******************************************************************************/

/* NEW
* According to the EABI, all method calls should use r0-r3 for passing
* parameters, should preserve registers r4-r8,r10-r11,sp between calls, and 
* should return values in r0 (and r1 if needed). 
* It does also stipulate many things about how methods should use the registers
* and stack during calls, but we're using hand coded assembly. All we need to 
* do is obey the start and end conditions, and if all our methods do this, they
* would all work from C.
*/


/* NEW
* SetGpio sets the GPIO pin addressed by register r0 high if r1 != 0 and low
* otherwise. 
* C++ Signature: void SetGpio(u32 gpioRegister, u32 value)
*/
.globl SetGpio
SetGpio:	
    pinNum .req r0
    pinVal .req r1

	cmp pinNum,#53
	movhi pc,lr
	push {lr}
	mov r2,pinNum	
    .unreq pinNum	
    pinNum .req r2
	bl GetGpioAddress
    gpioAddr .req r0

	pinBank .req r3
	lsr pinBank,pinNum,#5
	lsl pinBank,#2
	add gpioAddr,pinBank
	.unreq pinBank

	and pinNum,#31
	setBit .req r3
	mov setBit,#1
	lsl setBit,pinNum
	.unreq pinNum

	teq pinVal,#0
	.unreq pinVal
	streq setBit,[gpioAddr,#40]
	strne setBit,[gpioAddr,#28]
	.unreq setBit
	.unreq gpioAddr
	pop {pc}
