#include "include/ft_printf.h"
char	*ft_str(char *fptr, long int flen, va_list *ap)
{
	char	*ns;
	char	*os;
	char	*pnt;
	int	num;
	int	spc;
	/* precision, width, - flag */
	os = ft_strdup(va_arg(*ap, char *));
	ns = os;
	if(flen > 2)
	{
		if((pnt = ft_strchr(fptr, '.')))
		{
			num = atoi(pnt + 1);
			if(num == 0)
			{
				ns = malloc(sizeof(*ns));
				*ns = 0;
			}
			else if (num < ft_strlen(os))
			{
				ns = malloc((num + 1) * sizeof(*ns));
				ft_memcpy(ns, os, num);
				ns[num] = 0;
				free(os);
				os = ns;
			}
		}
		if((num = atoi(fptr+1)) > 0 && num > ft_strlen(os))
		{
			spc = num - ft_strlen(os);
			ns = malloc((num + 1) * sizeof(*ns));
			while(spc--)
				*(ns++) = ' ';
			ft_memcpy(ns, os, ft_strlen(os));
			*(ns + ft_strlen(os)) = 0;
			ns -= num - ft_strlen(os);
			free(os);
		}
		else if((num = atoi(fptr+1)) < 0 && (num * -1) > ft_strlen(os))
		{
			num *= -1;
			spc = num - ft_strlen(os);
			ns = malloc((num + 1) * sizeof(*ns));
			ft_memcpy(ns, os, ft_strlen(os));
			ns += ft_strlen(os);
			while(spc--)
				*(ns++) = ' ';
			*ns = 0;
			ns -= (ft_strlen(os) + num - ft_strlen(os));
			free(os);
		}
	}
	return(ns);
}

