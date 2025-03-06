/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_vars.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahlaqqa <aahlaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 02:35:06 by aahlaqqa          #+#    #+#             */
/*   Updated: 2025/03/06 16:20:54 by aahlaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	init_vars(t_data *data, int *x)
{
	data->camera_x = 2.0 * *x / SCREEN_WIDTH - 1;
	data->raydir_x = data->dir_x + data->plan_x * data->camera_x;
	data->raydir_y = data->dir_y + data->plan_y * data->camera_x;
	data->raymap_x = (int)data->player_x;
	data->raymap_y = (int)data->player_y;
	data->deltadistx = fabs(1 / data->raydir_x);
	data->deltadisty = fabs(1 / data->raydir_y);
	data->hit = 0;
}

void	handle_raydir_x(t_data *data)
{
	if (data->raydir_x < 0)
	{
		data->step_x = -1;
		data->sidedistx = (data->player_x - data->raymap_x)
			* data->deltadistx;
	}
	else
	{
		data->step_x = 1;
		data->sidedistx = (data->raymap_x + 1.0 - data->player_x)
			* data->deltadistx;
	}
}

void	handle_raydir_y(t_data *data)
{
	if (data->raydir_y < 0)
	{
		data->step_y = -1;
		data->sidedisty = (data->player_y - data->raymap_y)
			* data->deltadisty;
	}
	else
	{
		data->step_y = 1;
		data->sidedisty = (data->raymap_y + 1.0 - data->player_y)
			* data->deltadisty;
	}
}
