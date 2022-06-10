#include "include/ft_printf.h"
char	*ft_str(char *fptr, long int flen, va_list *ap)
{
	char	*ns;
	char	*os;
	int	msze;
	long	int	len;
	/* precision, width, - flag */
	os = ft_strdup(va_arg(*ap, char *));
	ns = os;
	len = 1;
	if(flen > 2)
		while(len < flen)
		{
			if(fptr[len] == '.')
			{
				msze = atoi(&(fptr[len+1]));
				if(msze == 0)
				{
					ns = malloc(sizeof(*ns));
					*ns = 0;
				}
				/* else if (msze < 0) */
				/* 	ns = os; */
				else if (msze < ft_strlen(os))
				{
					ns = malloc((msze + 1) * sizeof(*ns));
					ft_memcpy(ns, os, msze);
					ns[msze] = 0;
					free(os);
				}

			}
			len++;
		}
	return(ns);

}

