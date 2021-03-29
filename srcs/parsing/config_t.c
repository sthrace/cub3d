#include "../includes/cub3d.h"

static void		ft_select_path(t_cub *cub, char type, char **path)
{
	if (type == 'N')
		cub->file.north = *path;
	else if (type == 'S')
		cub->file.south = *path;
	else if (type == 'W')
		cub->file.west = *path;
	else if (type == 'E')
		cub->file.east = *path;
	else if (type == 'X')
		cub->file.sprite = *path;
	else if (type == 'F')
		cub->file.floor = *path;
	else if (type == 'C')
		cub->file.ceiling = *path;
}

void			ft_save_textures(t_cub *cub, char *line, char type, int i)
{
	char		*path;

	if ((type == 'F' && cub->file.floor != NULL)
	|| (type == 'C' && cub->file.ceiling != NULL))
		exit_cub(cub, 16);
	while (line[i] == ' ')
		i++;
	while (ft_isalpha(line[i]))
		i++;
	while (line[i] == ' ')
		i++;
	path = ft_strdup(&line[i]);
	free(line);
	ft_select_path(cub, type, &path);
	if (path[ft_strlen(path) - 1] != 'm' && path[ft_strlen(path) - 2] != 'p'
	&& path[ft_strlen(path) - 3] != 'x' && path[ft_strlen(path) - 4] != '.')
		exit_cub(cub, 17);
}

void			ft_texture(t_cub *cub, char *line, int *flag)
{
	char		type;

	if (ft_strchr(line, 'N') && *(ft_strchr(line, 'N') + 1) == 'O')
		type = 'N';
	else if (ft_strchr(line, 'S') && *(ft_strchr(line, 'S') + 1) == 'O')
		type = 'S';
	else if (ft_strchr(line, 'W') && *(ft_strchr(line, 'W') + 1) == 'E')
		type = 'W';
	else if (ft_strchr(line, 'E') && *(ft_strchr(line, 'E') + 1) == 'A')
		type = 'E';
	else if (ft_strchr(line, 'S') && *(ft_strchr(line, 'S') + 1) == ' ')
		type = 'X';
	else
		return ;
	if ((type == 'N' && cub->file.north != NULL)
	|| (type == 'S' && cub->file.south != NULL)
	|| (type == 'W' && cub->file.west != NULL)
	|| (type == 'E' && cub->file.east != NULL)
	|| (type == 'X' && cub->file.sprite != NULL))
		exit_cub(cub, 16);
	ft_save_textures(cub, line, type, 0);
	*flag += 1;
}
