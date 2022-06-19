#include "include/ft_printf.h"

void	ft_frall(char *rstr, char **rfs, fsinfo *fss)
{
	long	int inx;

	inx = 0;
	while(inx < fss->cnt)
		free(rfs[inx++]);

	free(rfs);
	free(fss->fptr);
	free(fss);
	free(rstr);
}

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

char	*ft_p2hx(void  *p)
{
	unsigned	int	i;
	unsigned	int	n;
	long		int	l;
	char			*hx;

	if(p == NULL)
		return(ft_strdup("0x0"));
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

