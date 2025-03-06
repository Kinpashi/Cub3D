/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahlaqqa <aahlaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 16:24:06 by aahlaqqa          #+#    #+#             */
/*   Updated: 2025/03/05 16:26:21 by aahlaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	rotate_left(t_data *data)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = data->dir_x;
	data->dir_x = data->dir_x * cos(-ROT_SPEED) - data->dir_y * sin(-ROT_SPEED);
	data->dir_y = old_dir_x * sin(-ROT_SPEED) + data->dir_y * cos(-ROT_SPEED);
	old_plane_x = data->plan_x;
	data->plan_x = data->plan_x * cos(-ROT_SPEED) - data->plan_y
		* sin(-ROT_SPEED);
	data->plan_y = old_plane_x * sin(-ROT_SPEED) + data->plan_y
		* cos(-ROT_SPEED);
}

void	rotate_right(t_data *data)
{
	double	old_dirx;
	double	old_planx;

	old_dirx = data->dir_x;
	data->dir_x = data->dir_x * cos(ROT_SPEED) - data->dir_y * sin(ROT_SPEED);
	data->dir_y = old_dirx * sin(ROT_SPEED) + data->dir_y * cos(ROT_SPEED);
	old_planx = data->plan_x;
	data->plan_x = data->plan_x * cos(ROT_SPEED) - data->plan_y
		* sin(ROT_SPEED);
	data->plan_y = old_planx * sin(ROT_SPEED) + data->plan_y * cos(ROT_SPEED);
}
