# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sthrace <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/03 15:35:40 by sthrace           #+#    #+#              #
#    Updated: 2020/11/14 14:02:47 by sthrace          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= ./ft_atoi.c \
		  ./ft_bzero.c \
		 ./ft_calloc.c \
		 ./ft_isalnum.c \
		 ./ft_isalpha.c \
		 ./ft_isascii.c \
		 ./ft_isdigit.c \
		 ./ft_isprint.c \
		 ./ft_memchr.c \
		 ./ft_memcmp.c \
		 ./ft_memcpy.c \
		 ./ft_memccpy.c \
		 ./ft_memmove.c \
		 ./ft_memset.c \
		 ./ft_strchr.c \
		 ./ft_strdup.c \
		 ./ft_strlcat.c \
		 ./ft_strlcpy.c \
		 ./ft_strlen.c \
		 ./ft_strncmp.c \
		 ./ft_strnstr.c \
		 ./ft_strrchr.c \
		 ./ft_tolower.c \
		 ./ft_toupper.c \
		 ./ft_substr.c \
		 ./ft_strjoin.c \
		 ./ft_strtrim.c \
		 ./ft_split.c \
		 ./ft_itoa.c \
		 ./ft_strmapi.c \
		 ./ft_putchar_fd.c \
		 ./ft_putstr_fd.c \
		 ./ft_putendl_fd.c \
		 ./ft_putnbr_fd.c \
		 ./ft_gnl.c \
		 ./ft_lstnew.c \
		 ./ft_lstadd_front.c \
		 ./ft_lstsize.c \
		 ./ft_lstlast.c \
		 ./ft_lstadd_back.c \
		 ./ft_lstdelone.c \
		 ./ft_lstclear.c \
		 ./ft_lstiter.c \
		 ./ft_lstmap.c \
		 ./ft_itoa_base.c \
		 ./ft_bspace.c
NAME	= libft.a
OBJS	= $(SRCS:.c=.o)
HEADER = libft.h

WFLAGS	= -Wall -Wextra -Werror

.c.o:
	@gcc $(WFLAGS) -c $< -o $(<:.c=.o)
$(NAME): $(OBJS) $(HEADER)
	@ar rc $(NAME) $(OBJS)

all: $(NAME)

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all
