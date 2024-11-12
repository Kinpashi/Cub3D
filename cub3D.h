/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahlaqqa <aahlaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 00:40:18 by aahlaqqa          #+#    #+#             */
/*   Updated: 2024/11/11 19:09:11 by aahlaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H

#include "./minilibx-linux/mlx.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 42
#endif

typedef struct s_data
{
    char **my_map;
    char *line;
} t_data;

// Libft functions
char *ft_strrchr(const char *s, int c);
size_t ft_strlen(const char *s);
int ft_strcmp(const char *s1, const char *s2);
char *ft_strjoin(char *s1, char *s2);
void *ft_calloc(size_t count, size_t size);
void ft_bzero(void *s, size_t n);
char *ft_strdup(const char *s1);
char	**ft_split(char const *s, char c);

// get_next_line function
char *get_next_line(int fd);

// Parsing map functions
void check_player(char **map);
void check_path(char *path);
char **read_lines(char *path, t_data *data);
void check_top_border(char **map);
void check_bottem_border(char **map);
void check_left_border(char **map);
void check_right_border(char **map);

#endif
