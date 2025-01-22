/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_position.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmed <ahmed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 15:52:29 by aahlaqqa          #+#    #+#             */
/*   Updated: 2025/01/22 17:06:50 by ahmed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void calculate_line_hight(t_data *data)
{
    int line_height;
    int draw_start;
    int draw_end;

    line_height = 0;
    draw_start = 0;
    draw_end = 0;
    line_height = (int)(data->screenheight / data->perpwalldist);
    draw_start = -line_height / 2 + data->screenheight / 2;
    draw_end = line_height / 2 + data->screenheight / 2;
    if (draw_start < 0)
        draw_start = 0;
    if (draw_end >= data->screenheight)
        draw_end = data->screenheight - 1;
    data->line_height = line_height;
    data->draw_start = draw_start;
    data->draw_end = draw_end;
}

void calculat_dda(t_data *data, double raydirx, double raydiry) // x = 2.0 y = 0.5
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
    calculate_line_hight(data);
    data->raydistans = data->perpwalldist;
}
