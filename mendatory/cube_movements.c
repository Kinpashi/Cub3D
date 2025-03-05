/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube_movements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahlaqqa <aahlaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 14:45:20 by aahlaqqa          #+#    #+#             */
/*   Updated: 2025/03/05 00:01:16 by aahlaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

// int press_key(int key, t_data *data)
// {
//     if (key == 65307) // ESC key
//         exit(0);
//     if (key == 119) // W up
//     {
//         if (data->mini_map[(int)(data->player_x + data->dir_x * MOVE_SPEED)][(int)data->player_y] != '1')
//             data->player_x += data->dir_x * MOVE_SPEED;
//         if (data->mini_map[(int)data->player_x][(int)(data->player_y + data->dir_y * MOVE_SPEED)] != '1')
//             data->player_y += data->dir_y * MOVE_SPEED;
//     }
//     else if (key == 115) // S down
//     {
//         if (data->mini_map[(int)(data->player_x - data->dir_x * MOVE_SPEED)][(int)data->player_y] != '1')
//             data->player_x -= data->dir_x * MOVE_SPEED;
//         if (data->mini_map[(int)data->player_x][(int)(data->player_y - data->dir_y * MOVE_SPEED)] != '1')
//             data->player_y -= data->dir_y * MOVE_SPEED;
//     }
//     else if (key == 97) // A left
//     {
//         if (data->mini_map[(int)(data->player_x - data->plan_x * MOVE_SPEED)][(int)data->player_y] != '1')
//             data->player_x -= data->plan_x * MOVE_SPEED;
//         if (data->mini_map[(int)data->player_x][(int)(data->player_y - data->plan_y * MOVE_SPEED)] != '1')
//             data->player_y -= data->plan_y * MOVE_SPEED;
//     }
//     else if (key == 100) // D right
//     {
//         if (data->mini_map[(int)(data->player_x + data->plan_x * MOVE_SPEED)][(int)data->player_y] != '1')
//             data->player_x += data->plan_x * MOVE_SPEED;
//         if (data->mini_map[(int)data->player_x][(int)(data->player_y + data->plan_y * MOVE_SPEED)] != '1')
//             data->player_y += data->plan_y * MOVE_SPEED;
//     }
//     else if (key == 65361) // Left key
//     {
//         double old_dir_x;
//         double old_plane_x;

//         old_dir_x = data->dir_x;
//         data->dir_x = data->dir_x * cos(-ROT_SPEED) - data->dir_y * sin(-ROT_SPEED);
//         data->dir_y = old_dir_x * sin(-ROT_SPEED) + data->dir_y * cos(-ROT_SPEED);
//         old_plane_x = data->plan_x;
//         data->plan_x = data->plan_x * cos(-ROT_SPEED) - data->plan_y * sin(-ROT_SPEED);
//         data->plan_y = old_plane_x * sin(-ROT_SPEED) + data->plan_y * cos(-ROT_SPEED);
//     }
//     else if (key == 65363) // Right key
//     {
//         double old_dirx;
//         double old_planx;

//         old_dirx = data->dir_x;
//         data->dir_x = data->dir_x * cos(ROT_SPEED) - data->dir_y * sin(ROT_SPEED);
//         data->dir_y = old_dirx * sin(ROT_SPEED) + data->dir_y * cos(ROT_SPEED);
//         old_planx = data->plan_x;
//         data->plan_x = data->plan_x * cos(ROT_SPEED) - data->plan_y * sin(ROT_SPEED);
//         data->plan_y = old_planx * sin(ROT_SPEED) + data->plan_y * cos(ROT_SPEED);
//     }
//     raycasting(data);
//     return (0);
// }

int press_key(int key, t_data *data)
{
    if (key == 65307)
        exit(0);
    if (key == 119)
        data->move_forward = true;
    else if (key == 115)
        data->move_backward = true;
    else if (key == 97)
        data->move_left = true;
    else if (key == 100)
        data->move_right = true;
    else if (key == 65361)
        data->rotate_left = true;
    else if (key == 65363)
        data->rotate_right = true;
    return (0);
}

int release_key(int key, t_data *data)
{
    if (key == 119)
        data->move_forward = false;
    else if (key == 115)
        data->move_backward = false;
    else if (key == 97)
        data->move_left = false;
    else if (key == 100)
        data->move_right = false;
    else if (key == 65361)
        data->rotate_left = false;
    else if (key == 65363)
        data->rotate_right = false;
    return (0);
}

void move_player(t_data *data)
{
    if (data->move_forward)
    {
        if (data->mini_map[(int)(data->player_x + data->dir_x * MOVE_SPEED)][(int)data->player_y] != '1')
            data->player_x += data->dir_x * MOVE_SPEED;
        if (data->mini_map[(int)data->player_x][(int)(data->player_y + data->dir_y * MOVE_SPEED)] != '1')
            data->player_y += data->dir_y * MOVE_SPEED;
    }
    if (data->move_backward)
    {
        if (data->mini_map[(int)(data->player_x - data->dir_x * MOVE_SPEED)][(int)data->player_y] != '1')
            data->player_x -= data->dir_x * MOVE_SPEED;
        if (data->mini_map[(int)data->player_x][(int)(data->player_y - data->dir_y * MOVE_SPEED)] != '1')
            data->player_y -= data->dir_y * MOVE_SPEED;
    }
    if (data->move_left)
    {
        if (data->mini_map[(int)(data->player_x - data->plan_x * MOVE_SPEED)][(int)data->player_y] != '1')
            data->player_x -= data->plan_x * MOVE_SPEED;
        if (data->mini_map[(int)data->player_x][(int)(data->player_y - data->plan_y * MOVE_SPEED)] != '1')
            data->player_y -= data->plan_y * MOVE_SPEED;
    }
    if (data->move_right)
    {
        if (data->mini_map[(int)(data->player_x + data->plan_x * MOVE_SPEED)][(int)data->player_y] != '1')
            data->player_x += data->plan_x * MOVE_SPEED;
        if (data->mini_map[(int)data->player_x][(int)(data->player_y + data->plan_y * MOVE_SPEED)] != '1')
            data->player_y += data->plan_y * MOVE_SPEED;
    }
    if (data->rotate_left)
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
    if (data->rotate_right)
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
}

int game_loop(t_data *data)
{
    static int first_frame = 1;

    if (first_frame)
    {
        raycasting(data);
        first_frame = 0;
        return (0);
    }
    if (data->move_backward || data->move_forward || data->move_left || data->move_right || data->rotate_left || data->rotate_right)
    {
        move_player(data);
        raycasting(data);
    }
    return (0);
}

void setup_hook(t_data *data)
{
    data->move_backward = false;
    data->move_forward = false;
    data->move_left = false;
    data->move_right = false;
    data->rotate_left = false;
    data->rotate_right = false;
}
