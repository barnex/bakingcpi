
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

	
	for(int j=0; j < w; j++){
		for(int i=0; i < h; i++){
			pointer[(i*w+j)*2 + 0] = 0;
			pointer[(i*w+j)*2 + 1] = 0;

			for(int k=0; k < 5000; k++){}
		}
	}

	for (;;){}
}



