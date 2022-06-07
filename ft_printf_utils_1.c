#include "include/ft_printf.h"
char	*ft_str(char *fptr, int	flen, va_list *ap)
{
	return(ft_strdup(va_arg(*ap, char *)));
}

