#include "../includes/cub3d.h"

static void		ft_player_direction(t_cub *cub, int i, int j)
{
	if (cub->file.map.map[i][j] == 'N')
	{
		cub->pov.dir.x = 0;
		cub->pov.dir.y = -1;
	}
	if (cub->file.map.map[i][j] == 'S')
	{
		cub->pov.dir.x = 0;
		cub->pov.dir.y = 1;
	}
	if (cub->file.map.map[i][j] == 'W')
	{
		cub->pov.dir.x = -1;
		cub->pov.dir.y = 0;
	}
	if (cub->file.map.map[i][j] == 'E')
	{
		cub->pov.dir.x = 1;
		cub->pov.dir.y = 0;
	}
	cub->pov.planex = cub->pov.dir.y * -0.66;
	cub->pov.planey = cub->pov.dir.x * 0.66;
}

void			ft_player_position(t_cub *cub, int i, int j)
{
	while (i < cub->file.map.rows)
	{
		j = 0;
		while (cub->file.map.map[i][j])
		{
			if ((cub->file.map.map[i][j] == 'N')
			|| (cub->file.map.map[i][j] == 'S')
			|| (cub->file.map.map[i][j] == 'W')
			|| (cub->file.map.map[i][j] == 'E'))
			{
				cub->pov.x = j + 0.5;
				cub->pov.y = i + 0.5;
				ft_player_direction(cub, i, j);
				cub->file.map.map[i][j] = '0';
			}
			j++;
		}
		i++;
	}
}
