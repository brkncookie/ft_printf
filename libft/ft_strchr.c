#include "libft.h"
/* locate the `c` in the string pointed to by s */
char	*ft_strchr(const char *s, int c)
{
	while(*s)
	{
		if(*s == c)
			return (char *)s;
		s++;
	}
	if(*s == c)
		return (char *)s;
	return (NULL);
}

