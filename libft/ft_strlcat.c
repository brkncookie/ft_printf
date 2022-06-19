#include "libft.h"
/* see https://opensource.apple.com/source/OpenSSH/OpenSSH-7.1/openssh/bsd-strlcat.c.auto.html && \
https://opensource.apple.com/source/Libc/Libc-825.25/string/strlcat.c.auto.html */

/* this function doesn't return more that the actual given parameter `size` if the string length is bigger than `size`*/
size_t ft_strnlen(const char *s, size_t size)
{
	size_t l;

	l = 0;

	while(l < size)
	{
		if(!*s)
			break;
		s++;
		l++;
	}
	return(l);
}

size_t ft_strlcat(char *dst, const char *src, size_t size)
{
	/* we need to know the size of each of `src` and `dst` */
	const	size_t slen = ft_strlen(src);
	const	size_t dlen = ft_strnlen(dst, size);
	/* see if we have enough space in dest else return the string's length we tried to create */
	if(dlen == size) return(dlen + slen);
	/* now it is up to the provided param `size` to
	decide if there is enough space for the null byte
	, to understand it better try this in your head:

	- `dst` points to a 7 bytes memory space containing the string "boy\0"
	- `src` points to the string "boy\0"
	now for size try to run it with 6 and afterwards run it with 7 and spot the difference */
	if(slen < size - dlen )
		ft_memcpy(dst+dlen, src, slen + 1);
	else
	{
		ft_memcpy(dst+dlen, src, size - dlen - 1);
		dst[size-1] = 0;
	}
	return dlen + slen;
}

