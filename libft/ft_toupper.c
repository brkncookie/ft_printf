#include "libft.h"
/* we use the mere fact that between 'a' and 'A' is 32 */
int	ft_toupper(int c)
{
	if(c > 96 && c < 123)
		return (c - 32);
	return(c);
}

