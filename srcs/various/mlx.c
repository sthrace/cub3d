#include "../includes/cub3d.h"

void			ft_mlx_pixel_put(t_cub *cub, int x, int y, unsigned int color)
{
	char		*dst;

	if (!(dst = cub->img.addr + (y * cub->img.line_length + \
	x * (cub->img.bits_per_pixel / 8))))
		exit_cub(cub, 41);
	*(unsigned int*)dst = color;
}

static void		ft_set_scale(t_cub *cub, int x, int y)
{
	if (cub->file.w > x)
		cub->file.w = x;
	if (cub->file.h > y)
		cub->file.h = y;
	cub->drw.scale_w = cub->file.w / (3 * cub->file.map.cols);
	cub->drw.scale_h = cub->file.h / (3 * cub->file.map.rows);
	if (cub->drw.scale_w > cub->drw.scale_h)
		cub->drw.scale = cub->drw.scale_h;
	else
		cub->drw.scale = cub->drw.scale_w;
}

void			ft_mlx_init(t_cub *cub)
{
	int			x;
	int			y;

	if (!(cub->mlx = mlx_init()))
		exit_cub(cub, 40);
	mlx_get_screen_size(cub->mlx, &x, &y);
	ft_set_scale(cub, x, y);
	if (cub->file.save == 0)
		if (!(cub->win = mlx_new_window(cub->mlx, \
			cub->file.w, cub->file.h, "Sthrace cub3d")))
			exit_cub(cub, 40);
	ft_init_textures(cub);
	if (!(cub->rcs.zbuffer = (double *)malloc(sizeof(double) * cub->file.w)))
		exit_cub(cub, 33);
	ft_render(cub, -1, -1);
	mlx_hook(cub->win, 02, 1L << 0, &key_press, cub);
	mlx_hook(cub->win, 03, 1L << 1, &key_release, cub);
	mlx_hook(cub->win, 17, 0L, &button_press, cub);
	mlx_loop_hook(cub->mlx, &ft_movement, cub);
	mlx_loop(cub->mlx);
}
