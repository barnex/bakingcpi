rm -f kernel.img
./gcc/bin/arm-none-eabi-gcc -I . *.c *.s -o kernel.o
./gcc/bin/arm-none-eabi-ld --no-undefined kernel.o -Map kernel.map -o output.elf -T kernel.ld
./gcc/bin/arm-none-eabi-objcopy output.elf -O binary kernel.img 
./gcc/bin/arm-none-eabi-objdump -d output.elf > kernel.list
