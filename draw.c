#include "kernel.h"

// clears the screen
void Clear(uint16_t color){
	uint32_t color2 = color << 16 | color;
	int pixels = FrameBufferInfo.width * FrameBufferInfo.height / 2;
	uint32_t* fb = (uint32_t*)FrameBufferInfo.pointer;
	for(int i=0; i < pixels; i+=8){
			fb[i+0] = color2;
			fb[i+1] = color2;
			fb[i+2] = color2;
			fb[i+3] = color2;
			fb[i+4] = color2;
			fb[i+5] = color2;
			fb[i+6] = color2;
			fb[i+7] = color2;
	}
}

void Fill(Rect r, uint16_t color){
	int w = FrameBufferInfo.width;
	int h = FrameBufferInfo.height;
	uint16_t* fb = FrameBufferInfo.pointer;

	for(int y = r.y0; y < r.y1; y++){
		for(int x = r.x0; x < r.x1; x++){
			fb[y*w+x] = color;
		}
	}
}
