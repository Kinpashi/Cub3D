# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aahlaqqa <aahlaqqa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/11 00:08:49 by aahlaqqa          #+#    #+#              #
#    Updated: 2025/02/06 15:48:54 by aahlaqqa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CC= cc

CFLAGS= -Wall -Wextra -Werror -g

FLAGS=  -Lminilibx-linux -lmlx -lXext -lX11

NAME= cub3D

SOURCES= mendatory/parse_map.c mendatory/check_map.c mendatory/ft_strcmp.c Libft/ft_strrchr.c Libft/ft_strlen.c \
Libft/ft_split.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c \
mendatory/main.c mendatory/key_handles.c mendatory/check_identifier.c Libft/ft_atoi.c mendatory/handle_rgb_colors.c \
mendatory/pars_texture.c mendatory/draw_mini_map.c mendatory/check_borders.c mendatory/ft_strcpy.c Libft/ft_memset.c \
mendatory/check_len.c mendatory/check_rgb.c mendatory/read_map.c mendatory/checker.c mendatory/move_player.c mendatory/rander_player.c \
mendatory/draw_mini_map_2.c
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
