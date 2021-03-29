#include "libft.h"

t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*item;

	if (!lst)
		return (0);
	new = 0;
	while (lst)
	{
		if (!(item = ft_lstnew(f(lst->content))))
		{
			ft_lstclear(&new, del);
			return (0);
		}
		ft_lstadd_back(&new, item);
		lst = lst->next;
	}
	return (new);
}
