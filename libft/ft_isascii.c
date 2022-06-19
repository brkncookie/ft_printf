#include "libft.h"

int	ft_isascii(int c)
{
	/* the whole ascii range is -1<c<128 */
	return((c > -1 && c < 128));
}

