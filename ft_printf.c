#include "include/ft_printf.h"

fsinfo	*ft_fsinfo_init(char	*fmt)
{
	fsinfo	*fss;
	char	*hfmt;
	long	int	inx;

	fss = malloc(sizeof *fss);
	if(!fss)
		return(NULL);
	fss->cnt = 0;
	hfmt = fmt;

	while((hfmt = ft_strchr(hfmt, '%')) != NULL)
	{
		hfmt++;
		while(ft_isfs(*hfmt))
		{
			if(ft_isfs(*hfmt) == 2)
			{
				fss->cnt += 1;
				break;
			}
			hfmt++;
		}
	}

	fss->fptr = malloc(fss->cnt * sizeof(char *));
	fss->flen = malloc(fss->cnt * sizeof(int));
	if(!(fss->fptr) || !(fss->flen))
		return(NULL);
	hfmt = fmt;
	inx = 0;

	while((hfmt = ft_strchr(hfmt, '%')) != NULL && inx < fss->cnt)
	{
		fss->fptr[inx] = hfmt;
		fss->flen[inx] = 2;
		hfmt++;
		while(ft_isfs(*hfmt))
		{
			if(ft_isfs(*hfmt) == 2)
			{
				inx++;
				break;
			}
			fss->flen[inx] += 1;
			hfmt++;
		}
	}

	return(fss);
}

char	**ft_resfs(fsinfo *fss, va_list *ap)
{
	char		**rfs;
	long	int	inx;

	rfs = malloc(fss->cnt * sizeof(*rfs));
	if(!rfs)
		return(NULL);
	inx = 0;

	while(inx < fss->cnt)
	{
		switch(fss->fptr[inx][fss->flen[inx]-1])
		{
			case 's':
				rfs[inx] = ft_str(fss->fptr[inx], fss->flen[inx], ap);
				break;
			case 'c':
				rfs[inx] = ft_cha(fss->fptr[inx], fss->flen[inx], ap);
				break;
			case 'p':
				rfs[inx] = ft_ptr(fss->fptr[inx], fss->flen[inx], ap);
				break;
			case 'i':
			case 'd':
				rfs[inx] = ft_int(fss->fptr[inx], fss->flen[inx], ap);
				break;
			case 'x':
				rfs[inx] = ft_hex(fss->fptr[inx], fss->flen[inx], ap);
				break;
			case 'X':
				rfs[inx] = ft_HEX(fss->fptr[inx], fss->flen[inx], ap);
				break;
			case 'u':
				rfs[inx] = ft_uns(fss->fptr[inx], fss->flen[inx], ap);
				break;
			case '%':
				rfs[inx] = "%";
				break;
		}
		inx++;
	}

	return(rfs);
}

char	*ft_buildstr(char *fmt, char **rfs, fsinfo *fss)
{
	long	int	rslen;
	long	int	inx;
	char		*hfmt;
	char		*rstr;

	inx = 0;
	rslen = (long int)ft_strlen(fmt);
	while(inx < fss->cnt)
	{
		rslen -= fss->flen[inx];
		rslen += (long int)ft_strlen(rfs[inx]);
		inx++;
	}

	rstr = malloc((rslen + 1) * sizeof(*rstr));
	if(!rstr)
		return(NULL);
	inx = 0;
	hfmt = fmt;

	while(*hfmt)
	{
		if(inx < fss->cnt)
			if(hfmt < fss->fptr[inx])
			{
				ft_memcpy(rstr, hfmt, fss->fptr[inx] - hfmt);
				rstr += fss->fptr[inx] - hfmt;
				hfmt += fss->fptr[inx] - hfmt;
			}
			else
			{
				ft_memcpy(rstr, rfs[inx], ft_strlen(rfs[inx]);
				rstr += ft_strlen(rfs[inx]);
				hfmt += fss->flen[inx];
				inx++;
			}
		else
		{
			ft_memcpy(rstr, hfmt, ft_strlen(hfmt));
			rstr += ft_strlen(hfmt);
			hfmt += ft_strlen(hfmt);
		}
		*rstr = 0;
		return(rstr - rslen);
	}
}

int ft_printf(char *fmt, ...)
{
	char	**rfs;
	char	*rstr;
	fsinfo	*fss;
	va_list	ap;

	fss = ft_fsinfo_init(fmt);
	if(!fss)
		return(-1);
	if(fss->cnt == 0)
	{
		free(fss);
		write(stdout, fmt, ft_strlen(fmt));
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

	write(stdout, rstr, ft_strlen(rstr));
	return(ft_strlen(rstr));
}

