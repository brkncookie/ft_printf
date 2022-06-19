#include "libft.h"
/* search n bytes of memory location pointed to by `s` for `c` */
void	*ft_memchr(const void *s, int c, size_t n)
{
	while(n--)
	{
		if(*(unsigned char *)s == (unsigned char)c)
			return((void *)s);
		(unsigned char *)s++;
	}
	return(NULL);
}

