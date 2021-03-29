#include "../includes/cub3d.h"

static void		ft_dda(t_cub *cub)
{
	cub->rcwalls.hit = 0;
	while (cub->rcwalls.hit == 0)
	{
		if (cub->rcwalls.sidedistx < cub->rcwalls.sidedisty)
		{
			cub->rcwalls.sidedistx += cub->rcwalls.deltax;
			cub->rcwalls.map_j += cub->rcwalls.stepx;
			cub->rcwalls.side = 0;
		}
		else
		{
			cub->rcwalls.sidedisty += cub->rcwalls.deltay;
			cub->rcwalls.map_i += cub->rcwalls.stepy;
			cub->rcwalls.side = 1;
		}
		if (cub->file.map.map[cub->rcwalls.map_i][cub->rcwalls.map_j] == '1')
			cub->rcwalls.hit = 1;
	}
	if (cub->rcwalls.side == 0)
		cub->rcwalls.perpwalldist = (cub->rcwalls.map_j - cub->pov.x + \
		(1 - cub->rcwalls.stepx) / 2) / cub->rcwalls.dir.x;
	else
		cub->rcwalls.perpwalldist = (cub->rcwalls.map_i - cub->pov.y + \
		(1 - cub->rcwalls.stepy) / 2) / cub->rcwalls.dir.y;
}

static void		ft_calculate_steps(t_cub *cub)
{
	if (cub->rcwalls.dir.x < 0)
	{
		cub->rcwalls.stepx = -1;
		cub->rcwalls.sidedistx = (cub->pov.x - cub->rcwalls.map_j) * \
		cub->rcwalls.deltax;
	}
	else
	{
		cub->rcwalls.stepx = 1;
		cub->rcwalls.sidedistx = (cub->rcwalls.map_j + 1.0 - cub->pov.x) * \
		cub->rcwalls.deltax;
	}
	if (cub->rcwalls.dir.y < 0)
	{
		cub->rcwalls.stepy = -1;
		cub->rcwalls.sidedisty = (cub->pov.y - cub->rcwalls.map_i) * \
		cub->rcwalls.deltay;
	}
	else
	{
		cub->rcwalls.stepy = 1;
		cub->rcwalls.sidedisty = (cub->rcwalls.map_i + 1.0 - cub->pov.y) * \
		cub->rcwalls.deltay;
	}
}

static void		ft_init_rcwallsstruct(t_cub *cub, int x)
{
	cub->rcwalls.camerax = 2 * x / (double)cub->file.w - 1;
	cub->rcwalls.dir.x = cub->pov.dir.x + cub->pov.planex * \
	cub->rcwalls.camerax;
	cub->rcwalls.dir.y = cub->pov.dir.y + cub->pov.planey * \
	cub->rcwalls.camerax;
	cub->rcwalls.deltax = fabs(1 / cub->rcwalls.dir.x);
	cub->rcwalls.deltay = fabs(1 / cub->rcwalls.dir.y);
	cub->rcwalls.map_i = (int)cub->pov.y;
	cub->rcwalls.map_j = (int)cub->pov.x;
}

void			ft_rc_walls(t_cub *cub)
{
	int			x;

	x = 0;
	while (x < cub->file.w)
	{
		ft_init_rcwallsstruct(cub, x);
		ft_calculate_steps(cub);
		ft_dda(cub);
		ft_render_walls(cub, x);
		cub->rcs.zbuffer[x] = cub->rcwalls.perpwalldist;
		x++;
	}
}
