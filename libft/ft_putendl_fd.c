#include "libft.h"
/* output a string ending with '\n' character to a file descriptor */
void	ft_putendl_fd(char *s, int fd)
{
	if(!s)
		return;
	write(fd, s, ft_strlen(s));
	write(fd, "\n", 1);

}

