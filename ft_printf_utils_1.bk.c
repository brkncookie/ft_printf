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

char	*ft_int(char *fptr, long int flen, va_list *ap)
{
	/* precision, width, - flag, 0 flag, ' ' flag, + flag */
	char	*ptr;
	char	*oi;
	char	*foi;
	char	*ni;
	int	num;
	int 	pad;

	oi = ft_itoa(va_arg(*ap, int));
	ni = oi;
	if(flen > 2)
	{
		if((ptr = ft_strchr(fptr, '.')))
		{
			num = atoi(ptr+1);
			foi = oi;
			if(*oi == '-')
			{
				num++;
				oi++;
			}
			if(num > ft_strlen(oi))
			{
				pad = num - ft_strlen(oi);
				ni = malloc((num + 1) * sizeof(*ni));
				ni[num] = 0;
				while(pad--)
					*(ni++) = '0';
				ft_memcpy(ni, oi, ft_strlen(oi));
				ni -= num - ft_strlen(oi);
				if(*foi == '-')
					*ni = '-';
				free(foi);
				oi = ni;
			}
			else if( num == 0 && *oi == '0')
			{
				ni = malloc(sizeof(*ni));
				*ni = 0;
				free(oi);
				oi = ni;

			}
		}
		if((ft_strchr(fptr, '+')) && (*oi != '-'))
		{
			ni = malloc((ft_strlen(oi) + 2) * sizeof(*ni));
			*(ni++) = '+';
			ft_memcpy(ni, oi, ft_strlen(oi));
			*((ni--) + ft_strlen(oi)) = 0;
			free(oi);
			oi = ni;

		}
		else if((ft_strchr(fptr, ' ')) && (*oi != '-'))
		{
			ni = malloc((ft_strlen(oi) + 2) * sizeof(*ni));
			*(ni++) = ' ';
			ft_memcpy(ni, oi, ft_strlen(oi));
			*((ni--) + ft_strlen(oi)) = 0;
			free(oi);
			oi = ni;
		}
		num = 0;
		while(fptr[num])
		{
			if(fptr[num] == '1' || fptr[num] == '2' || fptr[num] == '3'||  \
					fptr[num] == '4' || fptr[num] == '5' || fptr[num] == '6' || \
					fptr[num] == '7' || fptr[num] == '8' || fptr[num] == '9' )
			{
			num = atoi(&fptr[num]);
			if(num > ft_strlen(oi))
			{
				pad = num - ft_strlen(oi);
				if(ft_strchr(fptr, '-'))
				{
					ni = malloc((num + 1) * sizeof(*ni));
					ni[num] = 0;
					ft_memcpy(ni, oi, ft_strlen(oi));
					ni += ft_strlen(oi);
					while(pad--)
						*(ni++) = ' ';
					ni -= (ft_strlen(oi ) + num - ft_strlen(oi ));
					free(oi);
					oi = ni;
					foi = oi;

				}
				else if(ft_strchr(fptr, '0') && ptr == NULL)
				{
					ni = malloc((num + 1) * sizeof(*ni));
					ni[num] = 0;
					foi = oi;
					if(*oi == '-' || *oi == ' ' || *oi == '+')
					{
						ni++;
						oi++;
					}
					while(pad--)
						*(ni++) = '0';
					ft_memcpy(ni, oi, ft_strlen(oi));
					if(*foi == '-' || *foi == ' ' || *foi == '+')
					{
						ni -= (num - ft_strlen(foi)) + 1;
						*ni = *foi;
					}
					else
						ni -= num - ft_strlen(oi);
					free(foi);
					oi = ni;
				}
				else
				{

					ni = malloc((num + 1) * sizeof(*ni));
					ni[num] = 0;
					foi = oi;
					if(*oi == '-' || *oi == ' ' || *oi == '+')
					{
						ni++;
						oi++;
					}
					while(pad--)
						*(ni++) = ' ';
					ft_memcpy(ni, oi, ft_strlen(oi));
					if(*foi == '-' || *foi == ' ' || *foi == '+')
					{
						ni -= (num - ft_strlen(foi)) + 1;
						*ni = *foi;
					}
					else
						ni -= num - ft_strlen(oi);
					free(foi);
					oi = ni;
				}
			}
			break;
			}
		num++;
		}
	}

	if(oi != ni)
		free(oi);
	return(ni);

}

