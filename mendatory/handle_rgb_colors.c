/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_rgb_colors.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmed <ahmed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 23:57:58 by aahlaqqa          #+#    #+#             */
/*   Updated: 2025/02/07 15:15:00 by ahmed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	handle_rgb(int red, int green, int blue)
{
	return (red << 16 | green << 8 | blue);
}

void	init_data(t_data *data)
{
	data->floor_color = handle_rgb(data->floor[0], data->floor[1],
			data->floor[2]);
	data->cell_color = handle_rgb(data->cell[0], data->cell[1], data->cell[2]);
	data->img = mlx_new_image(data->mlx, 1500, 940);
	data->pixel_buffer = mlx_get_data_addr(data->img, &data->bits_per_pixel,
			&data->size_line, &data->endian);
}

void	set_cell_pixel(t_data *data, int x, int y, int line_len)
{
	int	offset;

	offset = (y * line_len) + (x * (data->bits_per_pixel / 8));
	*(int *)(data->pixel_buffer + offset) = data->cell_color;
}

void	set_floor_pixel(t_data *data, int x, int y, int line_len)
{
	int	offset;

	offset = (y * line_len) + (x * (data->bits_per_pixel / 8));
	*(int *)(data->pixel_buffer + offset) = data->floor_color;
}

void	draw_window(t_data *data)
{
	data->mini_y = 0;
	init_data(data);
	while (data->mini_y < SCREEN_HEIGHT / 2)
	{
		data->mini_x = 0;
		while (data->mini_x < SCREEN_WIDTH)
		{
			set_cell_pixel(data, data->mini_x, data->mini_y, data->size_line);
			data->mini_x++;
		}
		data->mini_y++;
	}
	while (data->mini_y < SCREEN_HEIGHT)
	{
		data->mini_x = 0;
		while (data->mini_x < SCREEN_WIDTH)
		{
			set_floor_pixel(data, data->mini_x, data->mini_y, data->size_line);
			data->mini_x++;
		}
		data->mini_y++;
	}
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);
}
