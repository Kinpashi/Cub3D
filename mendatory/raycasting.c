/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahlaqqa <aahlaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 16:16:04 by aahlaqqa          #+#    #+#             */
/*   Updated: 2025/02/18 22:38:35 by aahlaqqa         ###   ########.fr       */
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

            if ((data->mini_map[i][j] == 'N' || data->mini_map[i][j] == 'S' ||
                 data->mini_map[i][j] == 'W' || data->mini_map[i][j] == 'E') &&
                (data->player_x == 0 && data->player_y == 0))
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

void set_pixels(t_data *data, int x, int y, int color)
{
    char *dest;

    if (x < 0 || x >= SCREEN_WIDTH || y < 0 || y >= SCREEN_HEIGHT)
        return;
    dest = data->r_addr + (y * data->size_line + x * (data->bits_per_pixel / 8));
    *(unsigned int *)dest = color;
}

void raycasting(t_data *data)
{
    int x;
    int y;
    // int r_color;
    int color;
    int *texture;

    x = 0;
    // r_color = 0xFF3333;
    texture = NULL;
    data->r_img = mlx_new_image(data->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
    data->r_addr = mlx_get_data_addr(data->r_img, &data->bits_per_pixel, &data->size_line, &data->endian);
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
        if (data->side == 0 && data->raydir_x > 0)
            texture = data->ea_texture_data;
        else if (data->side == 0 && data->raydir_x < 0)
            texture = data->we_texture_data;
        else if (data->side == 1 && data->raydir_y > 0)
            texture = data->so_texture_data;
        else if (data->side == 1 && data->raydir_y < 0)
            texture = data->no_texture_data;
        if (data->side == 0)
            data->perpWallDist = (data->sideDist_x - data->deltaDist_x);
        else
            data->perpWallDist = (data->sideDist_y - data->deltaDist_y);
        if (data->perpWallDist < 0.0001)
            data->perpWallDist = 0.0001;
        data->line_height = (int)(SCREEN_HEIGHT / data->perpWallDist);
        if (data->line_height > SCREEN_HEIGHT * 10)
            data->line_height = SCREEN_HEIGHT * 10;
        data->drawStart = -data->line_height / 2 + SCREEN_HEIGHT / 2;
        if (data->drawStart < 0)
            data->drawStart = 0;
        data->drawEnd = data->line_height / 2 + SCREEN_HEIGHT / 2;
        if (data->drawEnd >= SCREEN_HEIGHT)
            data->drawEnd = SCREEN_HEIGHT - 1;
        if (data->side == 0)
            data->wallx = data->player_y * data->perpWallDist + data->raydir_y;
        else
            data->wallx = data->player_x * data->perpWallDist + data->raydir_x;
        data->wallx -= floor(data->wallx);
        data->txt_x = (int)(data->wallx * ((double)data->tex_width));
        if ((data->side == 0 && data->raydir_x > 0) || (data->side == 1 && data->raydir_y < 0))
            data->txt_x = 64 - data->txt_x - 1;
        y = 0;
        while (y < SCREEN_HEIGHT)
        {
            if (y < data->drawStart)
                set_pixels(data, x, y, data->cell_color);
            else if (y >= data->drawStart && y < data->drawEnd)
            {
                data->txt_y = (int)(((y - data->drawStart) * data->tex_height) / data->line_height);
                color = texture[data->txt_y * data->tex_width + data->txt_x];
                set_pixels(data, x, y, color);
            }
            else
                set_pixels(data, x, y, data->floor_color);
            y++;
        }
        x++;
    }
    mlx_put_image_to_window(data->mlx, data->mlx_win, data->r_img, 0, 0);
}
