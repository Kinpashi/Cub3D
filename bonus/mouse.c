/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahlaqqa <aahlaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 17:56:11 by aahlaqqa          #+#    #+#             */
/*   Updated: 2025/03/08 16:02:06 by aahlaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	rotate_player(t_data *data, double rotation_angle)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = data->dir_x;
	old_plane_x = data->plan_x;
	data->dir_x = data->dir_x * cos(rotation_angle) - data->dir_y
		* sin(rotation_angle);
	data->dir_y = old_dir_x * sin(rotation_angle) + data->dir_y
		* cos(rotation_angle);
	data->plan_x = data->plan_x * cos(rotation_angle) - data->plan_y
		* sin(rotation_angle);
	data->plan_y = old_plane_x * sin(rotation_angle) + data->plan_y
		* cos(rotation_angle);
	raycasting(data);
}

int handle_mouse_movement(int mouse_x, int mouse_y, t_data *data)
{
    double       sensitivity;
    double       rotation_angle;
    int          delta_x;
    static int   last_mouse_x = -1;
    static int   first_call = 1;

    (void)mouse_y;
    if (first_call) {
        last_mouse_x = mouse_x;
        first_call = 0;
        return (0);
    }
    delta_x = mouse_x - last_mouse_x;
    last_mouse_x = mouse_x;
    sensitivity = 0.005;
    rotation_angle = delta_x * sensitivity;
    rotate_player(data, rotation_angle);
    return (0);
}

void	init_mouse(t_data *data)
{
    mlx_mouse_hide(data->mlx, data->mlx_win);
	mlx_mouse_move(data->mlx, data->mlx_win, SCREEN_WIDTH / 2, SCREEN_HEIGHT
		/ 2);
	mlx_hook(data->mlx_win, 6, 1L << 6, handle_mouse_movement, data);
}
