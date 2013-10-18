#include "bcm2835.h"

#define PIN 18

void spin(int cycles){
	while (cycles > 0){
		cycles--;
	}
	return;
}

int main(void){
    bcm2835_gpio_fsel(PIN, BCM2835_GPIO_FSEL_OUTP);

    while (1)
    {
        bcm2835_gpio_write(PIN, HIGH);
		spin(0x3F0000);
        bcm2835_gpio_write(PIN, LOW);
		spin(0x3F0000);
    }
    return 0;
}
