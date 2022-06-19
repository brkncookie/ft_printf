#include "libft.h"
/* allocate memory for the s_list struct with a member of the struct pointing to `content` */
t_list	*ft_lstnew(void *content)
{
	t_list	*lst;

	lst = ft_calloc(1, sizeof(t_list));
	if(!lst)
		return NULL;
	lst->content = content;
	lst->next = NULL;
	return(lst);
}

