#include "include/ft_printf.h"
int	ft_isfs(char c)
{
	char	*f = "0123456789 0-#+.";
	char	*cs = "csdixXup%";

	while(*f)
		if(c == *f++)
			return(1);
	while(*cs)
		if(c == *cs++)
			return(2);
	return(0);
}

void	*ft_memcpy(void *restrict dest, const void *restrict src, size_t n)
{
	char	*d;
	const char	*s;

	d = (char *)dest;
	s = (const char *)src;
	if(!d && !s)
		return(NULL);
	while(n--)
		*(d++) = *(s++);
	return(dest);
}

char	*ft_strchr(const char *s, int c)
{
	while(*s)
	{
		if(*s == c)
			return (char *)s;
		s++;
	}
	if(*s == c)
		return (char *)s;
	return (NULL);
}

size_t	ft_strlen(const char *s)
{
	const char *ss = s;
	while(*s)
		s++;
	return((size_t)(s-ss));
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t len;

	len = ft_strlen(src);

	if(len + 1 < size)
		ft_memcpy(dst, src, len + 1);
	else if(size)
	{
		ft_memcpy(dst, src, size - 1);
		dst[size - 1] = 0;
	}
	return (len);
}

char	*ft_strdup(const char *s)
{
	char *d;

	d = malloc(ft_strlen(s) * sizeof(char) + 1);
	if(!d)
		return(NULL);
	ft_strlcpy(d, s, ft_strlen(s) + 1);
	return(d);
}

void	ft_frall(char *rstr, char **rfs, fsinfo *fss)
{
	long	int inx;

	inx = 0;
	while(inx < fss->cnt)
		free(rfs[inx++]);

	free(rfs);
	free(fss->fptr);
	free(fss->flen);
	free(fss);
	free(rstr);
}

