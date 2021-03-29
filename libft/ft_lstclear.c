#include "libft.h"

void		ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list *last;

	if (!*lst)
		return ;
	while (*lst)
	{
		last = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = last;
	}
	*lst = 0;
}
