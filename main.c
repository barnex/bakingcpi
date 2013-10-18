
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

#define P 16
#define O (16 * P)

//void rect(int x, int y, int w, int h){
//	uint32_t pointer = (uint32_t)FrameBufferInfo.pointer;
//	int W = 1024;
//	int H = 768;
//	
//	for(int i=y*P; i < (y+h)*P; i++){
//		for(int j=x*P; j < (x+w)*P; j++){
//			*((uint32_t*)( (pointer + i*W + j)*4 )) = 0;
//		}
//	}
//}
//

int main(void){
	// sign of life:
	SetGpioFunction(16, 1);
	SetGpio(16, 0);

	int w = 1024;
	int h = 768;
	InitialiseFrameBuffer(w, h, 16);
	uint32_t pitch = FrameBufferInfo.pitch;
	
	uint8_t* pointer = (uint8_t*)FrameBufferInfo.pointer;
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
	int j = 0;
			pointer[(i*w+j)*2 + 0] = 0;
			//pointer[(i*w+j)*2 + 1] = 0;

	for (;;){}
}



