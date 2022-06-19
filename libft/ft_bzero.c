#include "libft.h"
/* zero `n` bytes of string pointed to b `s` */
void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

