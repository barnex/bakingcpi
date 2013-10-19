
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

void Clear(uint16_t color){
	uint32_t color2 = color << 16 | color;
	int pixels = FrameBufferInfo.width * FrameBufferInfo.height / 2;
	volatile uint32_t* pointer = (volatile uint32_t*)FrameBufferInfo.pointer;
	for(int i=0; i < pixels; i+=8){
			pointer[i+0] = color2;
			pointer[i+1] = color2;
			pointer[i+2] = color2;
			pointer[i+3] = color2;
			pointer[i+4] = color2;
			pointer[i+5] = color2;
			pointer[i+6] = color2;
			pointer[i+7] = color2;
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



