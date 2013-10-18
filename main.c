
void spin(int cycles){
	while (cycles > 0){
		cycles--;
	}
	return;
}

int main(void){
	SetGpioFunction(16, 1);
	while(1){
		SetGpio(16, 0);
		spin(0x3F0000);
		SetGpio(16, 1);
		spin(0x3F0000);
	}
}
