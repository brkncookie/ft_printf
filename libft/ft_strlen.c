#include <stddef.h>
/* returns length of a string excluding the null terminating byte */
size_t	ft_strlen(const char *s)
{
	/* this time let's do it a lil bit (or byte) differently */
	const char *ss = s;
	while(*s)
		s++;
	return((size_t)(s-ss));
}

