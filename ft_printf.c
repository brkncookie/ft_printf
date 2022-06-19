#include "include/ft_printf.h"

fsinfo	*ft_fsinfo_init(char	*fmt)
{
	fsinfo	*fss;
	char	*hfmt;
	long	int	inx;

	fss = malloc(sizeof(*fss));
	if(!fss)
		return(NULL);
	fss->cnt = 0;
	hfmt = fmt;

	while((hfmt = ft_strchr(hfmt, '%')))
	{
		hfmt++;
		if(*hfmt == 'c' || *hfmt == 's' || *hfmt == 'p' || *hfmt == 'i' \
				|| *hfmt == 'd' || *hfmt == 'x' || *hfmt == 'X' || *hfmt == '%')
			fss->cnt++;
		if(*hfmt = 0)
			break;
		hfmt++;
	}

	fss->fptr = malloc(fss->cnt * sizeof(*(fss->fptr)));
	if(!(fss->fptr))
	{
		free(fss);
		return(NULL);
	}
	hfmt = fmt;
	inx = 0;
	while((hfmt = ft_strchr(hfmt,'%')) && (inx < fss->cnt))
	{
		fss->fptr[inx] = hfmt;
		hfmt++;
		if(*hfmt == 'c' || *hfmt == 's' || *hfmt == 'p' || *hfmt == 'i' \
				|| *hfmt == 'd' || *hfmt == 'x' || *hfmt == 'X' || *hfmt == '%')
			inx++;
		hfmt++;
	}
	return(fss);

}

char	**ft_resfs(fsinfo *fss, va_list *ap)
{
	char	**rfs;
	long	int	inx;

	rfs = malloc(fss->cnt * sizeof(*rfs));
	if(!rfs)
		return(NULL);
	inx = 0;

	while(inx < fss->cnt)
	{
		switch(fss->fptr[inx][1])
		{
			case 's':
				rfs[inx] = ft_str(ap);
				break;
			case 'c':
				rfs[inx] = ft_cha(ap);
				break;
			case 'x':
				rfs[inx] = ft_hex(ap, 0);
				break;
			case 'X':
				rfs[inx] = ft_hex(ap, 1);
				break;
			case 'p':
				rfs[inx] = ft_ptr(ap);
				break;
			case 'u':
				rfs[inx] = ft_uns(ap);
				break;
			case 'i':
			case 'd':
				rfs[inx] = ft_int(ap);
				break;
			case '%':
				rfs[inx] = ft_strdup("%");
				break;
		}
		if(!(rfs[inx]))
		{
			--inx;
			while(inx >= 0)
				free(rfs[inx--]);
			free(rfs);
			return(NULL);
		}
		inx++;
	}
	return(rfs);
}

char	*ft_buildstr(char *fmt, char **rfs, fsinfo *fss)
{
	long	int	rslen;
	long	int	inx;
	char		*rstr;

	inx = 0;
	rslen = (long int)ft_strlen(fmt);

	while(inx < fss->cnt)
	{
		rslen -= 2;
		rslen += (long int)ft_strlen(rfs[inx++]);
	}

	rstr = malloc((rslen + 1) * sizeof(*rstr));
	if(!rstr)
		return(NULL);
	inx= 0;
	while(*fmt)
	{
		if(inx < fss->cnt)
		{
			if(fmt < fss->fptr[inx])
			{
				ft_memcpy(rstr, fmt, fss->fptr[inx] - fmt);
				rstr += fss->fptr[inx] - fmt;
				fmt  += fss->fptr[inx] - fmt;

			}
			else
			{
				ft_memcpy(rstr, rfs[inx], ft_strlen(rfs[inx]));
				rstr += ft_strlen(rfs[inx]);
				fmt  += 2;
				inx++;
			}
		}
		else
		{
			ft_memcpy(rstr, fmt, ft_strlen(fmt));
			rstr += ft_strlen(fmt);
			fmt  += ft_strlen(fmt);
		}
	}
	*rstr = 0;
	return(rstr - rslen);
}


int ft_printf(char *fmt, ...)
{
	char	**rfs;
	char	*rstr;
	fsinfo	*fss;
	int	len;
	va_list	ap;

	fss = ft_fsinfo_init(fmt);
	if(!fss)
		return(-1);
	if(fss->cnt == 0)
	{
		free(fss);
		write(1, fmt, ft_strlen(fmt));
		return(ft_strlen(fmt));
	}

	va_start(ap, fmt);
	rfs = ft_resfs(fss, &ap);
	if(!rfs)
		return(-2);

	rstr = ft_buildstr(fmt, rfs, fss);
	if(!rstr)
		return(-3);
	va_end(ap);

	write(1, rstr, ft_strlen(rstr));
	len = ft_strlen(rstr);
	ft_frall(rstr, rfs, fss);
	return(len);
}

