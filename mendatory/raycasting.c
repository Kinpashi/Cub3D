/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahlaqqa <aahlaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 16:16:04 by aahlaqqa          #+#    #+#             */
/*   Updated: 2025/02/12 12:04:55 by aahlaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void init_dir_and_plan(t_data *data)
{
    int i = 0;
    while (data->mini_map[i])
    {
        int j = 0;
        while (data->mini_map[i][j])
        {
            if (data->mini_map[i][j] == 'N')
            {
                data->dir_x = 0;
                data->dir_y = -1;
                data->plan_x = 0.50;
                data->plan_y = 0;
            }
            else if (data->mini_map[i][j] == 'S')
            {
                data->dir_x = 0;
                data->dir_y = 1;
                data->plan_x = -0.50;
                data->plan_y = 0;
            }
            else if (data->mini_map[i][j] == 'E')
            {
                data->dir_x = 1;
                data->dir_y = 0;
                data->plan_x = 0;
                data->plan_y = 0.50;
            }
            else if (data->mini_map[i][j] == 'W')
            {
                data->dir_x = -1;
                data->dir_y = 0;
                data->plan_x = 0;
                data->plan_y = -0.50;
            }
            if (data->mini_map[i][j] == 'N' || data->mini_map[i][j] == 'S' || data->mini_map[i][j] == 'W' || data->mini_map[i][j] == 'E')
            {
                data->player_x = i + 0.5;
                data->player_y = j + 0.5;
            }
            j++;
        }
        i++;
    }
}

void perform_dda(t_data *data)
{
    while (data->hit == 0)
    {
        if (data->sideDist_x < data->sideDist_y)
        {
            data->sideDist_x += data->deltaDist_x;
            data->raymap_x += data->step_x;
            data->side = 0;
        }
        else
        {
            data->sideDist_y += data->deltaDist_y;
            data->raymap_y += data->step_y;
            data->side = 1;
        }
        if (data->mini_map[data->raymap_x][data->raymap_y] == '1')
            data->hit = 1;
    }
}

void raycasting(t_data *data)
{
    int x;

    init_dir_and_plan(data);
    x = 0;
    while (x < SCREEN_WIDTH)
    {
        data->camera_x = 2.0 * x / SCREEN_WIDTH - 1;
        data->raydir_x = data->dir_x + data->plan_x * data->camera_x;
        data->raydir_y = data->dir_y + data->plan_y * data->camera_x;
        data->raymap_x = (int)data->player_x;
        data->raymap_y = (int)data->player_y;
        data->deltaDist_x = fabs(1 / data->raydir_x);
        data->deltaDist_y = fabs(1 / data->raydir_y);
        data->hit = 0;
        if (data->raydir_x < 0)
        {
            data->step_x = -1;
            data->sideDist_x = (data->player_x - data->raymap_x) * data->deltaDist_x;
        }
        else
        {
            data->step_x = 1;
            data->sideDist_x = (data->raymap_x + 1.0 - data->player_x) * data->deltaDist_x;
        }
        if (data->raydir_y < 0)
        {
            data->step_y = -1;
            data->sideDist_y = (data->player_y - data->raymap_y) * data->deltaDist_y;
        }
        else
        {
            data->step_y = 1;
            data->sideDist_y = (data->raymap_y + 1.0 - data->player_y) * data->deltaDist_y;
        }
        perform_dda(data);
        if (data->side == 0)
            data->perpWallDist = (data->sideDist_x - data->deltaDist_x);
        else
            data->perpWallDist = (data->sideDist_y - data->deltaDist_y);
        if (data->perpWallDist < 0.0001)
            data->perpWallDist = 0.0001;
        // if (data->perpWallDist < 0)
        //     data->perpWallDist *= -1;
        data->line_height = (int)(SCREEN_HEIGHT / data->perpWallDist);
        if (data->line_height > SCREEN_HEIGHT * 10)
            data->line_height = SCREEN_HEIGHT * 10;
        data->drawStart = -data->line_height / 2 + SCREEN_HEIGHT / 2;
        if (data->drawStart < 0)
            data->drawStart = 0;
        data->drawEnd = data->line_height / 2 + SCREEN_HEIGHT / 2;
        if (data->drawEnd >= SCREEN_HEIGHT)
            data->drawEnd = SCREEN_HEIGHT - 1;
        x++;
    }
}
