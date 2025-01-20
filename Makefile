# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahmed <ahmed@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/11 00:08:49 by aahlaqqa          #+#    #+#              #
#    Updated: 2025/01/20 15:04:51 by ahmed            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CC= cc

CFLAGS= -Wall -Wextra -Werror -g

FLAGS=  -Lminilibx-linux -lmlx -lXext -lX11
#-L./minilibx_opengl -lmlx -framework OpenGL -framework AppKit

NAME= cub3D

SOURCES= parse_map.c check_map.c ft_strcmp.c Libft/ft_strrchr.c Libft/ft_strlen.c \
Libft/ft_split.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c \
main.c key_handles.c check_identifier.c Libft/ft_atoi.c handle_rgb_colors.c \
pars_texture.c find_position.c draw_mini_map.c check_borders.c ft_strcpy.c Libft/ft_memset.c \
check_len.c

OBJECTS= $(SOURCES:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(OBJECTS) $(FLAGS) -o $(NAME)

.c .o:
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re

.SECONDARY: $(OBJECTS)
