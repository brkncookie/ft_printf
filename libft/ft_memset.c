#include "libft.h"
/* simply set `n` bytes of string pointed to by `s` to `c` */
void *ft_memset(void *s, int c, size_t n)
{
	/* n-- decremtns but instead returns the old value */
	while(n--)
		((char *)s)[n] = c;
	return(s);
}

