/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rander_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahlaqqa <aahlaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 15:41:22 by aahlaqqa          #+#    #+#             */
/*   Updated: 2025/02/05 16:34:37 by aahlaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void draw_player_as_circle(t_data *data, int center_x, int center_y, int radius)
{
    int x;
    int y;
    int dx;
    int dy;
    int raduis_square;
    int color;

    raduis_square = radius * radius;
    color = 0xFFFF00;
    y = -radius;
    while (y <= radius)
    {
        x = -radius;
        while (x <= radius)
        {
            dx = center_x + x;
            dy = center_y + y;
            if (x * x + y * y <= raduis_square)
            {
                *(int *)(data->img_data + (dy * data->size_line + dx * (data->bits_per_pixel / 8))) = color;
            }
            x++;
        }
        y++;
    }
}
