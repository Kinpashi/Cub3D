/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahlaqqa <aahlaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 16:17:59 by aahlaqqa          #+#    #+#             */
/*   Updated: 2025/03/08 15:59:29 by aahlaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	move_up(t_data *data)
{
	double	new_x;
	double	new_y;

	new_x = data->player_x + data->dir_x * MOVE_SPEED;
	new_y = data->player_y + data->dir_y * MOVE_SPEED;
	if (data->mini_map[(int)new_x][(int)new_y] != '1')
	{
		if (!(data->mini_map[(int)new_x][(int)data->player_y] == '1'
			&& data->mini_map[(int)data->player_x][(int)new_y] == '1'))
		{
			data->player_x = new_x;
			data->player_y = new_y;
		}
	}
}

void	move_down(t_data *data)
{
	double	new_x;
	double	new_y;

	new_x = data->player_x - data->dir_x * MOVE_SPEED;
	new_y = data->player_y - data->dir_y * MOVE_SPEED;
	if (data->mini_map[(int)new_x][(int)new_y] != '1')
	{
		if (!(data->mini_map[(int)new_x][(int)data->player_y] == '1'
			&& data->mini_map[(int)data->player_x][(int)new_y] == '1'))
		{
			data->player_x = new_x;
			data->player_y = new_y;
		}
	}
}

void	move_left(t_data *data)
{
	double	new_x;
	double	new_y;

	new_x = data->player_x - data->plan_x * MOVE_SPEED;
	new_y = data->player_y - data->plan_y * MOVE_SPEED;
	if (data->mini_map[(int)new_x][(int)new_y] != '1')
	{
		if (!(data->mini_map[(int)new_x][(int)data->player_y] == '1'
			&& data->mini_map[(int)data->player_x][(int)new_y] == '1'))
		{
			data->player_x = new_x;
			data->player_y = new_y;
		}
	}
}

void	move_right(t_data *data)
{
	double	new_x;
	double	new_y;

	new_x = data->player_x + data->plan_x * MOVE_SPEED;
	new_y = data->player_y + data->plan_y * MOVE_SPEED;
	if (data->mini_map[(int)new_x][(int)new_y] != '1')
	{
		if (!(data->mini_map[(int)new_x][(int)data->player_y] == '1'
			&& data->mini_map[(int)data->player_x][(int)new_y] == '1'))
		{
			data->player_x = new_x;
			data->player_y = new_y;
		}
	}
}
