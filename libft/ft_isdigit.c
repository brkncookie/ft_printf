#include "libft.h"
int	ft_isdigit(int c)
{
	/* in ascii '0' is 48 and '9' is 57 */
	return((c > 47 && c < 58));
}

