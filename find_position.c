/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_position.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahlaqqa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 15:52:29 by aahlaqqa          #+#    #+#             */
/*   Updated: 2024/11/24 15:52:31 by aahlaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void find_player_position(t_data *data)
{
    int i;
    int j;

    i = 0;
    data->player_x = 0;
    data->player_y = 0;
    while (data->mini_map[i])
    {
        j = 0;
        while (data->mini_map[i][j])
        {
            if (data->mini_map[i][j] == 'N' || data->mini_map[i][j] == 'W' || data->mini_map[i][j] == 'S' || data->mini_map[i][j] == 'E')
            {
                data->player_x = i;
                data->player_y = j;
            }
            j++;
        }
        i++;
    }
}

void calculat_dda(t_data *data, double raydirx, double raydiry)
{
    data->map_x = 0;
    data->map_y = 0;
    data->deltadistx = 0;
    data->deltadisty = 0;
    data->stepx = 0;
    data->stepy = 0;
    data->sidedistx = 0;
    data->sidedisty = 0;
    data->wall = 0;
    data->perpwalldist = 0;
    data->raydistans = 0;

    data->map_x = data->player_x;
    data->map_y = data->player_y;
    data->deltadistx = fabs(1 / raydirx);
    data->deltadisty = fabs(1 / raydiry);
    if (raydirx < 0)
    {
        data->stepx = -1;
        data->sidedistx = (data->player_x - data->map_x) * data->deltadistx;
    }
    else
    {
        data->stepx = 1;
        data->sidedistx = (data->map_x + 1 - data->player_x) * data->deltadistx;
    }
    if (raydiry < 0)
    {
        data->stepy = -1;
        data->sidedisty = (data->player_y - data->map_y) * data->deltadisty;
    }
    else
    {
        data->stepy = 1;
        data->sidedisty = (data->map_y + 1 - data->player_y) * data->deltadisty;
    }
    while (!data->wall)
    {
        if (data->sidedistx < data->sidedisty)
        {
            data->sidedistx += data->deltadistx;
            data->map_x += data->stepx;
            data->side = 0;
        }
        else
        {
            data->sidedisty += data->deltadisty;
            data->map_y += data->stepy;
            data->side = 1;
        }
        if (data->mini_map[data->map_x][data->map_y] == '1')
            data->wall = 1;
    }
    if (data->side == 0)
    {
        data->perpwalldist = (data->map_x - data->player_x + (1 - data->stepx) / 2) / raydirx;
    }
    else
    {
        data->perpwalldist = (data->map_y - data->player_y + (1 - data->stepy) / 2) / raydiry;
    }
    data->raydistans = data->perpwalldist;
}
