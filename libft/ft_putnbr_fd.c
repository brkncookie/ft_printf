#include "libft.h"
/* output a number to a file descriptor */
void	ft_putnbr_fd(int n, int fd)
{
	char *nm;

	nm = ft_itoa(n);
	write(fd, nm, ft_strlen(nm));
}

