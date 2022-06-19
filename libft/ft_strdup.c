#include "libft.h"
/* duplicate a string and return the duplicate */
char	*ft_strdup(const char *s)
{
	char *d;

	d = malloc(ft_strlen(s) * sizeof(char) + 1);
	if(!d)
		return(NULL);
	ft_strlcpy(d, s, ft_strlen(s) + 1);
	return(d);
}

