#include "libft.h"
/* compare `n` bytes of the strings pointed to by `s1` and `s2` subtracting each
byte and returning the result as soon as it doesn't equal zero pretty straightforward, huh ? */
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while(*s1 && n)
	{
		if(*s1 != *s2)
			return((unsigned char)*s1 - (unsigned char)*s2);
		s1++;
		s2++;
		n--;
	}
	return(0);
}

