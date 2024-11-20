/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_rgb_colors.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahlaqqa <aahlaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 23:57:58 by aahlaqqa          #+#    #+#             */
/*   Updated: 2024/11/21 00:31:50 by aahlaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "cub3D.h"

int handle_rgb(int red, int green, int blue)
{
    return (red << 16 | green << 8 | blue);
}

void draw_window(t_data *data)
{
    int color;
    int x;
    int y;

    color = 0;
    y = 0;
    color = handle_rgb(data->floor[0], data->floor[1], data->floor[2]);
    while (y < 500)
    {
        x = 0;
        while (x < 500)
        {
            mlx_pixel_put(data->mlx,data->mlx_win, x, y, color);
            x++;
        }
        y++;
    }
}
