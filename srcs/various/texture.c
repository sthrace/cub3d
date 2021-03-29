#include "../includes/cub3d.h"

void			ft_select_texture(t_cub *cub)
{
	if (cub->rcwalls.side == 0 && cub->rcwalls.dir.x > 0)
		cub->select = cub->east;
	if (cub->rcwalls.side == 0 && cub->rcwalls.dir.x < 0)
		cub->select = cub->west;
	if (cub->rcwalls.side == 1 && cub->rcwalls.dir.y > 0)
		cub->select = cub->south;
	if (cub->rcwalls.side == 1 && cub->rcwalls.dir.y < 0)
		cub->select = cub->north;
}

static void		ft_init_sfc_textures(t_cub *cub)
{
	if (!(cub->sprimg.image = mlx_xpm_file_to_image(cub->mlx, \
	cub->file.sprite, &cub->sprimg.width, &cub->sprimg.height)))
		exit_cub(cub, 18);
	cub->sprimg.addr = mlx_get_data_addr(cub->sprimg.image, \
	&cub->sprimg.bits_per_pixel, &cub->sprimg.line_length, \
	&cub->sprimg.endian);
	if (cub->file.floor != NULL && cub->file.ceiling != NULL)
	{
		if (!(cub->floor.image = mlx_xpm_file_to_image(cub->mlx, \
		cub->file.floor, &cub->floor.width, &cub->floor.height)))
			exit_cub(cub, 18);
		cub->floor.addr = mlx_get_data_addr(cub->floor.image, \
		&cub->floor.bits_per_pixel, &cub->floor.line_length, \
		&cub->floor.endian);
		if (!(cub->ceiling.image = mlx_xpm_file_to_image(cub->mlx, \
		cub->file.ceiling, &cub->ceiling.width, &cub->ceiling.height)))
			exit_cub(cub, 18);
		cub->ceiling.addr = mlx_get_data_addr(cub->ceiling.image, \
		&cub->ceiling.bits_per_pixel, &cub->ceiling.line_length, \
		&cub->ceiling.endian);
	}
}

void			ft_init_textures(t_cub *cub)
{
	if (!(cub->south.image = mlx_xpm_file_to_image(cub->mlx, cub->file.south, \
					&cub->south.width, &cub->south.height)))
		exit_cub(cub, 18);
	cub->south.addr = mlx_get_data_addr(cub->south.image, \
	&cub->south.bits_per_pixel, &cub->south.line_length, &cub->south.endian);
	if (!(cub->north.image = mlx_xpm_file_to_image(cub->mlx, cub->file.north, \
		&cub->north.width, &cub->north.height)))
		exit_cub(cub, 18);
	cub->north.addr = mlx_get_data_addr(cub->north.image, \
	&cub->north.bits_per_pixel, &cub->north.line_length, &cub->north.endian);
	if (!(cub->east.image = mlx_xpm_file_to_image(cub->mlx, cub->file.east, \
					&cub->east.width, &cub->east.height)))
		exit_cub(cub, 18);
	cub->east.addr = mlx_get_data_addr(cub->east.image, \
	&cub->east.bits_per_pixel, &cub->east.line_length, &cub->east.endian);
	if (!(cub->west.image = mlx_xpm_file_to_image(cub->mlx, cub->file.west, \
					&cub->west.width, &cub->west.height)))
		exit_cub(cub, 18);
	cub->west.addr = mlx_get_data_addr(cub->west.image, \
	&cub->west.bits_per_pixel, &cub->west.line_length, &cub->west.endian);
	ft_init_sfc_textures(cub);
}
