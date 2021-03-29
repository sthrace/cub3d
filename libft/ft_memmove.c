#include "libft.h"

void		*ft_memmove(void *dst, const void *src, size_t n)
{
	size_t	i;

	if ((dst == NULL) && (src == NULL))
		return (NULL);
	i = 0;
	if ((size_t)dst - (size_t)src < n)
	{
		i = n - 1;
		while (i >= 0 && i < n)
		{
			((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
			i--;
		}
	}
	else
		while (i < n)
		{
			((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
			i++;
		}
	return (dst);
}
