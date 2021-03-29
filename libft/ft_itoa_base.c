#include "libft.h"

static int	ft_count_digits(unsigned long long nbr, unsigned int base, int *i)
{
	while (nbr >= base)
	{
		nbr = nbr / base;
		*i += 1;
	}
	return (*i);
}

char		*ft_itoa_base(unsigned long long n, unsigned int base)
{
	char				*out;
	int					i;
	unsigned long long	nbr;

	i = 0;
	nbr = n;
	i = ft_count_digits(nbr, base, &i);
	if (!(out = malloc(sizeof(char) * (i + 1))))
		return (0);
	out[i + 1] = '\0';
	while (n >= base)
	{
		if (n % base < 10)
			out[i--] = (char)(n % base + 48);
		else
			out[i--] = (char)(n % base + 87);
		n = n / base;
	}
	if ((n == 0) || (n % base < 10))
		out[i] = (char)(n % base + 48);
	else
		out[i] = (char)(n % base + 87);
	return (out);
}
