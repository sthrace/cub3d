#include "libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*joined_s;
	int		i;
	int		j;

	if (s1 == 0 && s2 == 0)
		return (NULL);
	if (!(joined_s = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1)))
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		joined_s[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
		joined_s[i++] = s2[j++];
	joined_s[i] = '\0';
	return (joined_s);
}
