#include "libft.h"

char	*ft_strrchr(const char *str, int ch)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	while (i > 0 && str[i] != ch)
		i--;
	if (str[i] == ch)
		return (char*)(str + i);
	return (0);
}
