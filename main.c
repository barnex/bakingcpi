
void spin(int cycles){
	while (cycles > 0){
		cycles--;
	}
	return;
}

int main(void){
	SetGpioFunction(16, 1);
	for(int i=0; i<10; i++){
		SetGpio(16, 0);
		spin(0x300000);
		SetGpio(16, 1);
		spin(0x300000);
	}
	return 0;
}
