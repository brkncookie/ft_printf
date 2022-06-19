#include "libft.h"
/* pass the `content` member of the s_list struct to `del()` and free the s_list struct pointed to by `lst` */
void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	del(lst->content);
	free(lst);
}

