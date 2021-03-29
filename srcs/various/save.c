#include "../includes/cub3d.h"

static void		ft_write_rbg2bmp(t_cub *cub)
{
	int			j;
	int			i;
	int			color;

	i = cub->file.h - 1;
	while (i >= 0)
	{
		j = 0;
		while (j < cub->file.w)
		{
			color = *(int*)(cub->img.addr + (cub->img.line_length * i \
			+ j * (cub->img.bits_per_pixel / 8)));
			if ((write(cub->bmp.fd, &color, 4)) != 4)
				exit_cub(cub, 44);
			j++;
		}
		i--;
	}
}

static void		ft_bmp_header(t_cub *cub)
{
	cub->bmp.header[0] = (unsigned char)'B';
	cub->bmp.header[1] = (unsigned char)'M';
	cub->bmp.header[2] = (unsigned char)cub->bmp.size;
	cub->bmp.header[3] = (unsigned char)(cub->bmp.size >> 8);
	cub->bmp.header[4] = (unsigned char)(cub->bmp.size >> 16);
	cub->bmp.header[5] = (unsigned char)(cub->bmp.size >> 24);
	cub->bmp.header[10] = (unsigned char)(54);
	cub->bmp.header[14] = (unsigned char)(40);
	cub->bmp.header[18] = (unsigned char)cub->file.w;
	cub->bmp.header[19] = (unsigned char)(cub->file.w >> 8);
	cub->bmp.header[20] = (unsigned char)(cub->file.w >> 16);
	cub->bmp.header[21] = (unsigned char)(cub->file.w >> 24);
	cub->bmp.header[22] = (unsigned char)cub->file.h;
	cub->bmp.header[23] = (unsigned char)(cub->file.h >> 8);
	cub->bmp.header[24] = (unsigned char)(cub->file.h >> 16);
	cub->bmp.header[25] = (unsigned char)(cub->file.h >> 24);
	cub->bmp.header[26] = (unsigned char)(1);
	cub->bmp.header[28] = (unsigned char)(32);
	if ((write(cub->bmp.fd, &cub->bmp.header, 54)) != 54)
		exit_cub(cub, 44);
	ft_write_rbg2bmp(cub);
}

void			ft_save_bmp(t_cub *cub)
{
	int			i;

	cub->bmp.size = 54 + ((cub->img.bits_per_pixel / 8) \
	* cub->file.w * cub->file.h);
	i = -1;
	while (i++ < 54)
		cub->bmp.header[i] = (unsigned char)(0);
	if ((cub->bmp.fd = open("cub3D.bmp", O_WRONLY | O_CREAT \
	| O_TRUNC, 0777)) < 0)
		exit_cub(cub, 43);
	ft_bmp_header(cub);
	close(cub->bmp.fd);
	exit_cub(cub, 101);
}
