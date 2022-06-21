#include "include/ft_printf_bonus.h"

char	*ft_str(char *fptr, long int flen, va_list *ap)
{
	char	*ns;
	char	*os;
	char	*pnt;
	long	int	num;
	long	int	pad;

	os = ft_strdup(va_arg(*ap, char *));
	ns = os;
	if(flen > 2)
	{
		if((pnt = ft_strnchr(fptr, '.', flen)))
		{
			num = ft_atoi(pnt + 1);
			if(num < (long int)ft_strlen(os))
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
				if(num > (long int)ft_strlen(os))
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


char	*ft_cha(char *fptr, long int flen, va_list *ap)
{
	char	*oc;
	char	*nc;
	long	int	num;
	long	int	pad;

	oc = malloc(2 * sizeof(*oc));
	oc[0] = (unsigned char)va_arg(*ap, int);
	oc[1] = 0;
	nc = oc;
	if(flen > 2)
	{

		num = 0;
		while(fptr[num])
		{
			if(fptr[num] == '1' || fptr[num] == '2' || fptr[num] == '3'||  \
					fptr[num] == '4' || fptr[num] == '5' || fptr[num] == '6' || \
					fptr[num] == '7' || fptr[num] == '8' || fptr[num] == '9' )
			{
				num = ft_atoi(&fptr[num]);
				if(num > (long int)ft_strlen(oc))
				{
					pad = num - ft_strlen(oc);
					if(ft_strnchr(fptr, '-', flen))
					{
						nc = malloc((num + 1) * sizeof(*nc));
						ft_memcpy(nc, oc, ft_strlen(oc));
						nc += ft_strlen(oc);
						while(pad--)
							*(nc++) = ' ';
						*nc = 0;
						nc -= (ft_strlen(oc) + (num - ft_strlen(oc)));
					}
					else
					{
						nc = malloc((num + 1) * sizeof(*nc));
						while(pad--)
							*(nc++) = ' ';
						ft_memcpy(nc, oc, ft_strlen(oc));
						*(nc + ft_strlen(oc)) = 0;
						nc -= num - ft_strlen(oc);
					}
				}
				break;
			}
			num++;
		}
	}
	if(oc != nc)
		free(oc);
	return(nc);
}

char	*ft_int(char *fptr, long int flen, va_list *ap)
{

	char	*ptr;
	char	*oi;
	char	*ni;
	long	int	num;
	long	int 	pad;

	oi = ft_itoa(va_arg(*ap, int));
	ni = oi;
	if(flen > 2)
	{
		if((ptr = ft_strnchr(fptr, '.', flen)))
		{
			num = ft_atoi(ptr+1);
			ptr = oi;
			if(*oi == '-')
			{
				num++;
				oi++;
			}
			if(num > (long int)ft_strlen(oi))
			{
				pad = num - ft_strlen(oi);
				ni = malloc((num + 1) * sizeof(*ni));
				ni[num] = 0;
				while(pad--)
					*(ni++) = '0';
				ft_memcpy(ni, oi, ft_strlen(oi));
				ni -= num - ft_strlen(oi);
				if(*ptr == '-')
					*ni = '-';
				free(ptr);
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
		if((ft_strnchr(fptr, '+', flen)) && (*oi != '-'))
		{
			ni = malloc((ft_strlen(oi) + 2) * sizeof(*ni));
			*(ni++) = '+';
			ft_memcpy(ni, oi, ft_strlen(oi));
			*((ni--) + ft_strlen(oi)) = 0;
			free(oi);
			oi = ni;

		}
		else if((ft_strnchr(fptr, ' ', flen)) && (*oi != '-'))
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
			num = ft_atoi(&fptr[num]);
			if(num > (long int)ft_strlen(oi))
			{
				pad = num - ft_strlen(oi);
				if(ft_strnchr(fptr, '-', flen))
				{
					ni = malloc((num + 1) * sizeof(*ni));
					ni[num] = 0;
					ft_memcpy(ni, oi, ft_strlen(oi));
					ni += ft_strlen(oi);
					while(pad--)
						*(ni++) = ' ';
					ni -= (ft_strlen(oi) + (num - ft_strlen(oi)));
					free(oi);
					oi = ni;
				}
				else if(ft_strnchr(fptr, '0', flen) && ptr == NULL)
				{
					ni = malloc((num + 1) * sizeof(*ni));
					ni[num] = 0;
					ptr = oi;
					if(*oi == '-' || *oi == ' ' || *oi == '+')
					{
						ni++;
						oi++;
					}
					while(pad--)
						*(ni++) = '0';
					ft_memcpy(ni, oi, ft_strlen(oi));
					if(*ptr == '-' || *ptr == ' ' || *ptr == '+')
					{
						ni -= (num - ft_strlen(ptr)) + 1;
						*ni = *ptr;
					}
					else
						ni -= num - ft_strlen(oi);
					free(ptr);
					oi = ni;
				}
				else
				{
					ni = malloc((num + 1) * sizeof(*ni));
					ni[num] = 0;
					ptr = oi;
					if(*oi == '-' || *oi == ' ' || *oi == '+')
					{
						ni++;
						oi++;
					}
					while(pad--)
						*(ni++) = ' ';
					ft_memcpy(ni, oi, ft_strlen(oi));
					if(*ptr == '-' || *ptr == ' ' || *ptr == '+')
					{
						ni -= (num - ft_strlen(ptr)) + 1;
						*ni = *ptr;
					}
					else
						ni -= num - ft_strlen(oi);
					free(ptr);
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

	char	*ptr;
	char	*ou;
	char	*nu;
	long	int	num;
	long	int 	pad;

	ou = ft_utoa(va_arg(*ap, int));
	nu = ou;
	if(flen > 2)
	{
		if((ptr = ft_strnchr(fptr, '.', flen)))
		{
			num = ft_atoi(ptr+1);
			if(num > (long int)ft_strlen(ou))
			{
				pad = num - ft_strlen(ou);
				nu = malloc((num + 1) * sizeof(*nu));
				nu[num] = 0;
				while(pad--)
					*(nu++) = '0';
				ft_memcpy(nu, ou, ft_strlen(ou));
				nu -= num - ft_strlen(ou);
				free(ptr);
				ou = nu;
			}
			else if( num == 0 && *ou == '0')
			{
				nu = malloc(sizeof(*nu));
				*nu = 0;
				free(ou);
				ou = nu;

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
			if(num > (long int)ft_strlen(ou))
			{
				pad = num - ft_strlen(ou);
				if(ft_strnchr(fptr, '-', flen))
				{
					nu = malloc((num + 1) * sizeof(*nu));
					nu[num] = 0;
					ft_memcpy(nu, ou, ft_strlen(ou));
					nu += ft_strlen(ou);
					while(pad--)
						*(nu++) = ' ';
					nu -= (ft_strlen(ou) + (num - ft_strlen(ou)));
					free(ou);
					ou = nu;
				}
				else if(ft_strnchr(fptr, '0', flen) && ptr == NULL)
				{
					nu = malloc((num + 1) * sizeof(*nu));
					nu[num] = 0;
					while(pad--)
						*(nu++) = '0';
					ft_memcpy(nu, ou, ft_strlen(ou));
					nu -= num - ft_strlen(ou);
					free(ou);
					ou = nu;
				}
				else
				{
					nu = malloc((num + 1) * sizeof(*nu));
					nu[num] = 0;
					while(pad--)
						*(nu++) = ' ';
					ft_memcpy(nu, ou, ft_strlen(ou));
					nu -= num - ft_strlen(ou);
					free(ou);
					ou = nu;

				}
			}
			break;
			}
		num++;
		}
	}
	if(ou != nu)
		free(ou);
	return(nu);
}

char	*ft_hex(char *fptr, long int flen, va_list *ap, int n)
{

	char	*ptr;
	char	*ox;
	char	*nx;
	long	int	num;
	long	int 	pad;

	ox = ft_i2hx(va_arg(*ap, int));
	nx = ox;
	if(flen > 2)
	{
		if((ptr = ft_strnchr(fptr, '.', flen)))
		{
			num = ft_atoi(ptr+1);
			if(num > (long int)ft_strlen(ox))
			{
				pad = num - ft_strlen(ox);
				nx = malloc((num + 1) * sizeof(*nx));
				nx[num] = 0;
				while(pad--)
					*(nx++) = '0';
				ft_memcpy(nx, ox, ft_strlen(ox));
				nx -= num - ft_strlen(ox);
				free(ptr);
				ox = nx;
			}
			else if( num == 0 && *ox == '0')
			{
				nx = malloc(sizeof(*nx));
				*nx = 0;
				free(ox);
				ox = nx;

			}
		}
		if(ft_strnchr(fptr, '#', flen))
		{
			nx = malloc((ft_strlen(ox) + 3) * sizeof(*nx));
			nx[0] = '0';
			nx[1] = 'x';
			ft_memcpy(nx + 2, ox, ft_strlen(ox));
			nx[ft_strlen(ox) + 2] = 0;
			free(ox);
			ox = nx;
		}
		num = 0;
		while(fptr[num])
		{
			if(fptr[num] == '1' || fptr[num] == '2' || fptr[num] == '3'||  \
					fptr[num] == '4' || fptr[num] == '5' || fptr[num] == '6' || \
					fptr[num] == '7' || fptr[num] == '8' || fptr[num] == '9' )
			{
			num = ft_atoi(&fptr[num]);
			if(num > (long int)ft_strlen(ox))
			{
				pad = num - ft_strlen(ox);
				if(ft_strnchr(fptr, '-', flen))
				{
					nx = malloc((num + 1) * sizeof(*nx));
					nx[num] = 0;
					ft_memcpy(nx, ox, ft_strlen(ox));
					nx += ft_strlen(ox);
					while(pad--)
						*(nx++) = ' ';
					nx -= (ft_strlen(ox) + (num - ft_strlen(ox)));
					free(ox);
					ox = nx;
				}
				else if(ft_strnchr(fptr, '0', flen) && ptr == NULL)
				{
					nx = malloc((num + 1) * sizeof(*nx));
					nx[num] = 0;
					ptr = ox;
					if(*(ox+1) == 'x')
					{
						ox += 2;
						nx += 2;
					}
					while(pad--)
						*(nx++) = '0';
					ft_memcpy(nx, ox, ft_strlen(ox));
					if(*(ptr+1) == 'x')
					{
						nx -= (num - ft_strlen(ox)) + 2;
						nx[0] = ptr[0];
						nx[1] = ptr[1];
					}
					else
						nx -= num - ft_strlen(ox);
					free(ox);
					ox = nx;
				}
				else
				{
					nx = malloc((num + 1) * sizeof(*nx));
					nx[num] = 0;
					while(pad--)
						*(nx++) = ' ';
					ft_memcpy(nx, ox, ft_strlen(ox));
					nx -= num - ft_strlen(ox);
					free(ox);
					ox = nx;

				}
			}
			break;
			}
		num++;
		}
	}
	if(ox != nx)
	{
		free(ox);
		ox = nx;
	}
	if(n)
	{
		while(*ox)
		{
			if(*ox >= 'a' && *ox <= 'f')
				*ox -= 32;
			ox++;
		}
	}
	return(nx);
}

char	*ft_ptr(char *fptr, long int flen, va_list *ap)
{
	/* precision, width, - flag, 0 flag */
	char	*ptr;
	char	*op;
	char	*np;
	int	num;
	int 	pad;

	op = ft_p2hx(va_arg(*ap, void *));
	np = op;
	if(flen > 2 && (ft_strncmp(op, "(nil)", ft_strlen(op)) != 0))
	{
		if((ptr = ft_strnchr(fptr, '.', flen)))
		{
			num = ft_atoi(ptr+1) + 2;
			if(num > (long int)(ft_strlen(op)))
			{
				pad = num - ft_strlen(op);
				np = malloc((num + 1) * sizeof(*np));
				np[num] = 0;
				np += 2;
				op += 2;
				while(pad--)
					*(np++) = '0';
				ft_memcpy(np, op, ft_strlen(op));
				np -= (num - ft_strlen(op - 2)) + 2;
				np[0] = '0';
				np[1] = 'x';
				free(op - 2);
				op = np;
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
			if(num > (long int)ft_strlen(op))
			{
				pad = num - ft_strlen(op);
				if(ft_strnchr(fptr, '-', flen))
				{
					np = malloc((num + 1) * sizeof(*np));
					np[num] = 0;
					ft_memcpy(np, op, ft_strlen(op));
					np += ft_strlen(op);
					while(pad--)
						*(np++) = ' ';
					np -= (ft_strlen(op ) + (num - ft_strlen(op )));
					free(op);
					op = np;

				}
				else if(ft_strnchr(fptr, '0', flen) && ptr == NULL)
				{
					np = malloc((num + 1) * sizeof(*np));
					np[num] = 0;
					np += 2;
					op += 2;
					while(pad--)
						*(np++) = '0';
					ft_memcpy(np, op, ft_strlen(op));
					np -= (num - ft_strlen(op - 2)) + 2;
					np[0] = '0';
					np[1] = 'x';
					free(op - 2);
					op = np;
				}
				else
				{

					np = malloc((num + 1) * sizeof(*np));
					np[num] = 0;
					while(pad--)
						*(np++) = ' ';
					ft_memcpy(np, op, ft_strlen(op));
					np -= num - ft_strlen(op);
					free(op);
					op = np;
				}
			}
			break;
			}
		num++;
		}
	}

	if(op != np)
		free(op);
	return(np);

}

