/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahlaqqa <aahlaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 16:16:04 by aahlaqqa          #+#    #+#             */
/*   Updated: 2025/03/14 16:38:42 by aahlaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	init_dir_and_plan(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->mini_map[i])
	{
		j = 0;
		while (data->mini_map[i][j])
		{
			if (data->mini_map[i][j] == 'N')
				init_north(data);
			else if (data->mini_map[i][j] == 'S')
				init_south(data);
			else if (data->mini_map[i][j] == 'E')
				init_east(data);
			else if (data->mini_map[i][j] == 'W')
				init_west(data);
			check_if_position(data, &i, &j);
			j++;
		}
		i++;
	}
}

void	perform_dda(t_data *data)
{
	while (data->hit == 0)
	{
		if (data->sidedistx < data->sidedisty)
		{
			data->sidedistx += data->deltadistx;
			data->raymap_x += data->step_x;
			data->side = 0;
		}
		else
		{
			data->sidedisty += data->deltadisty;
			data->raymap_y += data->step_y;
			data->side = 1;
		}
		if (data->mini_map[data->raymap_x][data->raymap_y] == '1')
			data->hit = 1;
	}
}

void	set_pixels(t_data *data, int x, int y, int color)
{
	char	*dest;

	if (x < 0 || x >= SCREEN_WIDTH || y < 0 || y >= SCREEN_HEIGHT)
		return ;
	dest = data->r_addr + (y * data->size_line + x * (data->bits_per_pixel
				/ 8));
	*(unsigned int *)dest = color;
}

void	raycasting(t_data *data)
{
	int	x;

	x = 0;
	while (x < SCREEN_WIDTH)
	{
		init_vars(data, &x);
		handle_raydir_x(data);
		handle_raydir_y(data);
		perform_dda(data);
		init_textures(data);
		calculate_wall(data);
		data->step = 1.0 * data->tex_height / data->line_height;
		data->texpos = (data->drawstart - SCREEN_HEIGHT / 2 + data->line_height
				/ 2) * data->step;
		draw_column(data, x);
		x++;
	}
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->r_img, 0, 0);
}
