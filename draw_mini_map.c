/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_mini_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmed <ahmed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 18:34:38 by aahlaqqa          #+#    #+#             */
/*   Updated: 2025/01/25 13:55:22 by ahmed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void draw_mini_map(t_data *data)
{
    int x, y;
    int map_x, map_y;
    int tile_size;
    void *img;
    char *img_data;
    int color;
    int mini_map_display_width = 100;
    int mini_map_display_height = 100;
    int view_width = 5;  // Number of tiles to display horizontally
    int view_height = 5; // Number of tiles to display vertically
    int start_x, start_y;

    // Calculate the map dimensions
    data->map_height = 0;
    while (data->mini_map[data->map_height])
        data->map_height++;
    data->map_width = 0;
    int i = 0;
    while (data->mini_map[0][i])
    {
        data->map_width++;
        i++;
    }

    // Determine tile size to fit within mini-map display dimensions
    tile_size = mini_map_display_width / view_width;
    if (mini_map_display_height / view_height < tile_size)
        tile_size = mini_map_display_height / view_height;

    // Determine the starting position of the visible map area
    start_x = data->player_x - view_width / 2; // Center on player position
    start_y = data->player_y - view_height / 2;

    // Ensure the starting position doesn't exceed map boundaries
    if (start_x < 0)
        start_x = 0;
    if (start_y < 0)
        start_y = 0;
    if (start_x + view_width > data->map_width)
        start_x = data->map_width - view_width;
    if (start_y + view_height > data->map_height)
        start_y = data->map_height - view_height;

    // Create the image for the mini-map
    img = mlx_new_image(data->mlx, view_width * tile_size, view_height * tile_size);
    img_data = mlx_get_data_addr(img, &data->bits_per_pixel, &data->size_line, &data->endian);

    // Render the visible portion of the mini-map
    y = 0;
    while (y < view_height * tile_size)
    {
        x = 0;
        while (x < view_width * tile_size)
        {
            map_x = start_x + x / tile_size;
            map_y = start_y + y / tile_size;

            if (data->mini_map[map_y][map_x] == '1') // Wall
                color = 0xFF0000;
            else if (data->mini_map[map_y][map_x] == '0') // Empty space
                color = 0xFFFFFF;
            else if (data->mini_map[map_y][map_x] == 'N' || data->mini_map[map_y][map_x] == 'W' ||
                     data->mini_map[map_y][map_x] == 'E' || data->mini_map[map_y][map_x] == 'S') // Player
                color = 0x9933FF;
            else
                color = 0x000000;

            *(int *)(img_data + (y * data->size_line + x * (data->bits_per_pixel / 8))) = color;
            x++;
        }
        y++;
    }

    // Display the mini-map in the window
    mlx_put_image_to_window(data->mlx, data->mlx_win, img, 0, 0);

    // Destroy the image to prevent memory leaks
    mlx_destroy_image(data->mlx, img);
}
