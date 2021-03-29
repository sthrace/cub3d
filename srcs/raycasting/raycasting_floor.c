#include "../includes/cub3d.h"

static void		ft_init_struct_rcfloor(t_cub *cub, int y)
{
	cub->rcfloor.p = y - cub->file.h / 2;
	cub->rcfloor.posz = 0.5 * cub->file.h;
	cub->rcfloor.rowdistance = cub->rcfloor.posz / cub->rcfloor.p;
	cub->rcfloor.floorstepx = cub->rcfloor.rowdistance * \
	(cub->rcfloor.dir.x1 - cub->rcfloor.dir.x0) / cub->file.w;
	cub->rcfloor.floorstepy = cub->rcfloor.rowdistance * \
	(cub->rcfloor.dir.y1 - cub->rcfloor.dir.y0) / cub->file.w;
	cub->rcfloor.floorx = cub->pov.x + cub->rcfloor.rowdistance * \
	cub->rcfloor.dir.x0;
	cub->rcfloor.floory = cub->pov.y + cub->rcfloor.rowdistance * \
	cub->rcfloor.dir.y0;
}

void			ft_rc_floor(t_cub *cub)
{
	int			y;
	int			x;

	y = 0;
	cub->rcfloor.dir.x0 = cub->pov.dir.x - cub->pov.planex;
	cub->rcfloor.dir.y0 = cub->pov.dir.y - cub->pov.planey;
	cub->rcfloor.dir.x1 = cub->pov.dir.x + cub->pov.planex;
	cub->rcfloor.dir.y1 = cub->pov.dir.y + cub->pov.planey;
	while (y < cub->file.h)
	{
		ft_init_struct_rcfloor(cub, y);
		x = 0;
		while (x < cub->file.w)
		{
			cub->rcfloor.cellx = (int)cub->rcfloor.floorx;
			cub->rcfloor.celly = (int)cub->rcfloor.floory;
			cub->rcfloor.floorx += cub->rcfloor.floorstepx;
			cub->rcfloor.floory += cub->rcfloor.floorstepy;
			ft_render_floor(cub, x, y);
			x++;
		}
		y++;
	}
}
