/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahlaqqa <aahlaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 02:45:36 by aahlaqqa          #+#    #+#             */
/*   Updated: 2025/03/06 16:20:23 by aahlaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	init_textures(t_data *data)
{
	if (data->side == 0 && data->raydir_x > 0)
	{
		data->r_texture = data->ea_texture_data;
		data->tex_width = data->ea_tex_width;
		data->tex_height = data->ea_tex_height;
	}
	else if (data->side == 0 && data->raydir_x < 0)
	{
		data->r_texture = data->we_texture_data;
		data->tex_width = data->we_tex_width;
		data->tex_height = data->we_tex_height;
	}
	else if (data->side == 1 && data->raydir_y > 0)
	{
		data->r_texture = data->so_texture_data;
		data->tex_width = data->so_tex_width;
		data->tex_height = data->so_tex_height;
	}
	else if (data->side == 1 && data->raydir_y < 0)
	{
		data->r_texture = data->no_texture_data;
		data->tex_width = data->no_tex_width;
		data->tex_height = data->no_tex_height;
	}
}

void	draw_column(t_data *data, int x)
{
	int	y;

	y = 0;
	while (y < SCREEN_HEIGHT)
	{
		if (y < data->drawstart)
			set_pixels(data, x, y, data->cell_color);
		else if (y >= data->drawstart && y < data->drawend)
		{
			data->texy = (int)data->texpos % data->tex_height;
			data->texpos += data->step;
			data->p_color = data->r_texture[data->texy * data->tex_width
				+ data->txt_x];
			if (data->side == 1)
				data->p_color = (data->p_color >> 1) & 8355711;
			set_pixels(data, x, y, data->p_color);
		}
		else
			set_pixels(data, x, y, data->floor_color);
		y++;
	}
}
