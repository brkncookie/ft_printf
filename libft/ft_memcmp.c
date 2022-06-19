#include "libft.h"
/*compare n bytes of memory locations pointed to by `s1` and `s2` */
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	while(n--)
	{
		if(*(unsigned char *)s1 != *(unsigned char*)s2)
			return(*(unsigned char *)s1 - *(unsigned char*)s2);
		s1++;
		s2++;
	}
	return(0);
}

