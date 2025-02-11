/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahlaqqa <aahlaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 16:16:04 by aahlaqqa          #+#    #+#             */
/*   Updated: 2025/02/11 17:30:11 by aahlaqqa         ###   ########.fr       */
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
            j++;
        }
        i++;
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
        x++;
    }
}
