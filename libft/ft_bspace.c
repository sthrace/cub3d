#include "libft.h"

void		ft_bspace(char *s, size_t n)
{
	size_t i;

	if (n == 0)
		return ;
	i = 0;
	while (i < n)
	{
		(s[i]) = ' ';
		i++;
	}
	(s[i]) = '\0';
}
