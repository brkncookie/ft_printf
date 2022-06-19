#include "libft.h"
/* return an int from the digits that apppears in the string pointed in nptr */
int	ft_atoi(const char *nptr)
{
	long long sgn;
	long long sum;

	sum = 0;
	sgn = 1;
	while(ft_isspace(*nptr))
		nptr++;
	if(*nptr == '-' || *nptr == '+')
	{
		if(*nptr == '-')
			sgn *= -1;
		nptr++;
	}
	while(ft_isdigit(*nptr))
	{
		sum = sum * 10 + *nptr - 48;
		nptr++;
	}
	return(sum * sgn);
}

