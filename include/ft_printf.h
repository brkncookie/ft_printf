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

int	ft_isfs(char c);
char	*ft_itoa(int n);
char	*ft_utoa(unsigned int n);
int 	ft_printf(char *fmt, ...);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s);
char	*ft_strchr(const char *s, int c);
void	ft_frall(char *rstr, char **rfs, fsinfo *fss);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
void	*ft_memcpy(void *restrict dest, const void *restrict src, size_t n);

char	*ft_str(char *fptr, long int flen, va_list *ap);
char	*ft_cha(char *fptr, long int flen, va_list *ap);
char	*ft_ptr(char *fptr, long int flen, va_list *ap);
char	*ft_int(char *fptr, long int flen, va_list *ap);
char	*ft_hex(char *fptr, long int flen, va_list *ap);
char	*ft_HEX(char *fptr, long int flen, va_list *ap);
char	*ft_uns(char *fptr, long int flen, va_list *ap);
#endif

