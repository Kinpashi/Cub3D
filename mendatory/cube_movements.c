/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube_movements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahlaqqa <aahlaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 14:45:20 by aahlaqqa          #+#    #+#             */
/*   Updated: 2025/02/14 15:23:29 by aahlaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int key_moves(int keycode, t_data *data)
{
    if (keycode == 119)
    {
        if (data->my_map[(int)(data->player_y + data->raydir_y * 0.2)][(int)data->player_x] == '0')
            data->player_y += data->raydir_y * 0.2;
        if (data->my_map[(int)data->player_y][(int)(data->player_x + data->raydir_x * 0.2)] == '0')
            data->player_x += data->raydir_x * 0.2;
    }
    if (keycode == 115)
    {
        if (data->my_map[(int)(data->player_y - data->raydir_y * 0.2)][(int)data->player_x] == '0')
            data->player_y -= data->raydir_y * 0.2;
        if (data->my_map[(int)data->player_y][(int)(data->player_x - data->raydir_x * 0.2)] == '0')
            data->player_x -= data->raydir_x * 0.2;
    }
    if (keycode == 100)
    {
        if (data->my_map[(int)(data->player_y + data->plan_y * 0.2)][(int)data->player_x] == '0')
            data->player_y += data->plan_y * 0.2;
        if (data->my_map[(int)data->player_y][(int)(data->player_x + data->plan_x * 0.2)] == '0')
            data->player_x += data->plan_x * 0.2;
    }
    if (keycode == 97)
    {
        if (data->my_map[(int)(data->player_y - data->plan_y * 0.2)][(int)data->player_x] == '0')
            data->player_y -= data->plan_y * 0.2;
        if (data->my_map[(int)data->player_y][(int)(data->player_x - data->plan_x * 0.2)] == '0')
            data->player_x -= data->plan_x * 0.2;
    }
    mlx_clear_window(data->mlx, data->mlx_win);
    return(0);
}