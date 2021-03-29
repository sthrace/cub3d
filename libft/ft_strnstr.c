#include "libft.h"

char		*ft_strnstr(const char *hst, const char *ndl, size_t len)
{
	size_t	i;
	size_t	j;

	if (ndl[0] == '\0')
		return ((char *)hst);
	i = 0;
	while (hst[i] && i < len)
	{
		j = 0;
		while (hst[i + j] == ndl[j] && i + j < len)
		{
			j++;
			if (ndl[j] == '\0')
				return ((char *)hst + i);
		}
		i++;
	}
	return (NULL);
}
