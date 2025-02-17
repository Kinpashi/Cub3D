/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_mini_map_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahlaqqa <aahlaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 15:36:52 by aahlaqqa          #+#    #+#             */
/*   Updated: 2025/02/06 15:46:26 by aahlaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	find_player_position(t_data *data)
{
	int	y;
	int	x;

	y = 0;
	while (y < data->map_height)
	{
		x = 0;
		while (x < data->map_width)
		{
			if (data->mini_map[y][x] == 'N' || data->mini_map[y][x] == 'E'
				|| data->mini_map[y][x] == 'W' || data->mini_map[y][x] == 'S')
			{
				data->player_x = x;
				data->player_y = y;
				return ;
			}
			x++;
		}
		y++;
	}
}

void	handle_player(t_data *data, int x, int y)
{
	data->tile_center_x = (data->map_x - data->start_x) * data->tile_size
		+ data->tile_size / 2;
	data->tile_center_y = (data->map_y - data->start_y) * data->tile_size
		+ data->tile_size / 2;
	data->radius = data->tile_size / 3;
	data->dx = x - data->tile_center_x;
	data->dy = y - data->tile_center_y;
	if ((data->dx * data->dx + data->dy * data->dy) <= (data->radius
			* data->radius))
		data->mini_color = 0x9933FF;
	else
		data->mini_color = draw_tile('0');
}

void	render_mini_map(t_data *data)
{
	int		x;
	int		y;
	char	tile;

	y = 0;
	while (y < data->view_height * data->tile_size)
	{
		x = 0;
		while (x < data->view_width * data->tile_size)
		{
			data->map_x = data->start_x + x / data->tile_size;
			data->map_y = data->start_y + y / data->tile_size;
			tile = data->mini_map[data->map_y][data->map_x];
			if (tile == 'N' || tile == 'E' || tile == 'W' || tile == 'S')
				handle_player(data, x, y);
			else
				data->mini_color = draw_tile(tile);
			*(int *)(data->img_data + (y * data->size_line + x
						* (data->bits_per_pixel / 8))) = data->mini_color;
			x++;
		}
		y++;
	}
}
