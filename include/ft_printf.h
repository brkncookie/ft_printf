#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include <stddef.h>

typedef struct s_fsinfo
{
	char		**fptr;
	long	int	cnt;
}	fsinfo;

int 	ft_printf(char *fmt, ...);
void	ft_frall(char *rstr, char **rfs, fsinfo *fss);

char	*ft_str(va_list *ap);
char	*ft_cha(va_list *ap);
char	*ft_ptr(va_list *ap);
char	*ft_int(va_list *ap);
char	*ft_hex(va_list *ap, int n);
char	*ft_uns(va_list *ap);
#endif

