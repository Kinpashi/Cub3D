/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahlaqqa <aahlaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 00:40:18 by aahlaqqa          #+#    #+#             */
/*   Updated: 2024/11/21 18:22:51 by aahlaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H

#include "./minilibx_opengl/mlx.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 42
#endif

#define MINI_MAP_HEIGHT 100
#define MINI_MAP_WIDTH 100
#define SCALE_FACTOR 5

#define WALL_COLOR 0x000000
#define FLOOR_COLOR 0xFFFFFF
#define PLAAYER_COLOR 0xFF0000

typedef struct s_data
{
    char **my_map; // struct to store the textures
    char **my_color; // struct to store the colors
    char **mini_map; // struct to strore the map (1-0)
    char *line;
    char *texture;
    char *rgb_res; // contain the rgb values in integers
    void *mlx;
    void *mlx_win;
    void *img;
    int floor[3]; // struct to stock floor values
    int cell[3]; // struct to stock cell values
    int height;
    int width;
    int bits_per_pixel;
    int size_line;
    int endian;
    int x;
    int y;
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
int	ft_atoi(const char *str);

// get_next_line function
char *get_next_line(int fd);

// Parsing map functions
void check_player(t_data *data);
void check_path(char *path);
void read_lines(char *path, t_data *data);
void check_top_border(t_data *data);
void check_bottem_border(t_data *data);
void check_left_border(t_data *data);
void check_right_border(t_data *data);
void check_no_identifier(t_data *data);
int check_for_identifier(char *str, int i);
void check_colors(t_data *data);
int check_for_colors(char *str, int i);
int check_length_color(char *str, int i);
void check_floor_rgb(char *str, t_data *data);
void check_cell_rgb(char *str, t_data *data);
void check_rgb_fllor_range(t_data *data);
void check_rgb_cell_range(t_data *data);
void check_mini_map(t_data *data);
void check_texture(char *str, t_data *data);
void draw_window(t_data *data);
int handle_rgb(int red, int green, int blue);
void set_pixel(char *pixel_buffer, int x, int y, int color, int lengh, int bits_per_pixel);

// minilibx functions
int handle_esc(int keycode, void *param);
int close_win(t_data *data);

// mini_map functions

#endif
