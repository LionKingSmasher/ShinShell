#include "crypt.h"

void Crypt_Char(char* input, int count, unsigned char eChar)
{
	__asm__ __volatile__("mov %0, %%esi" ::"r"(input));
	__asm__ __volatile__("mov %0, %%ecx"::"r"(count));
	__asm__ __volatile__("mov %0, %%al"::"r"(eChar));
	__asm__ __volatile__(
		"L1:;"
		"xor (%%esi)"
	);
}