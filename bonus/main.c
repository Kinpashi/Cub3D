/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahlaqqa <aahlaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 00:33:48 by aahlaqqa          #+#    #+#             */
/*   Updated: 2025/02/25 16:53:21 by aahlaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void function_call(t_data *data, t_path *path)
{
	(void)path;
	check_all_in_map(data);
	check_no_identifier(data);
	check_colors(data);
	check_mini_map(data);
}

void init_mouse(t_data *data)
{
	mlx_mouse_hide(data->mlx, data->mlx_win);
	mlx_mouse_move(data->mlx,data->mlx_win, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
	mlx_hook(data->mlx_win, 6, 1L << 6, handle_mouse_move, data);
}

int main(int argc, char **argv)
{
	t_data data;
	t_path path;

	data.floor[0] = 0;
	data.floor[1] = 0;
	data.floor[2] = 0;
	data.cell[0] = 0;
	data.cell[1] = 0;
	data.cell[2] = 0;
	data.flag = 0;
	data.counter = 0;
	data.color_counter = 0;
	data.hit = 0;
	data.side = 0;
	data.line_height = 0;
	data.drawStart = 0;
	data.drawEnd = 0;
	data.wallx = 0;
	data.txt_x = 0;
	data.txt_y = 0;
	data.tex_height = 0;
	data.tex_width = 0;
	data.so_texture = malloc(sizeof(char) * 100);
	data.no_texture = malloc(sizeof(char) * 100);
	data.ea_texture = malloc(sizeof(char) * 100);
	data.we_texture = malloc(sizeof(char) * 100);
	if (argc != 2)
	{
		printf("Too much arguments !\n");
		exit(1);
	}
	check_path(argv[1]);
	read_lines(argv[1], &data);
	function_call(&data, &path);
	data.mlx = mlx_init();
	load_textures(&data);
	get_texture_data(&data);
	data.mlx_win = mlx_new_window(data.mlx, SCREEN_WIDTH, SCREEN_HEIGHT, "Cub3D");
	init_data(&data);
	init_dir_and_plan(&data);
	init_mouse(&data);
	raycasting(&data);
	mlx_hook(data.mlx_win, 2, (1L << 0), press_key, &data);
	mlx_hook(data.mlx_win, 17, 0, close_win, &data);
	mlx_loop(data.mlx);
	free(data.ea_texture);
	free(data.we_texture);
	free(data.no_texture);
	free(data.so_texture);
	return (0);
}