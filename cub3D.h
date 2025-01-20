/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmed <ahmed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 00:40:18 by aahlaqqa          #+#    #+#             */
/*   Updated: 2025/01/20 17:52:12 by ahmed            ###   ########.fr       */
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
#include <math.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 42
#endif

typedef struct s_path
{
    char *key;
    char *value;
} t_path;

typedef struct s_data
{
    char **my_map;   // struct to store the textures
    char **my_color; // struct to store the colors
    char **mini_map; // struct to strore the map (1-0)
    char *line;
    char *prefix;
    char *texture;
    char *prefix1;
    char *rest;
    int count1;
    int count;
    int len;
    t_path *path;
    char *rgb_res; // contain the rgb values in integers
    void *mlx;
    void *mlx_win;
    void *img;
    void *wall_img;
    void *txt_buff;
    int floor[3]; // struct to stock floor values
    int cell[3];  // struct to stock cell values
    int height;
    int width;
    int bits_per_pixel;
    int size_line;
    int endian;
    int x;
    size_t y;
    size_t j;
    int player_x;
    int player_y;
    int map_x;
    int map_y;
    int stepx;
    int stepy;
    int side;
    int wall;
    int line_height;
    int draw_start;
    int draw_end;
    int screenheight;
    int screenwidth;
    int map_height;
    int map_width;
    double deltadistx;
    double deltadisty;
    double sidedistx;
    double sidedisty;
    double perpwalldist;
    double raydistans;
} t_data;

// Libft functions
char *ft_strrchr(const char *s, int c);
size_t ft_strlen(const char *s);
int ft_strcmp(const char *s1, const char *s2);
char *ft_strjoin(char *s1, char *s2);
void *ft_calloc(size_t count, size_t size);
void ft_bzero(void *s, size_t n);
char *ft_strdup(const char *s1);
char **ft_split(char const *s, char c);
int ft_atoi(const char *str);
char *ft_strcpy(char *dst, const char *src);
void *ft_memset(void *b, int c, size_t len);

// get_next_line function
char *get_next_line(int fd);

// Parsing map functions
void check_player(t_data *data);
void check_path(char *path);
void read_lines(char *path, t_data *data);
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
void check_all_in_map(t_data *data);
void pars_texture(t_data *data, t_path *path);
void find_player_position(t_data *data);
void calculat_dda(t_data *data, double raydirx, double raydiry);
void calculate_line_hight(t_data *data);
void draw_mini_map(t_data *data);
void check_map(t_data *data);
void check_top_borders(t_data *data);
void check_bottom_border(t_data *data);
void check_left_border(t_data *data);
void check_right_border(t_data *data);
void check_len(t_data *data);
void check_around_space(t_data *data);
char *directions_map(int fd, int *i, char *line);
char *color_map(int fd, int *i, char *line);
char *main_map(int fd, char *line);
void caller_function(t_data *data);
void	iterate_in_map(size_t *i, t_data *data);
void	check_no_identifier(t_data *data);
void	check_data(t_data *data);
void	iterate_color_map(t_data *data, int *i);

// minilibx functions
int handle_esc(int keycode, void *param);
int close_win(t_data *data);

// mini_map functions

#endif
