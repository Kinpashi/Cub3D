/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmed <ahmed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 14:35:21 by ahmed             #+#    #+#             */
/*   Updated: 2025/01/22 20:41:54 by ahmed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int move_player(t_data *data, int keycode)
{
    double new_x;
    double new_y;
    int i;
    int j;

    data->player_x = 0;
    data->player_y = 0;
    i = 0;
    while (data->mini_map[i])
    {
        j = 0;
        while (data->mini_map[i][j])
        {
            if (data->mini_map[i][j] == 'N' || data->mini_map[i][j] == 'W' || data->mini_map[i][j] == 'S' || data->mini_map[i][j] == 'E')
            {
                data->player_y = (double)i;
                data->player_x = (double)j;
            }
            j++;
        }
        i++;
    }
    new_x = data->player_x;
    new_y = data->player_y;
    if (keycode == 65361) // left
        new_x--;
    else if (keycode == 65363) // right
        new_x++;
    else if (keycode == 65362) // up
        new_y--;
    else if (keycode == 65364) // down
        new_y++;
    if (new_x >= 0 && new_x < data->map_width && new_y >= 0 && new_y < data->map_height)
    {
        if (data->mini_map[(int)new_y][(int)new_x] == '0')
        {
            data->mini_map[(int)data->player_y][(int)data->player_x] = '0';
            data->mini_map[(int)new_y][(int)new_x] = 'N';
            data->player_x = new_x;
            data->player_y = new_y;
        }
    }
    draw_mini_map(data);
    return (0);
}

int press_key(int keycode, t_data *data)
{
    if (keycode == 65307)
        exit(0);
    else if (keycode == 65361)
        move_player(data, keycode);
    else if (keycode == 65363)
        move_player(data, keycode);
    else if (keycode == 65362)
        move_player(data, keycode);
    else if (keycode == 65364)
        move_player(data, keycode);
    return (0);
}
