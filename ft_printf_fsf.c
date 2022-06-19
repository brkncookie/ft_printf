#include "include/ft_printf.h"

char	*ft_str(va_list *ap)
{
	return(ft_strdup(va_arg(*ap, char *)));
}

char	*ft_cha(va_list *ap)
{
	char *c;

	c = malloc(2 * sizeof(*c));
	if(!c)
		return(NULL);
	c[0] = (unsigned char)va_arg(*ap, int);
	c[1] = 0;

	return(c);
}
char	*ft_int(va_list *ap)
{
	return(ft_itoa(va_arg(*ap, int)));
}

char	*ft_uns(va_list *ap)
{
	return(ft_utoa(va_arg(*ap, unsigned int)));
}
char	*ft_hex(va_list *ap, int n)
{
	char	*hx;
	char	*x;

	hx = ft_i2hx(va_arg(*ap, unsigned int));
	if(!hx)
		return(NULL);
	if(n)
	{
		x = hx;
		while(x)
		{
			if(*x >= 'a' || *x <= 'f')
				*x -= 32;
			x++;
		}
	}
	return(hx);
}

char	*ft_ptr(va_list *ap)
{
	return(ft_p2hx(va_arg(*ap, void *)));
}

