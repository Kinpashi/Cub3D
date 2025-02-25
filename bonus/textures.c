/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahlaqqa <aahlaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 14:46:38 by aahlaqqa          #+#    #+#             */
/*   Updated: 2025/02/22 14:49:39 by aahlaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void load_textures(t_data *data)
{
    data->no_texture_img = mlx_xpm_file_to_image(data->mlx, data->no_texture, &data->no_tex_width, &data->no_tex_height);
    if (!data->no_texture_img)
    {
        printf("Error\n Failed to load North texture: %s\n", data->no_texture);
        exit(1);
    }
    data->so_texture_img = mlx_xpm_file_to_image(data->mlx, data->so_texture, &data->so_tex_width, &data->so_tex_height);
    if (!data->so_texture_img)
    {
        printf("Error\n Failed to load South texture: %s\n", data->so_texture);
        mlx_destroy_image(data->mlx, data->no_texture_img);
        exit(1);
    }
    data->we_texture_img = mlx_xpm_file_to_image(data->mlx, data->we_texture, &data->we_tex_width, &data->we_tex_height);
    if (!data->we_texture_img)
    {
        printf("Error\n Failed to load West texture: %s\n", data->we_texture);
        mlx_destroy_image(data->mlx, data->no_texture_img);
        mlx_destroy_image(data->mlx, data->so_texture_img);
        exit(1);
    }
    data->ea_texture_img = mlx_xpm_file_to_image(data->mlx, data->ea_texture, &data->ea_tex_width, &data->ea_tex_height);
    if (!data->ea_texture_img)
    {
        printf("Error\n Failed to load East texture: %s\n", data->ea_texture);
        mlx_destroy_image(data->mlx, data->no_texture_img);
        mlx_destroy_image(data->mlx, data->so_texture_img);
        mlx_destroy_image(data->mlx, data->we_texture_img);
        exit(1);
    }
}

void get_texture_data(t_data *data)
{
    data->no_texture_data = (int *)mlx_get_data_addr(data->no_texture_img, &data->bits_per_pixel, &data->size_line, &data->endian);
    if (!data->no_texture_data)
    {
        printf("Error\n Failed to get data address for North texture.\n");
        exit(1);
    }
    data->so_texture_data = (int *)mlx_get_data_addr(data->so_texture_img, &data->bits_per_pixel, &data->size_line, &data->endian);
    if (!data->so_texture_data)
    {
        printf("Error\n Failed to get data address for South texture.\n");
        exit(1);
    }
    data->we_texture_data = (int *)mlx_get_data_addr(data->we_texture_img, &data->bits_per_pixel, &data->size_line, &data->endian);
    if (!data->we_texture_data)
    {
        printf("Error\n Failed to get data address for West texture.\n");
        exit(1);
    }
    data->ea_texture_data = (int *)mlx_get_data_addr(data->ea_texture_img, &data->bits_per_pixel, &data->size_line, &data->endian);
    if (!data->ea_texture_data)
    {
        printf("Error\n Failed to get data address for East texture.\n");
        exit(1);
    }
}
