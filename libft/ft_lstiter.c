#include "libft.h"
/* iterate through the linked list and apply `f()` to each of the element's content */
void ft_lstiter(t_list *lst, void (*f)(void *))
{
	while(lst)
	{
		f(lst->content);
		lst = lst->next;
	}

}

