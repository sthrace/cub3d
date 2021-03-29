#include "libft.h"

void		*ft_calloc(size_t count, size_t size)
{
	void	*res;

	res = malloc(count * size);
	if (res)
		return (ft_memset(res, 0, count * size));
	return (0);
}
