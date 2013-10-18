#ifndef _GPIO_H_
#define _GPIO_H_

#include <stdint.h>

void* GetGpioAddress(void);

void SetGpioFunction(uint32_t gpioRegister, uint32_t function);

void SetGpio(uint32_t gpioRegister, uint32_t value);

#endif
