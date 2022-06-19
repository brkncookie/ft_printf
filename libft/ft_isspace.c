#include "libft.h"
int	ft_isspace(int c)
{
	return((c == 32  || ( c > 8 && c < 14)));
}

