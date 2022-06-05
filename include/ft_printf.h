#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdarg.h>

typedef struct s_fstr
{
	char	**fptr;
	long	int	*flen;
	int	cnt;
}	fstr;

int	ft_islegal(char c);
fstr *ft_fstrinfo(char *fmt);
int ft_printf(char *fmt, ...);
#endif

