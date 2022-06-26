#include "include/ft_printf_bonus.h"

fsinfo	*ft_fsinfo_init(char *fmt)
{
	fsinfo		*fss;
	char		*hfmt;
	long	int	inx;

	fss = malloc(sizeof(*fss));
	if(!fss)
		return(NULL);

	fss->cnt = 0;
	hfmt = fmt;
	/* we count how many valid fmt-strs are there, to use it for further calcs*/
	while((hfmt = ft_strchr(hfmt, '%')))
	{
		hfmt++;
		if(ft_isfs(hfmt))
		{
			fss->cnt += 1;
			hfmt = ft_isfs(hfmt);
		}
		/* this saves us from a segfault in case the str ends with a '%' char */
		if(*hfmt == 0)
			break;
		hfmt++;
	}
	/* allocate the needed memory to save the ptr and length to each fmt-str in the str, using the count we calculated prev */
	fss->fptr = malloc(fss->cnt * sizeof(*(fss->fptr)));
	fss->flen = malloc(fss->cnt * sizeof(*(fss->flen)));
	if(!(fss->fptr) || !(fss->flen))
		return(NULL);
	hfmt = fmt;
	inx = 0;
	/* the actual saving of a ptr/length to each fmt-str while also checking it is a valid fmt-str */
	while((hfmt = ft_strchr(hfmt, '%')) && (inx < fss->cnt))
	{
		fss->fptr[inx] = hfmt;
		fss->flen[inx] = 2;
		hfmt++;
		if(ft_isfs(hfmt))
		{
			fss->flen[inx] += ft_isfs(hfmt) - hfmt;
			hfmt = ft_isfs(hfmt);
			inx++;
		}
		if(*hfmt == 0)
			break;
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

	/* given the num of the valid fmt-strs is known, we iterate through it */
	while(inx < fss->cnt)
	{
		/* we then retrieve each last char of the fmt-str which is the conversion specifier that determines which function to call */
		switch(fss->fptr[inx][fss->flen[inx]-1])
		{
			case 's':
				rfs[inx] = ft_str(fss->fptr[inx], fss->flen[inx], ap);
				break;
			case 'c':
				rfs[inx] = ft_cha(fss->fptr[inx], fss->flen[inx], ap);
				break;
			case 'x':
				rfs[inx] = ft_hex(fss->fptr[inx], fss->flen[inx], ap, 0);
				break;
			case 'X':
				rfs[inx] = ft_hex(fss->fptr[inx], fss->flen[inx], ap, 1);
				break;
			case 'p':
				rfs[inx] = ft_ptr(fss->fptr[inx], fss->flen[inx], ap);
				break;
			case 'u':
				rfs[inx] = ft_uns(fss->fptr[inx], fss->flen[inx], ap);
				break;
			case 'i':
			case 'd':
				rfs[inx] = ft_int(fss->fptr[inx], fss->flen[inx], ap);
				break;
			case '%':
				rfs[inx] = ft_strdup("%");
				break;
		}
		/* making sure that if smtng fails while trying to resolve a fmt-str we fail the correct way resulting in no memleaks/wasted resources */
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
	/* finally if all went well we return an array of resolved fmt-strs */
	return(rfs);
}

char	*ft_buildstr(char *fmt, char **rfs, fsinfo *fss)
{
	long	int	rslen;
	long	int	inx;
	char		*rstr;

	inx = 0;
	rslen = (long int)ft_strlen(fmt);

	/* calculates the length of the str when each fmt-str is resolved */
	while(inx < fss->cnt)
	{
		rslen -= fss->flen[inx];
		rslen += (long int)ft_strlen(rfs[inx++]);
	}

	rstr = malloc((rslen + 1) * sizeof(*rstr));
	if(!rstr)
		return(NULL);
	/* this loop basically work on two conditions, either we need to copy a regular str or we need to copy a resolved fmt-str */
	inx= 0;
	while(*fmt)
	{
		/* makeing sure we still have resolved fmt-strs to copy, and if we don't we just copy the rest of the str */
		if(inx < fss->cnt)
		{
			/* ptr is either pointing to a regular str or to a fmt-str */
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
				fmt  += fss->flen[inx];
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
	/* null it and return a ptr to the resolved str */
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

	/* this basically fetches each pointer and length to a valid fmt-str and the count of 'em */
	fss = ft_fsinfo_init(fmt);
	if(!fss)
		return(-1);
	/* if true, it means there's no fmt-strs or a valid one which results in the program just printing back the given str*/
	if(fss->cnt == 0)
	{
		free(fss);
		write(1, fmt, ft_strlen(fmt));
		return(ft_strlen(fmt));
	}

	va_start(ap, fmt);
	/* given that we have the needed info about each fmt-str, we go and resolve each fmt-str */
	rfs = ft_resfs(fss, &ap);
	if(!rfs)
		return(-2);

	/* given that we have successfully resolved each fmt-str, we try to build the final str using that */
	rstr = ft_buildstr(fmt, rfs, fss);
	if(!rstr)
		return(-3);
	va_end(ap);

	/* after successfully resolving/building the str, we then print it, return its length and free any used resources */
	write(1, rstr, ft_strlen(rstr));
	len = ft_strlen(rstr);
	ft_frall(rstr, rfs, fss);
	return(len);
}

