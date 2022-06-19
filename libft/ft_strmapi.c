#include "libft.h"
/* for each successive application of `f()` on characters of the string pointed to by `s` we create at the end a string */
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t l;
	size_t	inx;
	char	*str;

	l = ft_strlen(s);
	inx = 0;
	if(!s || !f)
		return(NULL);

	str = ft_calloc(l+1, sizeof(char));
	if(!str)
		return(NULL);
	while(inx < l)
	{
		str[inx] = f((unsigned int)inx, s[inx]);
		inx++;
	}
	str[inx] = 0;
	return(str);
}


/* char myf(unsigned int i, char c) */
/* { */
/* 	return(c+i); */
/* } */

