#include "libft.h"

/* calculate how many strings we have in `s` to allocate the right amount of pointer variables */
size_t ft_numptr(char const *s, char c)
{
	size_t n;
	long long inx;


	n = 0;
	inx = 0;
	while(s[inx])
	{
		while(s[inx] == c && s[inx])
			inx++;
		if(s[inx])
			n++;
		while(s[inx] != c && s[inx])
			inx++;
	}
	return(n);
}
/* this subroutine is used to free all of the allocations if an error occurs */

static char	**ft_frerec(char **strs, long long pinx)
{
	while(pinx >= 0)
		free(strs[pinx--]);
	free(strs);
	return(NULL);

}
/* for earch trimmed string in `s` we allocate the appropriate
memory size for it and copy it there
null the last pointer */
char **ft_strput(char const *s, char c, char **strs, size_t nptr)
{
	long long inx;
	long long sinx;
	size_t pinx;
	size_t	  l;

	l = 0;
	inx = 0;
	pinx = 0;
	sinx = 0;
	while(s[inx] && pinx < nptr)
	{
		while(s[inx] == c && s[inx])
			inx++;
		sinx = inx;
		while(s[inx] != c && s[inx])
		{
			l++;
			inx++;
		}
		strs[pinx] = ft_calloc(l, sizeof(char) + 1);
		if(!strs[pinx])
			return(ft_frerec(strs, pinx));
		ft_strlcpy(strs[pinx], &s[sinx], l + 1);
		l = 0;
		sinx = 0;
		pinx++;
		inx++;
	}
	strs[pinx] = 0;
	return(strs);
}
char	**ft_split(char const *s, char c)
{
	size_t	nptr;
	char	**strs;

	if(!s)
		return(NULL);
	/* allocate nptr of pointer variables */
	nptr = ft_numptr(s, c);
	strs = ft_calloc(nptr, sizeof(char *) + 1);
	if(!strs)
		return(NULL);

	/* get the strings to their final destination */
	strs = ft_strput(s, c, strs, nptr);
	if(!strs)
		return(NULL);
	return(strs);
}

