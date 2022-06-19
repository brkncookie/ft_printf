#include "libft.h"
/* we use the mere fact that between 'a' and 'A' is 32 */
int	ft_tolower(int c)
{
	if(c > 64 && c < 91)
		return (c + 32);
	return(c);
}

