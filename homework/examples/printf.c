#include <stdio.h>


int main(void)
{
	char	*str = "one two three";
	int	num = 512;

	printf("str is %s and char is %c\n", str, *str);
	printf("ptr is %p and hex/HEX are %x/%X\n", str, (unsigned int )*str, (unsigned int )*str);
	printf("digit is %d  and integer is %i and unsigned int is %u\n", num, num, num);

	printf("\tMin Field Width\n");
	printf("str is %14s and char is %2c\n", str, *str);
	printf("ptr is %16p and hex/HEX are %4x/%4X\n", str, (unsigned int )*str, (unsigned int )*str);
	printf("digit is %6d  and integer is %6i and unsigned int is %6u\n", num, num, num);

	printf("\tMin Field Width with 0 flag\n");
	printf("hex/HEX are %04x/%04X\n",  (unsigned int )*str, (unsigned int )*str);
	printf("digit is %06d  and integer is %06i and unsigned int is %06u\n", num, num, num);

	printf("\tMin Field Width with - flag\n");
	printf("str is %-14s and char is %-2c\n", str, *str);
	printf("ptr is %-16p and hex/HEX are %-4x/%-4X\n", str, (unsigned int )*str, (unsigned int )*str);
	printf("digit is %-6d  and integer is %-6i and unsigned int is %-6u\n", num, num, num);

	printf("\tPrecision\n");
	printf("str is %.7s\n", str);
	printf("hex/HEX are %.4x/%.4X\n", (unsigned int )*str, (unsigned int )*str);
	printf("digit is %.6d  and integer is %.6i and unsigned int is %.6u\n", num, num, num);

	printf("\tPrecision with # flag\n");
	printf("hex/HEX are %#.4x/%#.4X\n", (unsigned int )*str, (unsigned int )*str);

	printf("\tPrecision with ' ' flag\n");
	printf("digit is % .6d  and integer is % .6i \n", num, num);

	printf("\tPrecision with + flag\n");
	printf("digit is %+.6d  and integer is %+.6i \n", num, num);
	return(0);
}

