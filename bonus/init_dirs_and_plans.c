/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_dirs_and_plans.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahlaqqa <aahlaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 02:24:22 by aahlaqqa          #+#    #+#             */
/*   Updated: 2025/03/05 02:34:10 by aahlaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	init_north(t_data *data)
{
	data->dir_x = 0;
	data->dir_y = -1;
	data->plan_x = 0.50;
	data->plan_y = 0;
}

void	init_south(t_data *data)
{
	data->dir_x = 0;
	data->dir_y = 1;
	data->plan_x = -0.50;
	data->plan_y = 0;
}

void	init_east(t_data *data)
{
	data->dir_x = 1;
	data->dir_y = 0;
	data->plan_x = 0;
	data->plan_y = 0.50;
}

void	init_west(t_data *data)
{
	data->dir_x = -1;
	data->dir_y = 0;
	data->plan_x = 0;
	data->plan_y = -0.50;
}

void	check_if_position(t_data *data, int *i, int *j)
{
	if ((data->mini_map[*i][*j] == 'N' || data->mini_map[*i][*j] == 'S'
			|| data->mini_map[*i][*j] == 'W' || data->mini_map[*i][*j] == 'E')
		&& (data->player_x == 0 && data->player_y == 0))
	{
		data->player_x = *i + 0.5;
		data->player_y = *j + 0.5;
	}
}
