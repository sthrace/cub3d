#include "../includes/cub3d.h"

static void		ft_init_sprites(t_cub *cub, int i)
{
	cub->rcs.spritex = cub->sprite[cub->sprite[i].ord].x - cub->pov.x;
	cub->rcs.spritey = cub->sprite[cub->sprite[i].ord].y - cub->pov.y;
	cub->rcs.invdet = 1.0 / (cub->pov.planex * cub->pov.dir.y - \
	cub->pov.dir.x * cub->pov.planey);
	cub->rcs.transformx = cub->rcs.invdet * (cub->pov.dir.y * \
	cub->rcs.spritex - cub->pov.dir.x * cub->rcs.spritey);
	cub->rcs.transformy = cub->rcs.invdet * (-cub->pov.planey * \
	cub->rcs.spritex + cub->pov.planex * cub->rcs.spritey);
	cub->rcs.screenx = (int)((cub->file.w / 2) * (1 + \
	cub->rcs.transformx / cub->rcs.transformy));
	cub->rcs.h = abs((int)(cub->file.h / cub->rcs.transformy));
	cub->rcs.w = abs((int)(cub->file.h / cub->rcs.transformy));
}

void			ft_rc_sprites(t_cub *cub)
{
	int			i;

	ft_order_sprites(cub, 0);
	ft_sort_sprites(cub);
	i = 0;
	while (i < cub->file.scnt)
	{
		ft_init_sprites(cub, i);
		cub->rcs.drawstarty = -cub->rcs.h / 2 + cub->file.h / 2;
		if (cub->rcs.drawstarty < 0)
			cub->rcs.drawstarty = 0;
		cub->rcs.drawendy = cub->rcs.h / 2 + cub->file.h / 2;
		if (cub->rcs.drawendy >= cub->file.h)
			cub->rcs.drawendy = cub->file.h - 1;
		cub->rcs.drawstartx = -cub->rcs.w / 2 + cub->rcs.screenx;
		if (cub->rcs.drawstartx < 0)
			cub->rcs.drawstartx = 0;
		cub->rcs.drawendx = cub->rcs.w / 2 + cub->rcs.screenx;
		if (cub->rcs.drawendx >= cub->file.w)
			cub->rcs.drawendx = cub->file.w - 1;
		ft_render_sprites(cub, cub->rcs.drawstartx);
		i++;
	}
}
