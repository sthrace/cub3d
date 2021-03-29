#include "libft.h"

static int	ft_nbrlen(unsigned int n)
{
	unsigned int	len;

	len = 1;
	while (n >= 10)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char		*ft_itoa(int n)
{
	char			*out;
	unsigned int	nbr;
	unsigned int	dgt;
	int				i;

	if (n < 0)
		nbr = (unsigned int)(n * -1);
	else
		nbr = (unsigned int)n;
	dgt = ft_nbrlen(nbr);
	i = 0;
	if (!(out = (char *)malloc(sizeof(char) * (dgt + 1 + (n < 0 ? 1 : 0)))))
		return (NULL);
	if (n < 0 && (out[i] = '-'))
		dgt++;
	i = dgt - 1;
	while (nbr >= 10)
	{
		out[i--] = (char)(nbr % 10 + 48);
		nbr = nbr / 10;
	}
	out[i] = (char)(nbr % 10 + 48);
	out[dgt] = '\0';
	return (out);
}
