#include "libft.h"

static char		*ft_charjoin(char *line, char c)
{
	char		*joined;
	int			i;

	i = 0;
	while (line[i])
		i++;
	joined = (char *)malloc(i + 2);
	i = 0;
	while (line[i])
	{
		joined[i] = line[i];
		i++;
	}
	joined[i] = c;
	joined[i + 1] = '\0';
	free(line);
	return (joined);
}

int				ft_gnl(int fd, char **line)
{
	char		buff;
	int			value;

	if (!(*line = (char *)malloc(1)) || !fd || !(*line))
		return (-1);
	*line[0] = '\0';
	while ((value = read(fd, &buff, 1)) > 0)
	{
		if (buff == '\n')
			break ;
		*line = ft_charjoin(*line, buff);
	}
	return (value);
}
