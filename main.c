
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


void start(void){
	// sign of life:
	SetGpioFunction(16, 1);
	SetGpio(16, 0);

	InitialiseFrameBuffer(1920, 1080, 16);
	if (FrameBufferInfo.pointer == 0){
		blink(100000);
	}

	Clear(0xFFFF);

#define A 32
#define X (1920/2 - 3*A)
#define Y (1080/2 - 3*A)

	Rect r1 = {0*A+X, 0*A+Y, 3*A+X, 3*A+Y};
	Fill(r1, 0x0000);
	Rect r2 = {1*A+X, 1*A+Y, 2*A+X, 2*A+Y};
	Fill(r2, 0xFFFF);
	Rect r3 = {0*A+X, 3*A+Y, 1*A+X, 5*A+Y};
	Fill(r3, 0x0000);
	Rect r4 = {4*A+X, 0*A+Y, 5*A+X, 5*A+Y};
	Fill(r4, 0x0000);

	SetGpio(16, 1); // done
	for (;;){}
}



