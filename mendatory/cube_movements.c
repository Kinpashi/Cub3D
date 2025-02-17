/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube_movements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahlaqqa <aahlaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 14:45:20 by aahlaqqa          #+#    #+#             */
/*   Updated: 2025/02/17 22:16:48 by aahlaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int press_key(int key, t_data *data)
{
    if (key == 65307) // ESC key
        exit(0);
    if (key == 119) // W up
    {
        if (data->mini_map[(int)(data->player_x + data->dir_x * MOVE_SPEED)][(int)data->player_y] != '1')
            data->player_x += data->dir_x * MOVE_SPEED;
        if (data->mini_map[(int)data->player_x][(int)(data->player_y + data->dir_y * MOVE_SPEED)] != '1')
            data->player_y += data->dir_y * MOVE_SPEED;
    }
    else if (key == 115) // S down
    {
        if (data->mini_map[(int)(data->player_x - data->dir_x * MOVE_SPEED)][(int)data->player_y] != '1')
            data->player_x -= data->dir_x * MOVE_SPEED;
        if (data->mini_map[(int)data->player_x][(int)(data->player_y - data->dir_y * MOVE_SPEED)] != '1')
            data->player_y -= data->dir_y * MOVE_SPEED;
    }
    else if (key == 97) // A left
    {
        if (data->mini_map[(int)(data->player_x - data->plan_x * MOVE_SPEED)][(int)data->player_y] != '1')
            data->player_x -= data->plan_x * MOVE_SPEED;
        if (data->mini_map[(int)data->player_x][(int)(data->player_y - data->plan_y * MOVE_SPEED)] != '1')
            data->player_y -= data->plan_y * MOVE_SPEED;
    }
    else if (key == 100) // D right
    {
        if (data->mini_map[(int)(data->player_x + data->plan_x * MOVE_SPEED)][(int)data->player_y] != '1')
            data->player_x += data->plan_x * MOVE_SPEED;
        if (data->mini_map[(int)data->player_x][(int)(data->player_y + data->plan_y * MOVE_SPEED)] != '1')
            data->player_y += data->plan_y * MOVE_SPEED;
    }
    else if (key == 65361) // Left key
    {
        double old_dir_x;
        double old_plane_x;

        old_dir_x = data->dir_x;
        data->dir_x = data->dir_x * cos(-ROT_SPEED) - data->dir_y * sin(-ROT_SPEED);
        data->dir_y = old_dir_x * sin(-ROT_SPEED) + data->dir_y * cos(-ROT_SPEED);
        old_plane_x = data->plan_x;
        data->plan_x = data->plan_x * cos(-ROT_SPEED) - data->plan_y * sin(-ROT_SPEED);
        data->plan_y = old_plane_x * sin(-ROT_SPEED) + data->plan_y * cos(-ROT_SPEED);
    }
    else if (key == 65363) // Right key
    {
        double old_dirx;
        double old_planx;

        old_dirx = data->dir_x;
        data->dir_x = data->dir_x * cos(ROT_SPEED) - data->dir_y * sin(ROT_SPEED);
        data->dir_y = old_dirx * sin(ROT_SPEED) + data->dir_y * cos(ROT_SPEED);
        old_planx = data->plan_x;
        data->plan_x = data->plan_x * cos(ROT_SPEED) - data->plan_y * sin(ROT_SPEED);
        data->plan_y = old_planx * sin(ROT_SPEED) + data->plan_y * cos(ROT_SPEED);
    }
    raycasting(data);
    return (0);
}