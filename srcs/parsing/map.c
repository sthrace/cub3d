#include "../includes/cub3d.h"

static void		ft_check_spawn(t_cub *cub, int i, int j)
{
	int		flag;

	flag = 0;
	while (++i < cub->file.map.rows)
	{
		j = -1;
		while (cub->file.map.map[i][++j] != '\0')
		{
			if ((cub->file.map.map[i][j] == 'N')
			|| (cub->file.map.map[i][j] == 'E')
			|| (cub->file.map.map[i][j] == 'S')
			|| (cub->file.map.map[i][j] == 'W'))
				flag++;
			if (flag == 2)
				exit_cub(cub, 22);
		}
	}
	if (flag == 0)
		exit_cub(cub, 23);
}

static void		ft_check_enclosure(t_cub *cub, int i, int j)
{
	while (++i < cub->file.map.rows)
	{
		j = -1;
		while (cub->file.map.map[i][++j] != '\0')
		{
			if ((ft_strchr("0NSWE2", cub->file.map.map[i][j])))
			{
				if (((int)ft_strlen(cub->file.map.map[i - 1]) < j - 1)
				|| ((cub->file.map.map[i - 1][j])
				&& cub->file.map.map[i - 1][j] == ' '))
					exit_cub(cub, 21);
				if (((int)ft_strlen(cub->file.map.map[i + 1]) < j - 1)
				|| ((cub->file.map.map[i + 1][j])
				&& cub->file.map.map[i + 1][j] == ' '))
					exit_cub(cub, 21);
				if (j == 0 || (j > 0 && cub->file.map.map[i][j - 1] == ' '))
					exit_cub(cub, 21);
				if (cub->file.map.map[i][j + 1] == '\0'
				|| cub->file.map.map[i][j + 1] == ' ')
					exit_cub(cub, 21);
			}
		}
	}
}

static void		ft_validate_map(t_cub *cub, int i)
{
	int			j;

	while (++i < cub->file.map.rows)
	{
		j = 0;
		while (cub->file.map.map[i][j] != '\0')
		{
			if ((cub->file.map.map[i][j] != '1')
			&& (cub->file.map.map[i][j] != '0')
			&& (cub->file.map.map[i][j] != '2')
			&& (cub->file.map.map[i][j] != 'N')
			&& (cub->file.map.map[i][j] != 'S')
			&& (cub->file.map.map[i][j] != 'E')
			&& (cub->file.map.map[i][j] != 'W')
			&& (cub->file.map.map[i][j] != ' '))
				exit_cub(cub, 20);
			if (cub->file.map.map[i][j] == '2')
				cub->file.scnt++;
			j++;
		}
	}
	ft_check_enclosure(cub, -1, -1);
	ft_check_spawn(cub, 0, 0);
	ft_set_sprites(cub, 0, 0);
}

void			ft_makemap(t_cub *cub)
{
	if (!(cub->file.map.map = ft_split(cub->file.map.tmp, '\n')))
		exit_cub(cub, 32);
	free(cub->file.map.tmp);
	ft_validate_map(cub, -1);
}
