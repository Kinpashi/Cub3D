/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube_movements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahlaqqa <aahlaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 14:45:20 by aahlaqqa          #+#    #+#             */
/*   Updated: 2025/02/15 11:47:58 by aahlaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void rotate_player(t_data *data, int keycode)
{
    double rot_speed = 0.05;
    double old_dir_x;
    double old_plane_x;

    if (keycode == 65361)
        rot_speed *= -1;
    old_dir_x = data->dir_x;
    data->dir_x = data->dir_x * cos(rot_speed) - data->dir_y * sin(rot_speed);
    data->dir_y = old_dir_x * sin(rot_speed) + data->dir_y * cos(rot_speed);
    old_plane_x = data->plan_x;
    data->plan_x = data->plan_x * cos(rot_speed) - data->plan_y * sin(rot_speed);
    data->plan_y = old_plane_x * sin(rot_speed) + data->plan_y * cos(rot_speed);
    raycasting(data);
    draw_mini_map(data);
}

int press_key(int keycode, t_data *data)
{
    if (keycode == 65307)
        exit(0);
    if (keycode == 119 || keycode == 115)
        move_player(data, keycode);
    if (keycode == 65361 || keycode == 65363)
        rotate_player(data, keycode);
    return (0);
}
