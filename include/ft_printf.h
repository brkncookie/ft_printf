#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdarg.h>

typedef struct s_fsinfo
{
	char		**fptr;
	long	int	*flen;
	long	int	cnt;
}	fsinfo;

int	ft_islegal(char c);
fsinfo *ft_fsinfoinfo(char *fmt);
int ft_printf(char *fmt, ...);
#endif

