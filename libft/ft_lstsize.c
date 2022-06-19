#include "libft.h"
/* calculate how many  elements are in a linked list */
int	ft_lstsize(t_list *lst)
{
	int	sze;

	sze = 0;
	while(lst)
	{
		lst = lst->next;
		sze++;
	}
	return(sze);
}

