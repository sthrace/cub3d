#include "libft.h"

static size_t	ft_wdcnt(char const *s, char c)
{
	size_t		wdcnt;
	size_t		i;

	wdcnt = 0;
	i = 0;
	while (s[i] && s[i] != '\0')
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
		{
			wdcnt++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (wdcnt);
}

static size_t	ft_len(char const *s, char c)
{
	size_t		i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static void		ft_free(char **s, int c)
{
	while (c)
	{
		free(s[c]);
		c--;
	}
	free(s);
}

static char		*ft_strsplit(char const *s, char c)
{
	size_t		i;
	size_t		j;
	char		*splitstr;

	i = 0;
	j = 0;
	if (!(splitstr = (char *)malloc(sizeof(char *) * (ft_len(s, c) + 1))))
		return (NULL);
	while (s[i] && s[i] != c)
		splitstr[j++] = s[i++];
	splitstr[j] = '\0';
	return (splitstr);
}

char			**ft_split(char const *s, char c)
{
	size_t		i;
	size_t		wdcnt;
	char		**split;

	i = 0;
	if (!s)
		return (NULL);
	wdcnt = ft_wdcnt(s, c);
	if (!(split = (char **)malloc(sizeof(char **) * wdcnt + 1)))
		return (NULL);
	while (i < wdcnt)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
		{
			if (!(split[i] = ft_strsplit(s, c)))
				ft_free(split, i - 1);
			i++;
			while (*s && *s != c)
				s++;
		}
	}
	split[i] = NULL;
	return (split);
}
