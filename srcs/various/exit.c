#include "../includes/cub3d.h"

static void		exit_cub_other(int err)
{
	if (err == 20)
		ft_putendl_fd("Error\nMap array contains invlid character", 1);
	if (err == 21)
		ft_putendl_fd("Error\nMap is not enclosed", 1);
	if (err == 22)
		ft_putendl_fd("Error\nMultiple spawn position", 1);
	if (err == 23)
		ft_putendl_fd("Error\nMissing spawn position", 1);
	if (err == 40)
		ft_putendl_fd("Error\nMinilibX initialization failed", 1);
	if (err == 41)
		ft_putendl_fd("Error\nSought color is out of image array boundary", 1);
	if (err == 42)
		ft_putendl_fd("Error\nMinilibX image initialization failed", 1);
	if (err == 43)
		ft_putendl_fd("Error\nFailed to create BMP file", 1);
	if (err == 44)
		ft_putendl_fd("Error\nFailed to write to BMP file", 1);
	exit(0);
}

static void		exit_cub_malloc(int err)
{
	if (err == 30)
		ft_putendl_fd("Error\nHeap allocation for cub structure failed", 1);
	if (err == 31)
		ft_putendl_fd("Error\nHeap allocation for map failed", 1);
	if (err == 32)
		ft_putendl_fd("Error\nHeap allocation for map element failed", 1);
	if (err == 33)
		ft_putendl_fd("Error\nHeap allocation for zbuffer array failed", 1);
	if (err == 34)
		ft_putendl_fd("Error\nHeap allocation for sprite array failed", 1);
	if (err == 35)
		ft_putendl_fd("Error\nHeap allocation for order array failed", 1);
	if (err == 36)
		ft_putendl_fd("Error\nHeap allocation for distance array failed", 1);
	exit(0);
}

static void		exit_cub_config(int err)
{
	if (err == 10)
		ft_putendl_fd("Error\nInvalid configuration file entry", 1);
	if (err == 11)
		ft_putendl_fd("Error\nResolution double definition", 1);
	if (err == 12)
		ft_putendl_fd("Error\nInvalid resolution format", 1);
	if (err == 13)
		ft_putendl_fd("Error\nColor double definition", 1);
	if (err == 14)
		ft_putendl_fd("Error\nInvalid colour format", 1);
	if (err == 15)
		ft_putendl_fd("Error\nInvalid colour ASCII code", 1);
	if (err == 16)
		ft_putendl_fd("Error\nDuplicate texture path", 1);
	if (err == 17)
		ft_putendl_fd("Error\nInvalid texture path format", 1);
	if (err == 18)
		ft_putendl_fd("Error\nMissing specified texture file", 1);
	exit(0);
}

static void		exit_cub_init(int err)
{
	if (err == 0)
		ft_putendl_fd("Error\nWrong number of arguments", 1);
	if (err == 1)
		ft_putendl_fd("Error\nInvalid argument format", 1);
	if (err == 2)
		ft_putendl_fd("Error\nInvalid map file extension", 1);
	if (err == 3)
		ft_putendl_fd("Error\nInvalid file descriptor", 1);
	exit(0);
}

void			exit_cub(t_cub *cub, int err)
{
	if (err < 10)
		exit_cub_init(err);
	else if (err > 9 && err < 20)
		exit_cub_config(err);
	else if (err > 19 && err < 30)
		exit_cub_other(err);
	else if (err > 29 && err < 40)
		exit_cub_malloc(err);
	else if (err > 39 && err < 50)
		exit_cub_other(err);
	else if (err > 99)
	{
		if (err == 100)
		{
			ft_putendl_fd("Good bye", 1);
			mlx_destroy_image(cub->mlx, cub->img.image);
			mlx_destroy_window(cub->mlx, cub->win);
		}
		else
		{
			ft_putendl_fd("cub3d.bmp created in root directory", 1);
			mlx_destroy_image(cub->mlx, cub->img.image);
		}
		exit(0);
	}
}
