
#include "kernel.h"

void spin(int cycles){
	while (cycles > 0){
		cycles--;
	}
	return;
}

void blink(int n){
	while(n != 0){
		spin(0x100000);
		SetGpio(16, 1);
		spin(0x100000);
		SetGpio(16, 0);
		n--;
	}
}


int main(void){
	// sign of life:
	SetGpioFunction(16, 1);
	SetGpio(16, 0);

	InitialiseFrameBuffer(1920, 1080, 16);
	uint32_t pitch = FrameBufferInfo.pitch;
	int w = FrameBufferInfo.width;
	int h = FrameBufferInfo.height;
	
	volatile uint16_t* pointer = (volatile uint16_t*)FrameBufferInfo.pointer;
	if (pointer == 0){
		blink(100000);
	}

	int led = 0;

	for(uint16_t c = 0; c <= 200; c++){
		Clear(0x0000);
	}

	for(uint16_t c = 0; c <= 1000; c++){
		Clear(0xFFFF);
	}

	Clear(0x0000);
	

	SetGpio(16, 1); // done
	for (;;){}
}



