#include "libft.h"
/* copy `n` bytes from memory location pointed to by `src` to memory location pointed to by `dest` */
void	*ft_memcpy(void *restrict dest, const void *restrict src, size_t n)
{
	char	*d;
	const char	*s;

	d = (char *)dest;
	s = (const char *)src;
	if(!d && !s)
		return(NULL);
	while(n--)
		*(d++) = *(s++);
	return(dest);
}

