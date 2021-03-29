#include "../includes/cub3d.h"

static void		ft_select_processor(t_cub *cub, char **line, int *flag)
{
	if (ft_strchr(*line, 'R'))
		ft_resolution(cub, *line, flag);
	else if (((ft_strchr(*line, 'N')) && *(ft_strchr(*line, 'N') + 1) == 'O') ||
			((ft_strchr(*line, 'S')) && *(ft_strchr(*line, 'S') + 1) == 'O') ||
			((ft_strchr(*line, 'E')) && *(ft_strchr(*line, 'E') + 1) == 'A') ||
			((ft_strchr(*line, 'W')) && *(ft_strchr(*line, 'W') + 1) == 'E') ||
			((ft_strchr(*line, 'S')) && *(ft_strchr(*line, 'S') + 1) == ' '))
		ft_texture(cub, *line, flag);
	else if (ft_strchr(*line, 'F') || ft_strchr(*line, 'C'))
		ft_colours(cub, *line, flag);
	else
		exit_cub(cub, 10);
}

static char		*ft_append(t_cub *cub, char *temp, char *line)
{
	char		*joined;
	int			i;
	int			j;

	if (!(joined = (char *)malloc(sizeof(char) * \
	(ft_strlen(temp) + ft_strlen(line) + 2))))
		exit_cub(cub, 31);
	i = 0;
	j = 0;
	while (temp[i])
	{
		joined[i] = temp[i];
		i++;
	}
	while (line[j])
	{
		joined[i] = line[j];
		i++;
		j++;
	}
	joined[i] = '\n';
	joined[i + 1] = '\0';
	free(temp);
	free(line);
	return (joined);
}

static void		ft_tempmap(t_cub *cub, char **line, int *flag)
{
	if (cub->file.map.cols < (int)ft_strlen(*line))
		cub->file.map.cols = (int)ft_strlen(*line);
	if (cub->file.map.tmp == NULL)
		cub->file.map.tmp = ft_strdup("");
	if (*line[0] != '\0')
	{
		cub->file.map.tmp = ft_append(cub, cub->file.map.tmp, *line);
		cub->file.map.rows++;
	}
	else
		exit_cub(cub, 10);
	*flag += 1;
}

static void		ft_readfile(int fd, char *line, t_cub *cub)
{
	int			flag;

	flag = 0;
	while (ft_gnl(fd, &line))
	{
		if (flag < 8 && line[0] != '\0')
			ft_select_processor(cub, &line, &flag);
		else if (line[0] == '\0' && flag <= 8)
		{
			free(line);
			continue;
		}
		else if (flag >= 8 && ((ft_strchr(line, '1')) || ft_strchr(line, ' ')))
			ft_tempmap(cub, &line, &flag);
		else
			exit_cub(cub, 10);
	}
	ft_tempmap(cub, &line, &flag);
	ft_makemap(cub);
	ft_player_position(cub, 0, 0);
}

void			ft_parser(t_cub *cub, char **argv)
{
	int			fd;
	char		*line;

	if ((!(*(ft_strrchr((char *)argv[1], '.') + 1) == 'c')) ||
			(!(*(ft_strrchr((char *)argv[1], '.') + 2) == 'u')) ||
			(!(*(ft_strrchr((char *)argv[1], '.') + 3) == 'b')) ||
			(!(*(ft_strrchr((char *)argv[1], '.') + 4) == '\0')))
		exit_cub(cub, 2);
	line = NULL;
	if ((fd = open(argv[1], O_RDONLY)) < 0)
		exit_cub(cub, 3);
	ft_readfile(fd, line, cub);
	close(fd);
}
