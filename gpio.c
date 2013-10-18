
// GetGpioAddress returns the base address of the GPIO region as a physical address
void* GetGpioAddress(){
	return (void*)(0x20200000);
}

//GetGpioAddress: 
//	gpioAddr .req r0
//	ldr gpioAddr,=0x20200000
//	mov pc,lr
//	.unreq gpioAddr

