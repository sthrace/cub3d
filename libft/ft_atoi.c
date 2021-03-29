#include "libft.h"

size_t		ft_atoi(const char *str)
{
	int					sign;
	size_t				res;
	int					i;

	i = 0;
	sign = 1;
	res = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		res = (res * 10) + (str[i] - '0');
		i++;
	}
	if (res > 2147483647)
		res = 2147483647;
	if (sign == -1 && res > 2147483648)
		res = 2147483648;
	return (res * sign);
}
