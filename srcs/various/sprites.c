#include "../includes/cub3d.h"

void			ft_sort_sprites(t_cub *cub)
{
	int			i;
	int			j;
	t_sprite	tmp;

	j = 0;
	while (j < cub->file.scnt - 1)
	{
		i = 0;
		while (i < cub->file.scnt - j - 1)
		{
			if (cub->sprite[i].dist < cub->sprite[i + 1].dist)
			{
				tmp = cub->sprite[i];
				cub->sprite[i] = cub->sprite[i + 1];
				cub->sprite[i + 1] = tmp;
			}
			i++;
		}
		j++;
	}
}

void			ft_order_sprites(t_cub *cub, int i)
{
	while (i < cub->file.scnt)
	{
		cub->sprite[i].ord = i;
		cub->sprite[i].dist = pow(cub->pov.x - \
		cub->sprite[i].x, 2) + pow(cub->pov.y - cub->sprite[i].y, 2);
		i++;
	}
}

void			ft_set_sprites(t_cub *cub, int i, int j)
{
	int			x;

	x = 0;
	if (!(cub->sprite = (t_sprite *)malloc(sizeof(t_sprite) * cub->file.scnt)))
		exit_cub(cub, 34);
	while (i < cub->file.map.rows)
	{
		j = 0;
		while (cub->file.map.map[i][j])
		{
			if (cub->file.map.map[i][j] == '2')
			{
				cub->sprite[x].y = i + 0.5;
				cub->sprite[x].x = j + 0.5;
				x++;
			}
			j++;
		}
		i++;
	}
}
