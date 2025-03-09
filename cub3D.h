/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahlaqqa <aahlaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 00:40:18 by aahlaqqa          #+#    #+#             */
/*   Updated: 2025/03/09 16:14:47 by aahlaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "./minilibx-linux/mlx.h"
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# ifndef M_PI
#  define M_PI 3.14159265358979323846
# endif

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# define SCREEN_WIDTH 1000
# define SCREEN_HEIGHT 500

# define MOVE_SPEED 0.01

# define ROT_SPEED 0.012

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
	char	**start_map;
	char	**new_map;
	char	*line;
	char	**prefix;
	char	*no_texture;
	char	*so_texture;
	char	*we_texture;
	char	*ea_texture;
	int		no_tex_width;
	int		no_tex_height;
	int		so_tex_width;
	int		so_tex_height;
	int		we_tex_width;
	int		we_tex_height;
	int		ea_tex_width;
	int		ea_tex_height;
	int		tex_width;
	int		tex_height;
	int		prev_mouse_x;
	char	**texture;
	char	**prefix1;
	char	**rest;
	void	*no_texture_img;
	void	*so_texture_img;
	void	*we_texture_img;
	void	*ea_texture_img;
	int		*no_texture_data;
	int		*so_texture_data;
	int		*ea_texture_data;
	int		*we_texture_data;
	int		count1;
	int		count;
	int		counter;
	int		color_counter;
	int		flag;
	int		len;
	t_path	*path;
	char	*rgb_res;
	void	*mlx;
	void	*mlx_win;
	int		floor[3];
	int		cell[3];
	int		height;
	int		width;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
	size_t	y;
	size_t	j;
	double	player_x;
	double	player_y;
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
	/////////////////////
	double	dir_x;
	double	dir_y;
	double	plan_x;
	double	plan_y;
	double	camera_x;
	double	camera_y;
	double	raydir_x;
	double	raydir_y;
	int		raymap_x;
	int		raymap_y;
	int		step_x;
	int		step_y;
	double	deltadistx;
	double	deltadisty;
	double	sidedistx;
	double	sidedisty;
	int		hit;
	int		side;
	int		line_height;
	double	perpwalldist;
	int		drawstart;
	int		drawend;
	double	wallx;
	int		txt_x;
	int		txt_y;
	void	*r_img;
	void	*r_addr;
	double	step;
	double	texpos;
	int		texy;
	int		p_color;
	int		*r_texture;
	int		map_width;
	int		map_height;
	int		no_count;
	int		so_count;
	int		we_count;
	int		ea_count;
	int		f_count;
	int		c_count;
	//////////////////////
	bool	move_forward;
	bool	move_backward;
	bool	move_left;
	bool	move_right;
	bool	rotate_left;
	bool	rotate_right;
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
int			handle_rgb(int red, int green, int blue);
void		check_all_in_map(t_data *data);
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
int			press_key(int keycode, t_data *data);
void		init_data(t_data *data);
int			close_win(t_data *data);
void		split_map(t_data *data);
void		print_malloc_error_message(void);
void		print_parsing_error_message(void);
void		handle_spaces(t_data *data);
void		check_prefix(t_data *data);
void		print_invalid_map_error_message(void);
void		assigne_colors(t_data *data);
void		assigne_texture(t_data *data);
void		print_incorrect_texture_error_message(void);
void		print_incorrect_prefix_error_message(void);
void		load_textures(t_data *data);
void		get_texture_data(t_data *data);
void		rotate_player(t_data *data, double rotation_angle);

////////////////////////////////////////////////

void		init_dir_and_plan(t_data *data);
void		raycasting(t_data *data);
void		perform_dda(t_data *data);
int			press_key(int key, t_data *data);
void		move_player(t_data *data);
int			release_key(int key, t_data *data);
int			press_key(int key, t_data *data);
int			game_loop(t_data *data);
void		setup_hook(t_data *data);
void		init_north(t_data *data);
void		init_south(t_data *data);
void		init_east(t_data *data);
void		init_west(t_data *data);
void		check_if_position(t_data *data, int *i, int *j);
void		init_vars(t_data *data, int *x);
void		handle_raydir_x(t_data *data);
void		handle_raydir_y(t_data *data);
void		init_textures(t_data *data);
void		calculate_wall(t_data *data);
void		set_pixels(t_data *data, int x, int y, int color);
void		draw_column(t_data *data, int x);
void		move_up(t_data *data);
void		move_down(t_data *data);
void		move_left(t_data *data);
void		move_right(t_data *data);
void		rotate_left(t_data *data);
void		rotate_right(t_data *data);
void		free_texture_one(t_data *data);
void		free_texture_two(t_data *data);
void		free_texture_three(t_data *data);
void		texture_east_error_message(void);
void		texture_west_error_message(void);
void		texture_south_error_message(void);
void		texture_north_error_message(void);
void		pars_error(int argc);
int			handle_mouse_movement(int mouse_x, int mouse_y, t_data *data);
void		calculate_map(t_data *data);
void		alloc_textures(t_data *data);
void		init_mouse(t_data *data);
void		init_second(t_data *data);

#endif