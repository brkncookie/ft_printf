#include "include/ft_printf.h"
/* int	ft_isfs(char c) */
/* { */
/* 	char	*f = "0123456789 0-#+."; */
/* 	char	*cs = "csdixXup%"; */

/* 	while(*f) */
/* 		if(c == *f++) */
/* 			return(1); */
/* 	while(*cs) */
/* 		if(c == *cs++) */
/* 			return(2); */
/* 	return(0); */
/* } */

char	*ft_isfs(char	*s)
{
	char	*f;
	char	*n;
	char	*c;
	char	*fi;
	char	*ni;
	char	*ci;

	f = " 0-+#";
	n = "0123456789";
	c = "csdixXup%";
	fi = f;
	ni = n;
	ci = c;

	while(*f && *s)
	{
		if(*s == *f)
		{
			s++;
			f = fi;
		}
		else
			f++;
	}

	while(*n && *s)
	{
		if(*s == *n)
		{
			s++;
			n = ni;
		}
		else
			n++;
	}
	n = ni;
	if(*s == '.')
	{
		s++;
		while(*n && *s)
		{
			if(*s == *n)
			{
				s++;
				n = ni;
			}
			else
				n++;
		}
	}

	while(*c && *s)
	{
		if(*s == *c)
			return(s);
		else
			c++;
	}
	return(NULL);
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

static long  ft_calclen(long nm )
{
	long l;

	l = 0;
	if( nm == 0)
		return(1);
	if( nm < 0)
	{
		nm *= -1;
		l++;
	}
	while( nm > 0)
	{

		nm /= 10;
		l++;
	}
	return(l);
}
/* this ft_atoi in a parallel universe :) */
char	*ft_itoa(int n)
{
	long 	nm;
	char	*ichr;
	long l;

	nm = n;
	l = ft_calclen(nm);
	ichr = malloc(sizeof(char) * (l + 1));
	if(!ichr)
		return(NULL);
	ichr[l--] = 0;
	if(nm == 0)
		ichr[l] = '0';
	if(nm < 0)
	{
		nm *= -1;
		ichr[0] = '-';
	}
	while(nm > 0)
	{
		ichr[l--] = 48 + (nm % 10);
		nm /= 10;
	}
	return(ichr);

}

char	*ft_utoa(unsigned int n)
{
	unsigned	int	nm;
	char	*ichr;
	long l;

	nm = n;
	l = ft_calclen(nm);
	ichr = malloc(sizeof(char) * (l + 1));
	if(!ichr)
		return(NULL);
	ichr[l--] = 0;
	if(nm == 0)
		ichr[l] = '0';
	while(nm > 0)
	{
		ichr[l--] = 48 + (nm % 10);
		nm /= 10;
	}
	return(ichr);

}

char	*ft_i2hx(unsigned int n)
{
	char			*hx;
	unsigned	int	i;
	long		int	l;

	l = 0;
	i = n;
	if(n == 0)
		l = 1;
	while(i)
	{
		i /= 16;
		l++;
	}
	hx = malloc((l+1) * sizeof(*hx));
	hx[l--] = 0;
	hx[l] = '0';
	while(n)
	{
		hx[l--] = "0123456789abcdef"[n % 16];
		n /= 16;
	}
	return(hx);
}

char	*ft_p2hx(void *p)
{
	char		*hx;
	long	int	i;
	long	int	n;
	long	int	l;

	n = (long int)p;
	l = 0;
	i = n;
	if(n == 0)
		l = 1;
	while(i)
	{
		i /= 16;
		l++;
	}
	l += 2;
	hx = malloc((l+1) * sizeof(*hx));
	hx[0] = '0';
	hx[1] = 'x';
	hx[l--] = 0;
	hx[l] = '0';
	while(n)
	{
		hx[l--] = "0123456789abcdef"[n % 16];
		n /= 16;
	}
	return(hx);
}

