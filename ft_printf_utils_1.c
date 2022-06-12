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
		}
	}
	if(os != ns)
		free(os);
	return(ns);
}

char	*ft_cha(char *fptr, long int flen, va_list *ap)
{
	char	*oc;
	char	*nc;
	int	num;
	int	spc;

	oc = malloc(2 * sizeof(*oc));
	nc = oc;
	oc[0] = (unsigned char)va_arg(*ap, int);
	oc[1] = 0;
	if(flen > 2)
	{
		if((num = atoi(fptr+1)) > 0 && num > ft_strlen(oc))
		{
			spc = num - ft_strlen(oc);
			nc = malloc((num + 1) * sizeof(*nc));
			while(spc--)
				*(nc++) = ' ';
			ft_memcpy(nc, oc, ft_strlen(oc));
			*(nc + ft_strlen(oc)) = 0;
			nc -= num - ft_strlen(oc);
		}
		else if((num = atoi(fptr+1)) < 0 && (num * -1) > ft_strlen(oc))
		{
			num *= -1;
			spc = num - ft_strlen(oc);
			nc = malloc((num + 1) * sizeof(*nc));
			ft_memcpy(nc, oc, ft_strlen(oc));
			nc += ft_strlen(oc);
			while(spc--)
				*(nc++) = ' ';
			*nc = 0;
			nc -= (ft_strlen(oc) + num - ft_strlen(oc));
		}

	}
	if(oc != nc)
		free(oc);
	return(nc);

}

