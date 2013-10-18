
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

	int w = 1024;
	int h = 768;
	InitialiseFrameBuffer(w, h, 16);
	uint32_t pitch = FrameBufferInfo.pitch;
	
	volatile uint8_t* pointer = (volatile uint8_t*)FrameBufferInfo.pointer;
	if (pointer == 0){
		blink(1000);
	}

	for(int i=0; i < h; i++){
		for(int j=0; j < w; j++){
			pointer[(i*w+j)*2 + 0] = 255;
			pointer[(i*w+j)*2 + 1] = 255;
		}
	}

	
	int i = 0;
	int j = w-1;
			pointer[(i*w+j)*2 + 0] = 0;
			pointer[(i*w+j)*2 + 1] = 0;

	for (;;){}
}



