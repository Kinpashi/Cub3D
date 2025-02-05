/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_mini_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahlaqqa <aahlaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 18:34:38 by aahlaqqa          #+#    #+#             */
/*   Updated: 2025/02/05 21:48:00 by aahlaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void init_mini_map(t_data *data)
{
	int max_size;

	max_size = 100;
	data->map_height = 0;
	while (data->mini_map[data->map_height])
		data->map_height++;
	data->map_width = 0;
	while (data->mini_map[0][data->map_width])
		data->map_width++;
	if (data->map_width < 10)
		data->mini_map_display_width = data->map_width * 10;
	else
		data->mini_map_display_width = max_size;
	if (data->map_height < 10)
		data->mini_map_display_height = data->map_height * 10;
	else
		data->mini_map_display_height = max_size;
	if (data->map_width < 5)
		data->view_width = data->map_width;
	else
		data->view_width = 5;
	if (data->map_height < 5)
		data->view_height = data->map_height;
	else
		data->view_height = 5;
	data->tile_size = data->mini_map_display_width / data->view_width;
	if (data->mini_map_display_height / data->view_height < data->tile_size)
		data->tile_size = data->mini_map_display_height / data->view_height;
	if (data->tile_size < 2)
		data->tile_size = 2;
}

void calculate_view(t_data *data)
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

int draw_tile(char tile)
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

void render_mini_map(t_data *data)
{
	int x;
	int y;
	int color;
	printf("%d\n", data->tile_size);

	y = 0;
	while (y < data->view_height * data->tile_size)
	{
		x = 0;
		while (x < data->view_width * data->tile_size)
		{
			data->map_x = data->start_x + x / data->tile_size;
			data->map_y = data->start_y + y / data->tile_size;
			color = draw_tile(data->mini_map[data->map_y][data->map_x]);
			*(int *)(data->img_data + (y * data->size_line + x * (data->bits_per_pixel / 8))) = color;
			x++;
		}
		y++;
	}
}

void draw_mini_map(t_data *data)
{
	init_mini_map(data);
	calculate_view(data);
	data->img_mini = mlx_new_image(data->mlx, data->view_width * data->tile_size, data->view_height * data->tile_size);
	data->img_data = mlx_get_data_addr(data->img_mini, &data->bits_per_pixel,
									   &data->size_line, &data->endian);
	render_mini_map(data);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img_mini, 0, 0);
	mlx_destroy_image(data->mlx, data->img_mini);
}
