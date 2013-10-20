./clean.bash

for c in *.c; do
	o=$(echo $c | sed 's/.c/.o/g')
	echo ./gcc/bin/arm-none-eabi-gcc -c $c -o $o -I . -O3 -nostdlib -std=c99
	./gcc/bin/arm-none-eabi-gcc -c $c -o $o -I . -O3 -nostdlib -std=c99 -Wall -Werror || exit 1
done

echo ./gcc/bin/arm-none-eabi-as -I . *.s -o drivers.o
./gcc/bin/arm-none-eabi-as -I . *.s -o drivers.o &&

echo ./gcc/bin/arm-none-eabi-ld --no-undefined *.o -Map kernel.map -o output.elf -T kernel.ld 
./gcc/bin/arm-none-eabi-ld --no-undefined *.o -Map kernel.map -o output.elf -T kernel.ld &&

echo ./gcc/bin/arm-none-eabi-objcopy output.elf -O binary kernel.img  &&
./gcc/bin/arm-none-eabi-objcopy output.elf -O binary kernel.img

echo ./gcc/bin/arm-none-eabi-objdump -d output.elf > kernel.list
./gcc/bin/arm-none-eabi-objdump -d output.elf > kernel.list &&

echo OK
