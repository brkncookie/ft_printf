#include "libft.h"
/* get the last element of the linked list */
t_list	*ft_lstlast(t_list *lst)
{
	while(lst)
	{
		if(!lst->next)
			return(lst);
		lst = lst->next;
	}
	return(NULL);
}

