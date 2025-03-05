/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahlaqqa <aahlaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 14:46:38 by aahlaqqa          #+#    #+#             */
/*   Updated: 2025/03/05 16:47:23 by aahlaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	load_textures(t_data *data)
{
	data->no_texture_img = mlx_xpm_file_to_image(data->mlx, data->no_texture,
			&data->no_tex_width, &data->no_tex_height);
	if (!data->no_texture_img)
	{
		printf("Error\n Failed to load North texture: %s\n", data->no_texture);
		exit(1);
	}
	data->so_texture_img = mlx_xpm_file_to_image(data->mlx, data->so_texture,
			&data->so_tex_width, &data->so_tex_height);
	if (!data->so_texture_img)
		free_texture_one(data);
	data->we_texture_img = mlx_xpm_file_to_image(data->mlx, data->we_texture,
			&data->we_tex_width, &data->we_tex_height);
	if (!data->we_texture_img)
		free_texture_two(data);
	data->ea_texture_img = mlx_xpm_file_to_image(data->mlx, data->ea_texture,
			&data->ea_tex_width, &data->ea_tex_height);
	if (!data->ea_texture_img)
		free_texture_three(data);
}

void	get_texture_data(t_data *data)
{
	data->no_texture_data = (int *)mlx_get_data_addr(data->no_texture_img,
			&data->bits_per_pixel, &data->size_line, &data->endian);
	if (!data->no_texture_data)
		texture_north_error_message();
	data->so_texture_data = (int *)mlx_get_data_addr(data->so_texture_img,
			&data->bits_per_pixel, &data->size_line, &data->endian);
	if (!data->so_texture_data)
		texture_south_error_message();
	data->we_texture_data = (int *)mlx_get_data_addr(data->we_texture_img,
			&data->bits_per_pixel, &data->size_line, &data->endian);
	if (!data->we_texture_data)
		texture_west_error_message();
	data->ea_texture_data = (int *)mlx_get_data_addr(data->ea_texture_img,
			&data->bits_per_pixel, &data->size_line, &data->endian);
	if (!data->ea_texture_data)
		texture_east_error_message();
}
