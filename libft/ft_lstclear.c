#include "libft.h"
/* basically  do what ft_lstdelone on each element of the linked list */
void ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list *head;

	while(*lst)
	{
		head = (*lst)->next;
		del((*lst)->content);
		free(*lst);
		*lst = head;
	}
}

