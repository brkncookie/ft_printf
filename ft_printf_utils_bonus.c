#include "include/ft_printf_bonus.h"

/* this function check whether the fmt-str given is valid, using order-based checking */
char	*ft_isfs(char	*s)
{
	char	*f;
	char	*n;
	char	*c;
	char	*fi;
	char	*ni;

	f = " 0-+#";
	n = "0123456789";
	c = "csdixXup%";
	fi = f;
	ni = n;

	/* the logic of this loop repeats in multiple areas in the function */
	/* it's simply either it or not it, in both cases we proceed to the next loop in the function */
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
	/* the final segment in the function which determines the real validity of the fmt-str */
	while(*c && *s)
	{
		if(*s == *c)
			return(s);
		else
			c++;
	}
	return(NULL);
}

/* frees every allocation done in the program's lifespan */
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

/* ft_itoa but for unsigned int data type, used by ft_uns */
char	*ft_utoa(unsigned int n)
{
	unsigned	int	i;
	long		int	l;
	char			*ic;

	if(n == 0)
		return(ft_strdup("0"));
	i = n;
	l = 0;
	while(i)
	{
		i /= 10;
		l++;
	}
	ic = malloc((l + 1) * sizeof(*ic));
	if(!ic)
		return(NULL);
	ic[l] = 0;
	i = n;
	while(i)
	{
		ic[--l] = "0123456789"[i % 10];
		i /= 10;
	}
	return(ic);
}

/* convert unsigned int to hexadecimal format, used by ft_hex*/
char	*ft_i2hx(unsigned int n)
{
	unsigned	int	i;
	long		int	l;
	char			*hx;

	if(n == 0)
		return(ft_strdup("0"));
	i = n;
	l = 0;
	while(i)
	{
		i /= 16;
		l++;
	}

	hx = malloc((l+1) * sizeof(*hx));

	if(!hx)
		return(NULL);

	hx[l] = 0;
	i = n;

	while(i)
	{
		hx[--l] = "0123456789abcdef"[i % 16];
		i /= 16;
	}
	return(hx);
}

/* represents a ptr in a hexadecimal format, used by ft_ptr */
char	*ft_p2hx(void  *p)
{
	long		int	i;
	long		int	n;
	long		int	l;
	char			*hx;

	if(p == NULL)
		return(ft_strdup("(nil)"));
	n = (long int)p;
	i = n;
	l = 2;
	while(i)
	{
		i /= 16;
		l++;
	}

	hx = malloc((l+1) * sizeof(*hx));

	if(!hx)
		return(NULL);

	hx[0] = '0';
	hx[1] = 'x';
	hx[l] = 0;
	i = n;

	while(i)
	{
		hx[--l] = "0123456789abcdef"[i % 16];
		i /= 16;
	}
	return(hx);
}
/* same as ft_strchr but only operates on 'n' numbers of chars */
char	*ft_strnchr(const char *s, int c, long int n)
{
	while(*s && n)
	{
		if(*s == c)
			return (char *)s;
		s++;
		n--;
	}
	if(*s == c && n)
		return (char *)s;
	return (NULL);
}

