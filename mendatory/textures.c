/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahlaqqa <aahlaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 14:46:38 by aahlaqqa          #+#    #+#             */
/*   Updated: 2025/02/18 17:34:16 by aahlaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void load_textures(t_data *data)
{
    
    data->no_texture_img = mlx_xpm_file_to_image(data->mlx, data->no_texture, &data->tex_width, &data->tex_height);
    data->so_texture_img = mlx_xpm_file_to_image(data->mlx, data->so_texture, &data->tex_width, &data->tex_height);
    data->we_texture_img = mlx_xpm_file_to_image(data->mlx, data->we_texture, &data->tex_width, &data->tex_height);
    data->ea_texture_img = mlx_xpm_file_to_image(data->mlx, data->ea_texture, &data->tex_width, &data->tex_height);

    if (!data->no_texture_img || !data->so_texture_img || !data->we_texture_img || !data->ea_texture_img)
    {
        printf("Error\n No image is set !!\n");
        exit(1);
    }
}

void get_texture_data(t_data *data)
{
    data->no_texture_data = (int *)mlx_get_data_addr(data->no_texture_img, &data->bits_per_pixel, &data->size_line, &data->endian);
    data->so_texture_data = (int *)mlx_get_data_addr(data->so_texture_img, &data->bits_per_pixel, &data->size_line, &data->endian);
    data->we_texture_data = (int *)mlx_get_data_addr(data->we_texture_img, &data->bits_per_pixel, &data->size_line, &data->endian);
    data->ea_texture_data = (int *)mlx_get_data_addr(data->ea_texture_img, &data->bits_per_pixel, &data->size_line, &data->endian);
}
