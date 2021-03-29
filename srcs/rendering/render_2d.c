#include "../includes/cub3d.h"

static void		ft_draw_fc(t_cub *cub)
{
	int			x;
	int			y;

	y = -1;
	while (++y <= cub->file.h / 2)
	{
		x = -1;
		while (++x <= cub->file.w)
			ft_mlx_pixel_put(cub, x, y, cub->file.rgb_ceiling);
	}
	y = cub->file.h;
	while (--y >= cub->file.h / 2 - 1)
	{
		x = -1;
		while (++x <= cub->file.w - 1)
			ft_mlx_pixel_put(cub, x, y, cub->file.rgb_floor);
	}
}

static void		ft_shape_2dmap(t_cub *cub, int i, int j, int x)
{
	int			y;
	int			dx;
	int			dy;

	while (cub->file.map.map[++i])
	{
		j = -1;
		while (cub->file.map.map[i][++j])
		{
			dx = cub->drw.scale * j;
			dy = cub->drw.scale * i;
			y = -1;
			while (++y < cub->drw.scale)
			{
				x = -1;
				while (++x < cub->drw.scale)
				{
					if (cub->file.map.map[i][j] == '1')
						ft_mlx_pixel_put(cub, x + dx, y + dy, 0xCCCCCC);
					if (cub->file.map.map[i][j] == '2')
						ft_mlx_pixel_put(cub, x + dx, y + dy, 0xFFFF00);
				}
			}
		}
	}
}

void			ft_render(t_cub *cub, int x, int y)
{
	if (!(cub->img.image = mlx_new_image(cub->mlx, cub->file.w, cub->file.h)))
		exit_cub(cub, 42);
	if (!(cub->img.addr = mlx_get_data_addr(cub->img.image, \
		&cub->img.bits_per_pixel, &cub->img.line_length, &cub->img.endian)))
		exit_cub(cub, 42);
	if (cub->file.floor && cub->file.ceiling)
		ft_rc_floor(cub);
	else
		ft_draw_fc(cub);
	ft_rc_walls(cub);
	ft_rc_sprites(cub);
	if (cub->file.w >= cub->file.map.cols && cub->file.h >= cub->file.map.rows)
		ft_shape_2dmap(cub, -1, -1, -1);
	while (++x < 3)
	{
		y = -1;
		while (++y < 3)
			ft_mlx_pixel_put(cub, roundf(cub->pov.x * cub->drw.scale) + y, \
			roundf(cub->pov.y * cub->drw.scale) + x, 0x00FF00);
	}
	if (cub->file.save)
		ft_save_bmp(cub);
	else
		mlx_put_image_to_window(cub->mlx, cub->win, cub->img.image, 0, 0);
}
