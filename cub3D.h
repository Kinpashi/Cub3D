/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahlaqqa <aahlaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 00:40:18 by aahlaqqa          #+#    #+#             */
/*   Updated: 2025/02/08 19:31:50 by aahlaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "./minilibx-linux/mlx.h"
# include <fcntl.h>
# include <math.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

#define SCREEN_WIDTH 1000
#define SCREEN_HEIGHT 500

typedef struct s_path
{
	char	*key;
	char	*value;
}			t_path;

typedef struct s_data
{
	char	**my_map;
	char	**my_color;
	char	**mini_map;
	char **start_map;
	char	*line;
	char	*prefix;
	char	*texture;
	char	*prefix1;
	char	*rest;
	int		count1;
	int		count;
	int flag;
	int		len;
	t_path	*path;
	char	*rgb_res;
	void	*mlx;
	void	*mlx_win;
	void	*img;
	void	*wall_img;
	void	*txt_buff;
	int		floor[3];
	int		cell[3];
	int		height;
	int		width;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
	int		x;
	size_t	y;
	size_t	j;
	double	player_x;
	double	player_y;
	int		screenheight;
	int		screenwidth;
	int		map_height;
	int		map_width;
	int		mini_map_display_width;
	int		mini_map_display_height;
	int		view_width;
	int		view_height;
	int		tile_size;
	char	*img_data;
	void	*img_mini;
	int		start_x;
	int		start_y;
	int		map_x;
	int		map_y;
	char	*pixel_buffer;
	int		floor_color;
	int		cell_color;
	int		mini_x;
	int		mini_y;
	double	new_x;
	double	new_y;
	int		player_i;
	int		player_j;
	int		tile_center_x;
	int		tile_center_y;
	int		radius;
	int		dx;
	int		dy;
	int		mini_color;
	int		max_size;
	int		raduis_square;
}			t_data;

char		*ft_strrchr(const char *s, int c);
size_t		ft_strlen(const char *s);
int			ft_strcmp(const char *s1, const char *s2);
char		*ft_strjoin(char *s1, char *s2);
void		*ft_calloc(size_t count, size_t size);
void		ft_bzero(void *s, size_t n);
char		*ft_strdup(const char *s1);
char		**ft_split(char const *s, char c);
int			ft_atoi(const char *str);
char		*ft_strcpy(char *dst, const char *src);
void		*ft_memset(void *b, int c, size_t len);

char		*get_next_line(int fd);

void		check_player(t_data *data);
void		check_path(char *path);
void		read_lines(char *path, t_data *data);
void		check_no_identifier(t_data *data);
int			check_for_identifier(char *str, int i);
void		check_colors(t_data *data);
int			check_for_colors(char *str, int i);
int			check_length_color(char *str, int i);
void		check_floor_rgb(char *str, t_data *data);
void		check_cell_rgb(char *str, t_data *data);
void		check_rgb_fllor_range(t_data *data);
void		check_rgb_cell_range(t_data *data);
void		check_mini_map(t_data *data);
void		check_texture(char *str, t_data *data);
void		draw_window(t_data *data);
int			handle_rgb(int red, int green, int blue);
void		set_floor_pixel(t_data *data, int x, int y, int line_len);
void		set_cell_pixel(t_data *data, int x, int y, int line_len);
void		check_all_in_map(t_data *data);
void		pars_texture(t_data *data, t_path *path);
void		draw_mini_map(t_data *data);
void		check_map(t_data *data);
void		check_top_borders(t_data *data);
void		check_bottom_border(t_data *data);
void		check_left_border(t_data *data);
void		check_right_border(t_data *data);
void		check_len(t_data *data);
void		check_around_space(t_data *data);
char		*directions_map(int fd, int *i, char *line);
char		*color_map(int fd, int *i, char *line);
char		*main_map(int fd, char *line);
void		caller_function(t_data *data);
void		iterate_in_map(size_t *i, t_data *data);
void		check_no_identifier(t_data *data);
void		check_data(t_data *data);
void		iterate_color_map(t_data *data, int *i);
int			move_player(t_data *data, int keycode);
int			press_key(int keycode, t_data *data);
void		draw_player_as_circle(t_data *data, int center_x, int center_y,
				int radius);
void		render_mini_map(t_data *data);
void		handle_player(t_data *data, int x, int y);
void		find_player_position(t_data *data);
int			draw_tile(char tile);

int			close_win(t_data *data);

#endif