char	*ft_uns(char *fptr, long int flen, va_list *ap)
{
	/* precision, width, - flag, 0 flag */
	char	*ptr;
	char	*oi;
	char	*ni;
	int	num;
	int 	pad;

	oi = ft_utoa(va_arg(*ap, unsigned int));
	ni = oi;
	if(flen > 2)
	{
		if((ptr = ft_strchr(fptr, '.')))
		{
			num = atoi(ptr+1);
			if(num > ft_strlen(oi))
			{
				pad = num - ft_strlen(oi);
				ni = malloc((num + 1) * sizeof(*ni));
				ni[num] = 0;
				while(pad--)
					*(ni++) = '0';
				ft_memcpy(ni, oi, ft_strlen(oi));
				ni -= num - ft_strlen(oi);
				free(oi);
				oi = ni;
			}
			else if( num == 0 && *oi == '0')
			{
				ni = malloc(sizeof(*ni));
				*ni = 0;
				free(oi);
				oi = ni;

			}
		}
		num = 0;
		while(fptr[num])
		{
			if(fptr[num] == '1' || fptr[num] == '2' || fptr[num] == '3'||  \
					fptr[num] == '4' || fptr[num] == '5' || fptr[num] == '6' || \
					fptr[num] == '7' || fptr[num] == '8' || fptr[num] == '9' )
			{
			num = atoi(&fptr[num]);
			if(num > ft_strlen(oi))
			{
				pad = num - ft_strlen(oi);
				if(ft_strchr(fptr, '-'))
				{
					ni = malloc((num + 1) * sizeof(*ni));
					ni[num] = 0;
					ft_memcpy(ni, oi, ft_strlen(oi));
					ni += ft_strlen(oi);
					while(pad--)
						*(ni++) = ' ';
					ni -= (ft_strlen(oi ) + num - ft_strlen(oi ));
					free(oi);
					oi = ni;

				}
				else if(ft_strchr(fptr, '0') && ptr == NULL)
				{
					ni = malloc((num + 1) * sizeof(*ni));
					ni[num] = 0;
					while(pad--)
						*(ni++) = '0';
					ft_memcpy(ni, oi, ft_strlen(oi));
					ni -= num - ft_strlen(oi);
					free(oi);
					oi = ni;
				}
				else
				{

					ni = malloc((num + 1) * sizeof(*ni));
					ni[num] = 0;
					while(pad--)
						*(ni++) = ' ';
					ft_memcpy(ni, oi, ft_strlen(oi));
					ni -= num - ft_strlen(oi);
					free(oi);
					oi = ni;
				}
			}
			break;
			}
		num++;
		}
	}

	if(oi != ni)
		free(oi);
	return(ni);

}

char	*ft_hex(char *fptr, long int flen, va_list *ap)
{
	/* precision, width, - flag, 0 flag */
	char	*ptr;
	char	*oi;
	char	*foi;
	char	*ni;
	int	num;
	int 	pad;

	oi = ft_i2hx(va_arg(*ap, unsigned int));
	ni = oi;
	if(flen > 2)
	{
		if((ptr = ft_strchr(fptr, '.')))
		{
			num = atoi(ptr+1);
			if(num > ft_strlen(oi))
			{
				pad = num - ft_strlen(oi);
				ni = malloc((num + 1) * sizeof(*ni));
				ni[num] = 0;
				while(pad--)
					*(ni++) = '0';
				ft_memcpy(ni, oi, ft_strlen(oi));
				ni -= num - ft_strlen(oi);
				free(oi);
				oi = ni;
			}
			else if( num == 0 && *oi == '0')
			{
				ni = malloc(sizeof(*ni));
				*ni = 0;
				free(oi);
				oi = ni;

			}
		}
		if(ft_strchr(fptr, '#'))
		{
			ni = malloc((ft_strlen(oi) + 3) * sizeof(*ni));
			ni[0] = '0';
			ni[1] = 'x';
			ft_memcpy(ni + 2, oi, ft_strlen(oi));
			ni[ft_strlen(oi) + 2] = 0;
			free(oi);
			oi = ni;
		}
		num = 0;
		while(fptr[num])
		{
			if(fptr[num] == '1' || fptr[num] == '2' || fptr[num] == '3'||  \
					fptr[num] == '4' || fptr[num] == '5' || fptr[num] == '6' || \
					fptr[num] == '7' || fptr[num] == '8' || fptr[num] == '9' )
			{
			num = atoi(&fptr[num]);
			if(num > ft_strlen(oi))
			{
				pad = num - ft_strlen(oi);
				if(ft_strchr(fptr, '-'))
				{
					ni = malloc((num + 1) * sizeof(*ni));
					ni[num] = 0;
					ft_memcpy(ni, oi, ft_strlen(oi));
					ni += ft_strlen(oi);
					while(pad--)
						*(ni++) = ' ';
					ni -= (ft_strlen(oi ) + num - ft_strlen(oi ));
					free(oi);
					oi = ni;

				}
				else if(ft_strchr(fptr, '0') && ptr == NULL)
				{

					ni = malloc((num + 1) * sizeof(*ni));
					ni[num] = 0;
					foi = oi;
					if(*(foi+1) == 'x')
					{
						ni += 2;
						oi += 2;
					}
					while(pad--)
						*(ni++) = '0';
					ft_memcpy(ni, oi, ft_strlen(oi));
					if(*(foi+1) == 'x')
					{
						ni -= (num - ft_strlen(foi)) + 2;
						*ni = *foi;
						*(ni + 1) = *(foi + 1);
					}
					else
						ni -= num - ft_strlen(oi);
					free(foi);
					oi = ni;
				}
				else
				{

					ni = malloc((num + 1) * sizeof(*ni));
					ni[num] = 0;
					while(pad--)
						*(ni++) = ' ';
					ft_memcpy(ni, oi, ft_strlen(oi));
					ni -= num - ft_strlen(oi);
					free(oi);
					oi = ni;
				}
			}
			break;
			}
		num++;
		}

	}

	if(oi != ni)
		free(oi);
	return(ni);

}

