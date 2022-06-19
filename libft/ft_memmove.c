#include "libft.h"
/* memory-overlap aware version of memcpy */
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char 	t[n];
	/* char 	*d; */
	/* const char 	*s; */

	/* d = (char *)dest; */
	/* s = (const char *)src; */
	if(!dest && !src)
		return(NULL);

	ft_memcpy(t, src, n);
	ft_memcpy(dest, t, n);

	return(dest);
}

