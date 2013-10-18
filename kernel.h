#ifndef _KERNEL_H_
#define _KERNEL_H_

#include <stdint.h>

void* GetGpioAddress(void);

void SetGpioFunction(uint32_t gpioRegister, uint32_t function);

void SetGpio(uint32_t gpioRegister, uint32_t value);

typedef struct  {
	uint32_t width; 
	uint32_t height;
	uint32_t vWidth;
	uint32_t vHeight;
	uint32_t pitch;
	uint32_t bitDepth;
	uint32_t x;
	uint32_t y; 
	void* pointer; 
	uint32_t size;
}FrameBuferDescription;

extern FrameBuferDescription FrameBufferInfo;

void* InitialiseFrameBuffer(uint32_t width, uint32_t height, uint32_t bitDepth);


void SetGraphicsAddress(FrameBuferDescription* value);

void SetForeColour(uint16_t colour);

void DrawPixel(uint32_t x, uint32_t y);

void DrawLine(uint32_t x1, uint32_t y1, uint32_t x2, uint32_t y2);

#endif
