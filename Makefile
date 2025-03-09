# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aahlaqqa <aahlaqqa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/11 00:08:49 by aahlaqqa          #+#    #+#              #
#    Updated: 2025/03/09 16:14:13 by aahlaqqa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CC= cc

CFLAGS= -Wall -Wextra -Werror
# LDFLAGS = -g3 -fsanitize=address
FLAGS=  -Lminilibx-linux -lmlx -lXext -lX11 -lm

NAME= cub3D

SOURCES= mendatory/parse_map.c mendatory/check_map.c mendatory/ft_strcmp.c Libft/ft_strrchr.c \
Libft/ft_strlen.c Libft/ft_split.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c \
mendatory/main.c mendatory/key_handles.c mendatory/check_identifier.c Libft/ft_atoi.c mendatory/handle_rgb_colors.c \
mendatory/check_borders.c mendatory/ft_strcpy.c Libft/ft_memset.c mendatory/check_len.c mendatory/check_rgb.c mendatory/read_map.c \
mendatory/checker.c mendatory/move_player.c mendatory/raycasting.c mendatory/cube_movements.c \
mendatory/errors.c mendatory/check_map1.c mendatory/assigne.c mendatory/textures.c \
mendatory/init_dirs_and_plans.c mendatory/init_vars.c mendatory/init_textures.c \
mendatory/calculate_wall.c mendatory/iterate_in_map.c mendatory/iterate_color_map.c \
mendatory/handle_moves.c mendatory/rotate.c mendatory/free_textures.c \
mendatory/texture_errors.c mendatory/alloc_texture.c mendatory/init.c

BONUS= bonus/parse_map.c bonus/check_map.c bonus/ft_strcmp.c Libft/ft_strrchr.c \
Libft/ft_strlen.c Libft/ft_split.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c \
bonus/main.c bonus/key_handles.c bonus/check_identifier.c Libft/ft_atoi.c bonus/handle_rgb_colors.c \
bonus/check_borders.c bonus/ft_strcpy.c Libft/ft_memset.c bonus/check_len.c bonus/check_rgb.c bonus/read_map.c \
bonus/checker.c bonus/move_player.c bonus/raycasting.c bonus/cube_movements.c \
bonus/errors.c bonus/check_map1.c bonus/assigne.c bonus/textures.c \
bonus/init_dirs_and_plans.c bonus/init_vars.c bonus/init_textures.c \
bonus/calculate_wall.c bonus/iterate_in_map.c bonus/iterate_color_map.c \
bonus/handle_moves.c bonus/rotate.c bonus/free_textures.c \
bonus/texture_errors.c bonus/mouse.c bonus/alloc_texture.c bonus/init.c

OBJECTS= $(SOURCES:.c=.o)

BOBJECTS= $(BONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(OBJECTS) $(FLAGS) -o $(NAME)

bonus: $(BOBJECTS)
	$(CC) $(BOBJECTS) $(FLAGS) -o $(NAME)

.c .o:
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	rm -f $(OBJECTS) $(BOBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re bonus

.SECONDARY: $(OBJECTS) $(BOBJECTS)
