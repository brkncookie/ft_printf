#include "include/ft_printf.h"

int main(int argc, char **argv)
{
	/* fstr 	*fc; */
	/* int	inx; */

	/* fc = ft_fstrinfo(argv[1]); */
	/* if(fc->cnt == 0) */
	/* 	return(1); */
	/* printf("there are %d format strings in the string\n",  fc->cnt); */
	/* for(inx = 0; inx < fc->cnt; inx++) */
	/* 	printf("format string: '%.*s' length: %d\n", fc->flen[inx], fc->fptr[inx], fc->flen[inx]); */

	ft_printf(argv[1], argv[2], argv[3]);
	/* printf(argv[1], argv[2], argv[3]); */

	return(0);
}

