#include "libft.h"

int	ft_isalpha(int c)
{
	/* in ascii 'A' is 65, 'Z' is 90 and 'a' is 97, 'z' is 122 */
	return((c > 96 && c < 123) || (c > 64 && c < 91));
}

