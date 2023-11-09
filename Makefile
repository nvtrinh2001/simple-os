compile:
	i686-elf-g++ -c kernel.cpp -o kernel.o -ffreestanding -O2 -Wall -Wextra -fno-exceptions -fno-rtti

load:
	i686-elf-as loader.s -o loader.o

link:
	i686-elf-g++ -T linker.ld -o myos.bin -ffreestanding -O2 -nostdlib loader.o kernel.o -lgcc

clean: 
	rm *.o *.bin
