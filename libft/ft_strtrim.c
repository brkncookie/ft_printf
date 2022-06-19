#include "libft.h"
/* trim the string point to by `s1` at the start and end of it from characters point to by `set` */
char	*ft_strtrim(char const *s1, char const *set)
{
	char	*end;
	char	*str;

	if(!s1 || !set)
		return(NULL);
	end = (char *)s1 + ft_strlen(s1) - 1;

	while(ft_strchr(set, *s1))
		s1++;
	while(ft_strrchr(set, *end))
		end--;
	/* nothing left to return */
	if(end < (char *)s1)
		return(ft_strdup(""));
	/* we add 2 because 0xffffde5-0xffffde4 = 1 and we need a byte for the null =D */
	str = malloc((end - s1 + 2) * sizeof(char));
	if(!str)
		return(NULL);
	/* why re-invent the wheel, huh ? */
	ft_strlcpy(str, s1, end - s1 +2);
	return(str);
}

