#include "../includes/cub3d.h"

static void		ft_set_resolution(t_cub *cub, char *line, int i)
{
	while (line[i] != 'R')
		i++;
	i++;
	while (line[i] == ' ')
		i++;
	cub->file.w = (int)ft_atoi(&line[i]);
	while (line[i] >= '0' && line[i] <= '9')
		i++;
	while (line[i] == ' ')
		i++;
	cub->file.h = (int)ft_atoi(&line[i]);
	while (line[i] >= '0' && line[i] <= '9')
		i++;
	while (line[i] != '\0')
	{
		if (line[i] != ' ')
			exit_cub(cub, 12);
		i++;
	}
	if (cub->file.h == 0 || cub->file.w == 0)
		exit_cub(cub, 12);
}

void			ft_resolution(t_cub *cub, char *line, int *flag)
{
	int			i;

	if (cub->file.w != 0)
		exit_cub(cub, 11);
	i = 0;
	while (line[i] != '\0')
	{
		if (!(ft_isdigit(line[i])) && line[i] != ' ' && line[i] != 'R')
			exit_cub(cub, 12);
		i++;
	}
	ft_set_resolution(cub, line, 0);
	free(line);
	*flag += 1;
}
