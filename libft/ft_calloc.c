#include "libft.h"
/* a fancy way of doing malloc(nelm*selm)
and zeroing it*/
void	*ft_calloc(size_t nelm, size_t selm)
{
	void	*pt;
	pt = malloc(nelm * selm);
	if(!pt)
		return(NULL);
	ft_bzero(pt, nelm * selm);
	return(pt);
}

