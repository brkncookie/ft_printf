#include "libft.h"
/* from the successive application of `f()` we creat another linked list and return it */
t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list *old;
	t_list *new;

	old = NULL;
	while(lst)
	{
		new = ft_lstnew(f(lst->content));
		/* if we somehow fail to setup one element of the linked list */
		/* we then let go of the whole linked list */
		if(!new)
		{
			ft_lstclear(&old, del);
			return(NULL);
		}
		ft_lstadd_back(&old, new);
 		lst = lst->next;
		new->next = NULL;
	}

	return(old);
}

