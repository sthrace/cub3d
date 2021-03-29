#include "../includes/cub3d.h"

static void		ft_rotate_leftright(t_cub *cub, float rt)
{
	if (cub->mv.rotleft == 1)
	{
		cub->pov.dir.oldx = cub->pov.dir.x;
		cub->pov.dir.x = cub->pov.dir.x * cos(-rt) - cub->pov.dir.y * sin(-rt);
		cub->pov.dir.y = cub->pov.dir.oldx * sin(-rt) + \
		cub->pov.dir.y * cos(-rt);
		cub->pov.oldplanex = cub->pov.planex;
		cub->pov.planex = cub->pov.planex * cos(-rt) - \
		cub->pov.planey * sin(-rt);
		cub->pov.planey = cub->pov.oldplanex * sin(-rt) + \
		cub->pov.planey * cos(-rt);
	}
	if (cub->mv.rotright == 1)
	{
		cub->pov.dir.oldx = cub->pov.dir.x;
		cub->pov.dir.x = cub->pov.dir.x * cos(rt) - cub->pov.dir.y * sin(rt);
		cub->pov.dir.y = cub->pov.dir.oldx * sin(rt) + \
		cub->pov.dir.y * cos(rt);
		cub->pov.oldplanex = cub->pov.planex;
		cub->pov.planex = cub->pov.planex * cos(rt) - cub->pov.planey * sin(rt);
		cub->pov.planey = cub->pov.oldplanex * sin(rt) + \
		cub->pov.planey * cos(rt);
	}
	ft_render(cub, -1, -1);
}

static void		ft_move_leftright(t_cub *cub, float mv)
{
	if (cub->mv.left == 1)
	{
		if (cub->file.map.map[(int)(cub->pov.y - cub->pov.dir.x * \
			mv)][(int)(cub->pov.x)] != '1' &&
			cub->file.map.map[(int)(cub->pov.y - cub->pov.dir.x * \
			mv)][(int)(cub->pov.x)] != '2')
			cub->pov.y -= cub->pov.dir.x * mv;
		if (cub->file.map.map[(int)(cub->pov.y)][(int)(cub->pov.x + \
			cub->pov.dir.y * mv)] != '1' &&
			cub->file.map.map[(int)(cub->pov.y)][(int)(cub->pov.x + \
			cub->pov.dir.y * mv)] != '2')
			cub->pov.x += cub->pov.dir.y * mv;
	}
	if (cub->mv.right == 1)
	{
		if (cub->file.map.map[(int)(cub->pov.y + cub->pov.dir.x * mv)]\
		[(int)(cub->pov.x)] != '1' && cub->file.map.map[(int)(cub->pov.y + \
		cub->pov.dir.x * mv)][(int)(cub->pov.x)] != '2')
			cub->pov.y += cub->pov.dir.x * mv;
		if (cub->file.map.map[(int)(cub->pov.y)][(int)(cub->pov.x - \
		cub->pov.dir.y * mv)] != '1' && cub->file.map.map[(int)\
		(cub->pov.y)][(int)(cub->pov.x - cub->pov.dir.y * mv)] != '2')
			cub->pov.x -= cub->pov.dir.y * mv;
	}
	ft_render(cub, -1, -1);
}

static void		ft_move_updown(t_cub *cub, float mv)
{
	if (cub->mv.up == 1)
	{
		if (cub->file.map.map[(int)(cub->pov.y + cub->pov.dir.y * mv)]\
			[(int)(cub->pov.x)] != '1' && cub->file.map.map[(int)\
			(cub->pov.y + cub->pov.dir.y * mv)][(int)(cub->pov.x)] != '2')
			cub->pov.y += cub->pov.dir.y * mv;
		if (cub->file.map.map[(int)(cub->pov.y)][(int)(cub->pov.x + \
			cub->pov.dir.x * mv)] != '1' &&
			cub->file.map.map[(int)(cub->pov.y)][(int)(cub->pov.x + \
			cub->pov.dir.x * mv)] != '2')
			cub->pov.x += cub->pov.dir.x * mv;
	}
	else if (cub->mv.down == 1)
	{
		if (cub->file.map.map[(int)(cub->pov.y - cub->pov.dir.y * \
			mv)][(int)(cub->pov.x)] != '1' && cub->file.map.map[(int)\
			(cub->pov.y - cub->pov.dir.y * mv)][(int)(cub->pov.x)] != '2')
			cub->pov.y -= cub->pov.dir.y * mv;
		if (cub->file.map.map[(int)(cub->pov.y)][(int)(cub->pov.x - \
			cub->pov.dir.x * mv)] != '1' &&
			cub->file.map.map[(int)(cub->pov.y)][(int)(cub->pov.x - \
			cub->pov.dir.x * mv)] != '2')
			cub->pov.x -= cub->pov.dir.x * mv;
	}
	ft_render(cub, -1, -1);
}

int				ft_movement(t_cub *cub)
{
	float		rt;
	float		mv;

	rt = 0.1;
	mv = 0.1;
	if (cub->mv.up == 1 || cub->mv.down == 1)
		ft_move_updown(cub, mv);
	if (cub->mv.left == 1 || cub->mv.right == 1)
		ft_move_leftright(cub, mv);
	if (cub->mv.rotleft == 1 || cub->mv.rotright == 1)
		ft_rotate_leftright(cub, rt);
	return (0);
}
