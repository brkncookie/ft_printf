#include "libft.h"
/* output a string to a file descriptor */
void	ft_putstr_fd(char *s, int fd)
{
	if(!s)
		return;
	write(fd, s, ft_strlen(s));

}

