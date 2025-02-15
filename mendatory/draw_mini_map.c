/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_mini_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahlaqqa <aahlaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 18:34:38 by aahlaqqa          #+#    #+#             */
/*   Updated: 2025/02/15 09:59:56 by aahlaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	calculate_view(t_data *data)
{
	data->start_x = data->player_x - data->view_width / 2;
	data->start_y = data->player_y - data->view_height / 2;

	if (data->start_x < 0)
		data->start_x = 0;
	if (data->start_y < 0)
		data->start_y = 0;
	if (data->start_x + data->view_width > data->map_width)
		data->start_x = data->map_width - data->view_width;
	if (data->start_y + data->view_height > data->map_height)
		data->start_y = data->map_height - data->view_height;
}


void	init_mini_map_2(t_data *data)
{
	if (data->map_width < 10)
		data->mini_map_display_width = data->map_width * 10;
	else
		data->mini_map_display_width = data->max_size;
	if (data->map_height < 10)
		data->mini_map_display_height = data->map_height * 10;
	else
		data->mini_map_display_height = data->max_size;
	if (data->map_width < 5)
		data->view_width = data->map_width;
	else
		data->view_width = 5;
	if (data->map_height < 5)
		data->view_height = data->map_height;
	else
		data->view_height = 5;
}

void	init_mini_map(t_data *data)
{
	data->max_size = 100;
	data->map_height = 0;
	while (data->mini_map[data->map_height])
		data->map_height++;
	data->map_width = 0;
	while (data->mini_map[0][data->map_width])
		data->map_width++;
	init_mini_map_2(data);
	data->tile_size = data->mini_map_display_width / data->view_width;
	if (data->mini_map_display_height / data->view_height < data->tile_size)
		data->tile_size = data->mini_map_display_height / data->view_height;
	if (data->tile_size < 2)
		data->tile_size = 2;
	find_player_position(data);
	calculate_view(data);
}

int	draw_tile(char tile)
{
	if (tile == '1')
		return (0xFF0000);
	if (tile == '0')
		return (0xFFFFFF);
	if (tile == 'N' || tile == 'E' || tile == 'W' || tile == 'S')
		return (0x9933FF);
	else
		return (0x000000);
}

void	draw_mini_map(t_data *data)
{
	init_mini_map(data);
	calculate_view(data);
	data->img_mini = mlx_new_image(data->mlx, data->view_width
			* data->tile_size, data->view_height * data->tile_size);
	data->img_data = mlx_get_data_addr(data->img_mini, &data->bits_per_pixel,
			&data->size_line, &data->endian);
	render_mini_map(data);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img_mini, 0, 0);
	mlx_destroy_image(data->mlx, data->img_mini);
}
