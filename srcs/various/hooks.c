#include "../includes/cub3d.h"

int			button_press(t_cub *cub)
{
	exit_cub(cub, 100);
	return (0);
}

int			key_release(int keycode, t_cub *cub)
{
	if (keycode == W)
		cub->mv.up = 0;
	if (keycode == S)
		cub->mv.down = 0;
	if (keycode == A)
		cub->mv.left = 0;
	if (keycode == D)
		cub->mv.right = 0;
	if (keycode == LEFT)
		cub->mv.rotleft = 0;
	if (keycode == RIGHT)
		cub->mv.rotright = 0;
	return (0);
}

int			key_press(int keycode, t_cub *cub)
{
	if (keycode == W)
		cub->mv.up = 1;
	if (keycode == S)
		cub->mv.down = 1;
	if (keycode == A)
		cub->mv.left = 1;
	if (keycode == D)
		cub->mv.right = 1;
	if (keycode == LEFT)
		cub->mv.rotleft = 1;
	if (keycode == RIGHT)
		cub->mv.rotright = 1;
	if (keycode == ESC)
		exit_cub(cub, 100);
	return (0);
}
