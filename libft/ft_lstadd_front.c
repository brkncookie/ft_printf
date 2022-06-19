#include "libft.h"
/* add the s_list struct pointed to by `new` to the start of a linked list */
void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = lst[0];
	lst[0] = new;
}

