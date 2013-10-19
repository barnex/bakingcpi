rm -f kernel.img
echo gcc
./gcc/bin/arm-none-eabi-gcc -c -I . *.c -o system.o -O3 -nostdlib -std=c99 &&

echo as
./gcc/bin/arm-none-eabi-as -I . *.s -o drivers.o &&

echo ld
./gcc/bin/arm-none-eabi-ld --no-undefined system.o drivers.o -Map kernel.map -o output.elf -T kernel.ld &&

echo objcopy
./gcc/bin/arm-none-eabi-objcopy output.elf -O binary kernel.img  &&

echo objdump
./gcc/bin/arm-none-eabi-objdump -d output.elf > kernel.list
