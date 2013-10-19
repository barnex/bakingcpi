#include "kernel.h"

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
