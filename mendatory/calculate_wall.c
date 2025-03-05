/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_wall.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahlaqqa <aahlaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 02:52:51 by aahlaqqa          #+#    #+#             */
/*   Updated: 2025/03/05 03:04:54 by aahlaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	calculate_wall(t_data *data)
{
	if (data->side == 0)
		data->perpWallDist = (data->sideDist_x - data->deltaDist_x);
	else
		data->perpWallDist = (data->sideDist_y - data->deltaDist_y);
	if (data->perpWallDist < 0.05)
		data->perpWallDist = 0.05;
	data->line_height = (int)(SCREEN_HEIGHT / data->perpWallDist);
	if (data->line_height > SCREEN_HEIGHT * 10)
		data->line_height = SCREEN_HEIGHT * 10;
	data->drawStart = -data->line_height / 2 + SCREEN_HEIGHT / 2;
	if (data->drawStart < 0)
		data->drawStart = 0;
	data->drawEnd = data->line_height / 2 + SCREEN_HEIGHT / 2;
	if (data->drawEnd >= SCREEN_HEIGHT)
		data->drawEnd = SCREEN_HEIGHT - 1;
	if (data->side == 0)
		data->wallx = data->player_y + data->perpWallDist * data->raydir_y;
	else
		data->wallx = data->player_x + data->perpWallDist * data->raydir_x;
	data->wallx -= floor(data->wallx);
	data->txt_x = (int)(data->wallx * (double)data->tex_width);
	if (data->side == 0 && data->raydir_x > 0)
		data->txt_x = data->tex_width - data->txt_x - 1;
	if (data->side == 1 && data->raydir_y < 0)
		data->txt_x = data->tex_width - data->txt_x - 1;
}
