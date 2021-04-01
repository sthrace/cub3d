NAME = cub3D

SRCS = srcs/cub3d.c \
		srcs/parsing/config_c.c \
		srcs/parsing/config_r.c \
		srcs/parsing/config_t.c \
		srcs/parsing/map.c \
		srcs/parsing/parser.c \
		srcs/parsing/player.c \
		srcs/raycasting/raycasting_floor.c \
		srcs/raycasting/raycasting_sprites.c \
		srcs/raycasting/raycasting_walls.c \
		srcs/rendering/render_2d.c \
		srcs/rendering/render_rc.c \
		srcs/various/exit.c \
		srcs/various/hooks.c \
		srcs/various/mlx.c \
		srcs/various/movement.c \
		srcs/various/save.c \
		srcs/various/sprites.c \
		srcs/various/texture.c 
	   

OBJS = $(SRCS:.c=.o)

CC = clang

RM = rm -rf

CFLAGS = -g -Wall -Werror -Wextra

MACFLAGS = -framework OpenGL -framework Appkit

all:		$(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -c -I./libft/ -I./minilibx_mac/ $< -o $(<:.c=.o)

$(NAME):	$(OBJS)
		@make -C libft
		@make -C minilibx_mac
		@mv minilibx_mac/libmlx.dylib .
		@$(CC) $(CFLAGS) $(MACFLAGS) -o $(NAME) -L. -lmlx -I./minilibx_mac/ $(OBJS) ./libft/libft.a
		@echo project compiled

clean:		
		@$(RM) $(OBJS)
		@make clean -C libft
		@make clean -C minilibx_mac
		@echo object files removed

fclean:		clean
		@$(RM) $(NAME) cub3D.bmp libmlx.dylib
		@make fclean -C libft
		@echo executable, dylib and bmp removed

re:		fclean all

.PHONY:		all clean fclean re
