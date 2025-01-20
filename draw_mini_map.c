/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_mini_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmed <ahmed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 18:34:38 by aahlaqqa          #+#    #+#             */
/*   Updated: 2025/01/20 16:46:30 by ahmed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void draw_mini_map(t_data *data)
{
    int x;
    int y;
    int map_x;
    int map_y;
    int tile_size;
    void *img;
    char *img_data;
    int color;

    tile_size = 20;
    data->map_height = 5;
    data->map_width = 9;
    img = mlx_new_image(data->mlx, data->map_width * tile_size, data->map_height * tile_size);
    img_data = mlx_get_data_addr(img, &data->bits_per_pixel, &data->size_line, &data->endian);
    y = 0;
    while (y < data->map_height * tile_size)
    {
        x = 0;
        while (x < data->map_width * tile_size)
        {
            map_x = x / tile_size;
            map_y = y / tile_size;
            if (data->mini_map[map_y][map_x] == '1')
                color = 0xFF0000;
            else if (data->mini_map[map_y][map_x] == '0')
                color = 0xFFFFFF;
            else if (data->mini_map[map_y][map_x] == 'N' || data->mini_map[map_y][map_x] == 'W' || 
                     data->mini_map[map_y][map_x] == 'E' || data->mini_map[map_y][map_x] == 'S')
                color = 0x9933FF;
            else
                color = 0x000000;
            *(int *)(img_data + (y * data->size_line + x * (data->bits_per_pixel / 8))) = color;
            x++;
        }
        y++;
    }
    mlx_put_image_to_window(data->mlx, data->mlx_win, img, 0, 0);
    mlx_destroy_image(data->mlx, img);
}

