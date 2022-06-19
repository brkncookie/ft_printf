#include "libft.h"

/* output a single character to a file descriptor */

void	ft_putchar_fd(char c, int fd)
{

	write(fd, &c, 1);

}

