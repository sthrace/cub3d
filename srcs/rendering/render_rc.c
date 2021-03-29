#include "../includes/cub3d.h"

void			ft_render_sprites(t_cub *cub, int x)
{
	int		y;

	while (x < cub->rcs.drawendx)
	{
		cub->rcs.texx = (int)(256 * (x - (-cub->rcs.w / 2 + \
		cub->rcs.screenx)) * cub->sprimg.width / cub->rcs.w) / 256;
		if (cub->rcs.transformy > 0 && x > 0 && x < cub->file.w && \
		cub->rcs.transformy < cub->rcs.zbuffer[x])
		{
			y = cub->rcs.drawstarty;
			while (y < cub->rcs.drawendy)
			{
				cub->rcs.d = y * 256 - cub->file.h * 128 + cub->rcs.h * 128;
				cub->rcs.texy = ((cub->rcs.d * cub->sprimg.height) / \
				cub->rcs.h) / 256;
				cub->drw.color = *(unsigned int*)(cub->sprimg.addr + \
				(cub->rcs.texy * cub->sprimg.line_length + cub->rcs.texx * \
				(cub->sprimg.bits_per_pixel / 8)));
				if ((cub->drw.color & 0x00FFFFFF) != 0)
					ft_mlx_pixel_put(cub, x, y, cub->drw.color);
				y++;
			}
		}
		x++;
	}
}

void			ft_render_floor(t_cub *cub, int x, int y)
{
	if (y < cub->file.h / 2)
	{
		cub->rcfloor.tx = (int)(cub->ceiling.width * (cub->rcfloor.floorx - \
		cub->rcfloor.cellx)) & (cub->floor.width - 1);
		cub->rcfloor.ty = (int)(cub->ceiling.height * (cub->rcfloor.floory - \
		cub->rcfloor.celly)) & (cub->floor.height - 1);
		cub->drw.color = *(unsigned int*)(cub->ceiling.addr + \
		(cub->rcfloor.ty * cub->ceiling.line_length + cub->rcfloor.tx * \
		(cub->ceiling.bits_per_pixel / 8)));
		ft_mlx_pixel_put(cub, x, y, cub->drw.color);
	}
	else
	{
		cub->rcfloor.tx = (int)(cub->floor.width * (cub->rcfloor.floorx - \
		cub->rcfloor.cellx)) & (cub->floor.width - 1);
		cub->rcfloor.ty = (int)(cub->floor.height * (cub->rcfloor.floory - \
		cub->rcfloor.celly)) & (cub->floor.height - 1);
		cub->drw.color = *(unsigned int*)(cub->floor.addr + (cub->rcfloor.ty * \
		cub->floor.line_length + cub->rcfloor.tx * \
		(cub->floor.bits_per_pixel / 8)));
		ft_mlx_pixel_put(cub, x, y, cub->drw.color);
	}
}

static void		ft_paint_walls(t_cub *cub, int x)
{
	if (cub->rcwalls.side == 0)
		cub->rcwalls.wall_x = cub->pov.y + \
		cub->rcwalls.perpwalldist * cub->rcwalls.dir.y;
	else
		cub->rcwalls.wall_x = cub->pov.x + \
		cub->rcwalls.perpwalldist * cub->rcwalls.dir.x;
	cub->rcwalls.wall_x -= floor(cub->rcwalls.wall_x);
	cub->drw.tex_x = (int)(cub->rcwalls.wall_x * (double)(cub->select.width));
	if (cub->rcwalls.side == 0 && cub->rcwalls.dir.x > 0)
		cub->drw.tex_x = cub->select.width - cub->drw.tex_x - 1;
	if (cub->rcwalls.side == 1 && cub->rcwalls.dir.y < 0)
		cub->drw.tex_x = cub->select.width - cub->drw.tex_x - 1;
	cub->drw.step = (double)cub->select.height / (double)cub->drw.line_height;
	cub->drw.texpos = (cub->drw.start - cub->file.h / 2 + \
	cub->drw.line_height / 2) * cub->drw.step;
	while (cub->drw.start < cub->drw.end)
	{
		cub->drw.tex_y = (int)cub->drw.texpos & (cub->select.height - 1);
		cub->drw.color = *(unsigned int*)(cub->select.addr + (cub->drw.tex_y * \
		cub->select.line_length + cub->drw.tex_x * \
		(cub->select.bits_per_pixel / 8)));
		ft_mlx_pixel_put(cub, x, cub->drw.start, cub->drw.color);
		cub->drw.texpos += cub->drw.step;
		cub->drw.start++;
	}
}

void			ft_render_walls(t_cub *cub, int x)
{
	cub->drw.line_height = (int)(cub->file.h / cub->rcwalls.perpwalldist);
	cub->drw.start = -cub->drw.line_height / 2 + cub->file.h / 2;
	if (cub->drw.start < 0)
		cub->drw.start = 0;
	cub->drw.end = cub->drw.line_height / 2 + cub->file.h / 2;
	if (cub->drw.end >= cub->file.h)
		cub->drw.end = cub->file.h - 1;
	ft_select_texture(cub);
	ft_paint_walls(cub, x);
}
