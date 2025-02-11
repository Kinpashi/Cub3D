/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahlaqqa <aahlaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 00:33:48 by aahlaqqa          #+#    #+#             */
/*   Updated: 2025/02/11 17:21:56 by aahlaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	function_call(t_data *data, t_path *path)
{
	(void)path;
	check_all_in_map(data);
	check_no_identifier(data);
	check_colors(data);
	check_mini_map(data);
}

int	main(int argc, char **argv)
{
	t_data	data;
	t_path	path;

	data.floor[0] = 0;
	data.floor[1] = 0;
	data.floor[2] = 0;
	data.cell[0] = 0;
	data.cell[1] = 0;
	data.cell[2] = 0;
	data.flag = 0;
	data.counter = 0;
	data.color_counter = 0;
	if (argc != 2)
	{
		printf("Too much arguments !\n");
		exit(1);
	}
	check_path(argv[1]);
	read_lines(argv[1], &data);
	function_call(&data, &path);
	data.mlx = mlx_init();
	data.mlx_win = mlx_new_window(data.mlx, SCREEN_WIDTH, SCREEN_HEIGHT, "Cub3D");
	draw_window(&data);
	draw_mini_map(&data);
	raycasting(&data);
	mlx_hook(data.mlx_win, 2, (1L << 0), press_key, &data);
	mlx_hook(data.mlx_win, 17, 0, close_win, &data);
	mlx_loop(data.mlx);
	return (0);
}
