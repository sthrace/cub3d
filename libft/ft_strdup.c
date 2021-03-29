#include "libft.h"

char		*ft_strdup(const char *s1)
{
	char	*dst;

	if (!(dst = (char *)malloc(ft_strlen(s1) + 1)))
		return (NULL);
	ft_memcpy(dst, s1, ft_strlen(s1) + 1);
	return (dst);
}
