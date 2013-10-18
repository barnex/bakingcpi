
#include "kernel.h"

void spin(int cycles){
	while (cycles > 0){
		cycles--;
	}
	return;
}

void blink(){
	while(1){
		spin(0x100000);
		SetGpio(16, 1);
		spin(0x100000);
		SetGpio(16, 0);
	}
}

int main(void){
	// sign of life:
	SetGpioFunction(16, 1);
	SetGpio(16, 0);

	InitialiseFrameBuffer(1024, 768, 16);
	
	uint16_t* pointer = (uint16_t*)FrameBufferInfo.pointer;

	//for (uint16_t c = 0; c < 0xFFFF; c++){
	uint16_t c = 0xFFFF;

	for(int i=0; i < 768; i++){
		for(int j=0; j < 1024; j++){
			pointer[i*1024 + j] = c;
		}
	}

	//}

	blink();

}


