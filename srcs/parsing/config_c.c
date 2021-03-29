#include "../includes/cub3d.h"

static void		ft_check_file_format(t_cub *cub, char **color)
{
	int			i;
	int			j;

	i = 0;
	while (++i < 4)
	{
		j = -1;
		while (color[i][++j] != '\0')
		{
			if ((color[i][j] < '0' || color[i][j] > '9')
			&& ft_atoi(color[i]) != 0)
				exit_cub(cub, 16);
		}
	}
	if (ft_atoi(color[0]) > 255 || ft_atoi(color[1]) > 255
	|| ft_atoi(color[2]) > 255)
		exit_cub(cub, 15);
}

static char		**ft_split_file(t_cub *cub, char *line, char **trimmed)
{
	int			i;
	int			cnt;

	i = 0;
	cnt = 0;
	while (line[i] != '\0')
	{
		if (line[i] == ',')
		{
			line[i] = ' ';
			cnt++;
		}
		i++;
	}
	if (cnt != 2)
		exit_cub(cub, 14);
	trimmed = ft_split(line, ' ');
	free(line);
	return (trimmed);
}

static void		ft_no_bonus_fc(t_cub *cub, char *line, char type, int *flag)
{
	char		**trimmed;
	int			r;
	int			g;
	int			b;
	int			cnt;

	trimmed = NULL;
	trimmed = ft_split_file(cub, line, trimmed);
	cnt = 0;
	while (trimmed[cnt])
		cnt++;
	if (cnt != 4)
		exit_cub(cub, 14);
	ft_check_file_format(cub, trimmed);
	r = (int)ft_atoi(trimmed[1]);
	g = (int)ft_atoi(trimmed[2]);
	b = (int)ft_atoi(trimmed[3]);
	while (cnt-- > 0)
		free(trimmed[cnt]);
	free(trimmed);
	if (type == 'F')
		cub->file.rgb_floor = (r << 16 | g << 8 | b);
	else
		cub->file.rgb_ceiling = (r << 16 | g << 8 | b);
	*flag += 1;
}

void			ft_colours(t_cub *cub, char *line, int *flag)
{
	char		type;
	int			len;

	if ((ft_strchr(line, 'F')) && (cub->file.rgb_floor != 0))
		exit_cub(cub, 13);
	if ((ft_strchr(line, 'C')) && (cub->file.rgb_ceiling != 0))
		exit_cub(cub, 13);
	if (ft_strchr(line, 'F'))
		type = 'F';
	else
		type = 'C';
	len = ft_strlen(line);
	if (line[len - 1] == 'm' && line[len - 2] == 'p'
	&& line[len - 3] == 'x' && line[len - 4] == '.')
	{
		ft_save_textures(cub, line, type, 0);
		*flag += 1;
	}
	else
		ft_no_bonus_fc(cub, line, type, flag);
}
