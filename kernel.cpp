void printf(char* str)
{
	unsigned short* VideoMemory = (unsigned short*) 0xb8000; // this address allows displaying string to the screen with 4-bit higher is the color
	
	for (int i = 0; str[i] != '\0'; ++i) 
	{
		VideoMemory[i] = (VideoMemory[i] & 0xFF00) | str[i];
	}
}

extern "C" void kernel_main(void* multiboot_structure, unsigned int magic_number)
{
	printf("Hello, World!");

	while(1);
}

