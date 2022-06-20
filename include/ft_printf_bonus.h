#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include <stddef.h>

typedef struct s_fsinfo
{
	char		**fptr;
	long	int	*flen;
	long	int	cnt;
}	fsinfo;

char	*ft_isfs(char *s);
char	*ft_p2hx(void *p);
char	*ft_utoa(unsigned int n);
char	*ft_i2hx(unsigned int n);
int 	ft_printf(char *fmt, ...);
void	ft_frall(char *rstr, char **rfs, fsinfo *fss);

char	*ft_str(char *fptr, long int flen, va_list *ap);
char	*ft_cha(char *fptr, long int flen, va_list *ap);
char	*ft_ptr(char *fptr, long int flen, va_list *ap);
char	*ft_int(char *fptr, long int flen, va_list *ap);
char	*ft_hex(char *fptr, long int flen, va_list *ap, int n);
char	*ft_uns(char *fptr, long int flen, va_list *ap);
#endif

