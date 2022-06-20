#include "include/ft_printf_bonus.h"

char	*ft_str(char *fptr, long int flen, va_list *ap)
{
	char	*ns;
	char	*os;
	char	*pnt;
	int	num;
	int	pad;

	os = ft_strdup(va_arg(*ap, char *));
	ns = os;
	if(flen > 2)
	{
		if((pnt = ft_strnchr(fptr, '.', flen)))
		{
			num = ft_atoi(pnt + 1);
			if(num < ft_strlen(os))
			{
				ns = malloc((num + 1) * sizeof(*ns));
				ft_memcpy(ns, os, num);
				ns[num] = 0;
				free(os);
				os = ns;
			}
		}
		num = 0;
		while(fptr[num])
		{
			if(fptr[num] == '1' || fptr[num] == '2' || fptr[num] == '3'||  \
					fptr[num] == '4' || fptr[num] == '5' || fptr[num] == '6' || \
					fptr[num] == '7' || fptr[num] == '8' || fptr[num] == '9' )
			{
				num = ft_atoi(&fptr[num]);
				if(num > ft_strlen(os))
				{
					pad = num - ft_strlen(os);
					if(ft_strnchr(fptr, '-', flen))
					{
						ns = malloc((num + 1) * sizeof(*ns));
						ft_memcpy(ns, os, ft_strlen(os));
						ns += ft_strlen(os);
						while(pad--)
							*(ns++) = ' ';
						*ns = 0;
						ns -= (ft_strlen(os) + (num - ft_strlen(os)));
					}
					else
					{
						ns = malloc((num + 1) * sizeof(*ns));
						while(pad--)
							*(ns++) = ' ';
						ft_memcpy(ns, os, ft_strlen(os));
						*(ns + ft_strlen(os)) = 0;
						ns -= num - ft_strlen(os);
					}
				}
				break;
			}
			num++;
		}
	}
	if(os != ns)
		free(os);
	return(ns);
}

