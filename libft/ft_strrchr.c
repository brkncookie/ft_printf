#include "libft.h"
char	*ft_strrchr(const char *s, int c)
{
	long long l = ft_strlen(s);

	while(l >= 0)
	{
		if(*(s+l) == (char)c)
			return (char *)(s+l);
		l--;
	}
	return (NULL);
}