char	*ft_ptr(char *fptr, long int flen, va_list *ap)
{
	/* precision, width, - flag, 0 flag */
	char	*ptr;
	char	*oi;
	char	*ni;
	int	num;
	int 	pad;

	oi = ft_p2hx(va_arg(*ap, void *));
	ni = oi;
	if(flen > 2)
	{
		if((ptr = ft_strchr(fptr, '.')))
		{
			num = atoi(ptr+1) + 2;
			if(num > (ft_strlen(oi)))
			{
				pad = num - ft_strlen(oi);
				ni = malloc((num + 1) * sizeof(*ni));
				ni[num] = 0;
				ni += 2;
				oi += 2;
				while(pad--)
					*(ni++) = '0';
				ft_memcpy(ni, oi, ft_strlen(oi));
				ni -= (num - ft_strlen(oi - 2)) + 2;
				*ni = '0';
				*(ni + 1) = 'x';
				free(oi - 2);
				oi = ni;
			}
			else if( num == 0 && *oi == '0')
			{
				ni = malloc(sizeof(*ni));
				*ni = 0;
				free(oi);
				oi = ni;

			}
		}
		num = 0;
		while(fptr[num])
		{
			if(fptr[num] == '1' || fptr[num] == '2' || fptr[num] == '3'||  \
					fptr[num] == '4' || fptr[num] == '5' || fptr[num] == '6' || \
					fptr[num] == '7' || fptr[num] == '8' || fptr[num] == '9' )
			{
			num = atoi(&fptr[num]);
			if(num > ft_strlen(oi))
			{
				pad = num - ft_strlen(oi);
				if(ft_strchr(fptr, '-'))
				{
					ni = malloc((num + 1) * sizeof(*ni));
					ni[num] = 0;
					ft_memcpy(ni, oi, ft_strlen(oi));
					ni += ft_strlen(oi);
					while(pad--)
						*(ni++) = ' ';
					ni -= (ft_strlen(oi ) + num - ft_strlen(oi ));
					free(oi);
					oi = ni;

				}
				else if(ft_strchr(fptr, '0') && ptr == NULL)
				{
					ni = malloc((num + 1) * sizeof(*ni));
					ni[num] = 0;
					ni += 2;
					oi += 2;
					while(pad--)
						*(ni++) = '0';
					ft_memcpy(ni, oi, ft_strlen(oi));
					ni -= (num - ft_strlen(oi - 2)) + 2;
					*ni = '0';
					*(ni + 1) = 'x';
					free(oi - 2);
					oi = ni;
				}
				else
				{

					ni = malloc((num + 1) * sizeof(*ni));
					ni[num] = 0;
					while(pad--)
						*(ni++) = ' ';
					ft_memcpy(ni, oi, ft_strlen(oi));
					ni -= num - ft_strlen(oi);
					free(oi);
					oi = ni;
				}
			}
			break;
			}
		num++;
		}
	}

	if(oi != ni)
		free(oi);
	return(ni);

}

