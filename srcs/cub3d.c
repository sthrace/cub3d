#include "../includes/cub3d.h"

static void		ft_init(t_cub *cub)
{
	cub->mlx = NULL;
	cub->win = NULL;
	cub->img.image = NULL;
	cub->img.addr = NULL;
	cub->rcs.zbuffer = NULL;
	cub->file.north = NULL;
	cub->file.south = NULL;
	cub->file.east = NULL;
	cub->file.west = NULL;
	cub->file.select = NULL;
	cub->file.sprite = NULL;
	cub->file.floor = NULL;
	cub->file.ceiling = NULL;
	cub->file.map.tmp = NULL;
	cub->file.map.map = NULL;
	
	cub->file.save = 0;
	cub->file.w = 0;
	cub->file.rgb_floor = 0;
	cub->file.rgb_ceiling = 0;
	cub->file.map.cols = 0;
	cub->file.map.rows = 0;
}

int				main(int argc, char **argv)
{
	t_cub	*cub;

	if (!(cub = (t_cub *)malloc(sizeof(t_cub))))
		exit_cub(cub, 30);
	if (argc < 2 || argc > 3)
		exit_cub(cub, 0);
	ft_init(cub);
	if (argc == 3)
	{
		if (ft_strlen(argv[2]) == 6 && !ft_strncmp(argv[2], "--save", 6))
			cub->file.save = 1;
		else
			exit_cub(cub, 1);
	}
	ft_parser(cub, argv);
	ft_mlx_init(cub);
	return (0);
}
