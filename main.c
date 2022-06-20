#include "include/ft_printf.h"
#include <stdio.h>

int main(int argc, char **argv)
{
	argc--;
	ft_printf(argv[1], argv[2], atoi(argv[3]), argv[4], argv[5]);
	ft_printf("\n");
	printf(argv[1], argv[2], atoi(argv[3]), argv[4], argv[5]);

	return(0);
}

