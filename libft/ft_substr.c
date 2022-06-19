#include "libft.h"
/* returns a substring from a string starting at `start` and only using `len` bytes */
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char *str;

	if(!s)
		return(NULL);
	str = malloc(++len * sizeof(char));
	if(!str)
		return(NULL);
	/* the n!gga asked for too much, huh ? give him nothing then */
	if(start >= ft_strlen(s))
		return(str);
	ft_strlcpy(str, s + start, len);
	return(str);
}

