/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_rgb_colors.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahlaqqa <aahlaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 23:57:58 by aahlaqqa          #+#    #+#             */
/*   Updated: 2024/11/21 19:42:40 by aahlaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int handle_rgb(int red, int green, int blue)
{
    return (red << 16 | green << 8 | blue);
}

void set_pixel(char *pixel_buffer, int x, int y, int color, int line_len, int bits_per_pixel)
{
    int offset;

    offset = (y * line_len) + (x * (bits_per_pixel / 8));
    *(int *)(pixel_buffer + offset) = color;
}

void draw_window(t_data *data)
{
    int color;
    int x;
    int y;
    char *pixel_buffer;

    color = 0;
    y = 0;
    color = handle_rgb(data->floor[0], data->floor[1], data->floor[2]);
    data->img = mlx_new_image(data->mlx, 500, 500);
    pixel_buffer = mlx_get_data_addr(data->img, &data->bits_per_pixel, &data->size_line, &data->endian);
    while (y < 500)
    {
        x = 0;
        while (x < 500)
        {
            set_pixel(pixel_buffer, x, y, color, data->size_line, data->bits_per_pixel);
            x++;
        }
        y++;
    }
    mlx_put_image_to_window(data->mlx,data->mlx_win, data->img, 0, 0);
}


// bits_per_pixel : This indicat how many bits are used to represent each pixel in the image.
// size_line : This represent the total number of bytes in a single row of pixels in the image.
// endian : byte order for sortring pixel data : 0 for LSB and 1 for MSB
