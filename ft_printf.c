#include "include/ft_printf.h"

int	ft_islegal(char c)
{
	char *ff = "0123456789 0-#+.";
	char *fs = "csdixXup%";
	while(*ff)
	{
		if(c == *ff)
			return(1);
		ff++;
	}
	while(*fs)
	{
		if(c == *fs)
			return(2);
		fs++;
	}
	return(0);
}

char	*ft_str(char *fptr, int	flen, va_list *ap)
{
	return(strdup(va_arg(*ap, char *)));
}

fstr	*ft_fstrinfo(char *fmt)
{
	fstr	*finfo;
	char	*str;
	char	*fptr;
	long	int	flen;
	int 	inx;

	finfo = malloc(sizeof *finfo);
	finfo->cnt = 0;
	str = fmt;

	while((str = strchr(str, '%')) != NULL)
	{
			str++;
			while(ft_islegal(*str) && *str)
			{
				if(ft_islegal(*str) == 2)
				{
					finfo->cnt += 1;
					break;
				}
				str++;
			}
		if(!(*str))
			break;
		str++;
	}

	str = fmt;
	finfo->fptr = malloc(finfo->cnt * sizeof(char *));
	finfo->flen = malloc(finfo->cnt * sizeof(int));
	flen = 2;
	inx = 0;


	while(((str = strchr(str, '%')) != NULL) && inx < finfo->cnt)
	{
			fptr = str;
			flen = 2;
			str++;
			while(ft_islegal(*str) && *str)
			{
				if(ft_islegal(*str) == 2)
				{
					finfo->fptr[inx] = fptr;
					finfo->flen[inx] = flen;
					inx++;
					break;
				}
				flen++;
				str++;
			}
		if(!(*str))
			break;
		str++;
	}
	return(finfo);
}

char	**ft_resfs(fstr *finfo, va_list *ap)
{
	char	**rfs;
	int	inx;

	rfs = malloc(finfo->cnt * sizeof(*rfs));
	inx = 0;

	while(inx < finfo->cnt)
	{
		switch(finfo->fptr[inx][finfo->flen[inx]-1])
		{
			case 's':
				rfs[inx] = ft_str(finfo->fptr[inx], finfo->flen[inx], ap);
				break;
			case '%':
				rfs[inx] = "%";
				break;
		}
		inx++;
	}

	return(rfs);
}

int ft_printf(char *fmt, ...)
{
	va_list	ap;
	fstr	*finfo;
	char	**rfs;


	va_start(ap, fmt);

	finfo = ft_fstrinfo(fmt);
	rfs = ft_resfs(finfo, &ap);

	for(int i = 0; i < finfo->cnt; i++)
		printf("string: %s\n", rfs[i]);
	va_end(ap);
	return(0);
}

