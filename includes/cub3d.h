#ifndef CUB3D_H
# define CUB3D_H

# define W 13
# define S 1
# define D 2
# define A 0
# define RIGHT 124
# define LEFT 123
# define ESC 53

# include "../minilibx_mac/mlx.h"
# include "../libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <fcntl.h>
# include <stdio.h>

typedef struct		s_map
{
	char			**map;
	char			*tmp;
	int				rows;
	int				cols;
}					t_map;

typedef struct		s_file
{
	int				w;
	int				h;
	int				rgb_floor;
	int				rgb_ceiling;
	t_map			map;
	char			*north;
	char			*south;
	char			*east;
	char			*west;
	char			*select;
	char			*sprite;
	char			*floor;
	char			*ceiling;
	int				scnt;
	int				save;
}					t_file;

typedef struct		s_draw
{
	int				line_height;
	int				endian;
	int				start;
	int				end;
	int				tex_x;
	int				tex_y;
	double			step;
	double			texpos;
	unsigned int	color;
	int				scale_w;
	int				scale_h;
	int				scale;
}					t_draw;

typedef struct		s_dir
{
	double			x;
	double			y;
	double			x0;
	double			y0;
	double			x1;
	double			y1;
	double			oldx;
}					t_dir;

typedef struct		s_rcw
{
	t_dir			dir;
	double			camerax;
	double			deltax;
	double			deltay;
	int				map_i;
	int				map_j;
	double			sidedistx;
	double			sidedisty;
	double			perpwalldist;
	int				stepx;
	int				stepy;
	int				hit;
	int				side;
	double			wall_x;
}					t_rcw;

typedef struct		s_rcf
{
	t_dir			dir;
	int				p;
	double			posz;
	double			rowdistance;
	double			floorstepx;
	double			floorstepy;
	double			floorx;
	double			floory;
	int				cellx;
	int				celly;
	int				tx;
	int				ty;
}					t_rcf;

typedef struct		s_sprite
{
	double			x;
	double			y;
	int				ord;
	double			dist;
}					t_sprite;

typedef struct		s_rcs
{
	double			x;
	double			y;
	double			*zbuffer;
	double			spritex;
	double			spritey;
	double			invdet;
	double			transformx;
	double			transformy;
	int				screenx;
	int				h;
	int				drawstarty;
	int				drawendy;
	int				w;
	int				drawstartx;
	int				drawendx;
	int				texx;
	int				texy;
	int				d;
}					t_rcs;

typedef struct		s_pov
{
	double			x;
	double			y;
	double			planex;
	double			planey;
	double			oldplanex;
	t_dir			dir;
}					t_pov;

typedef struct		s_movement
{
	int				up;
	int				down;
	int				left;
	int				right;
	int				rotleft;
	int				rotright;
}					t_movement;

typedef struct		s_image
{
	void			*image;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	int				width;
	int				height;
}					t_image;

typedef struct		s_bmps
{
	unsigned char	header[54];
	int				size;
	int				fd;
	int				color;
}					t_bmp;

typedef struct		s_cub
{
	void			*mlx;
	void			*win;
	t_file			file;
	t_draw			drw;
	t_rcw			rcwalls;
	t_rcf			rcfloor;
	t_rcs			rcs;
	t_pov			pov;
	t_movement		mv;
	t_image			img;
	t_image			north;
	t_image			south;
	t_image			west;
	t_image			east;
	t_image			select;
	t_image			floor;
	t_image			ceiling;
	t_image			sprimg;
	t_sprite		*sprite;
	t_bmp			bmp;
}					t_cub;

void				ft_parser(t_cub *cub, char **argv);
void				exit_cub(t_cub *cub, int err);
void				ft_mlx_init(t_cub *cub);
void				ft_makemap(t_cub *cub);
void				ft_colours(t_cub *cub, char *line, int *flag);
void				ft_texture(t_cub *cub, char *line, int *flag);
void				ft_resolution(t_cub *cub, char *line, int *flag);
void				ft_render(t_cub *cub, int x, int y);
void				ft_player_position(t_cub *cub, int i, int j);
void				ft_mlx_pixel_put(t_cub *cub, int x, int y, unsigned int c);
void				ft_render_2d(t_cub *cub, int x, int y, int i, int j);
int					ft_movement(t_cub *cub);
void				ft_rc_walls(t_cub *cub);
void				ft_render_walls(t_cub *cub, int x);
void				ft_init_textures(t_cub *cub);
void				ft_select_texture(t_cub *cub);
void				ft_save_textures(t_cub *cub, char *line, char type, int i);
void				ft_rc_floor(t_cub *cub);
void				ft_render_floor(t_cub *cub, int x, int y);
void				ft_rc_sprites(t_cub *cub);
void				ft_set_sprites(t_cub *cub, int i, int j);
void				ft_order_sprites(t_cub *cub, int i);
void				ft_render_sprites(t_cub *cub, int x);
void				ft_sort_sprites(t_cub *cub);
void				ft_save_bmp(t_cub *cub);
int					key_press(int keycode, t_cub *cub);
int					key_release(int keycode, t_cub *cub);
int					button_press(t_cub *cub);

#endif
