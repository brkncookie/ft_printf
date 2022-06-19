#include "libft.h"
/* libbsd/safer version of strncpy */
/* visit https://opensource.apple.com/source/xnu/xnu-4570.1.46/osfmk/arm/strlcpy.c.auto.html */
size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t len;

	len = ft_strlen(src);

	if(len + 1 < size)
		ft_memcpy(dst, src, len + 1);
	else if(size)
	{
		ft_memcpy(dst, src, size - 1);
		dst[size - 1] = 0;
	}
	return (len);
}

