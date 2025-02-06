/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahlaqqa <aahlaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 14:35:21 by ahmed             #+#    #+#             */
/*   Updated: 2025/02/06 15:46:54 by aahlaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	check_bounds(t_data *data)
{
	if (data->mini_map[(int)data->new_y][(int)data->new_x] == '0')
	{
		data->mini_map[(int)data->player_y][(int)data->player_x] = '0';
		data->mini_map[(int)data->new_y][(int)data->new_x] = 'N';
		data->player_x = data->new_x;
		data->player_y = data->new_y;
	}
}

void	key_movement(t_data *data, int keycode)
{
	if (keycode == 65361)
		data->new_x--;
	else if (keycode == 65363)
		data->new_x++;
	else if (keycode == 65362)
		data->new_y--;
	else if (keycode == 65364)
		data->new_y++;
}

void	check_if_condition(t_data *data)
{
	if (data->mini_map[data->player_i][data->player_j] == 'N'
		|| data->mini_map[data->player_i][data->player_j] == 'W'
		|| data->mini_map[data->player_i][data->player_j] == 'S'
		|| data->mini_map[data->player_i][data->player_j] == 'E')
	{
		data->player_y = (double)data->player_i;
		data->player_x = (double)data->player_j;
	}
}

int	move_player(t_data *data, int keycode)
{
	data->player_x = 0;
	data->player_y = 0;
	data->player_i = 0;
	while (data->mini_map[data->player_i])
	{
		data->player_j = 0;
		while (data->mini_map[data->player_i][data->player_j])
		{
			check_if_condition(data);
			data->player_j++;
		}
		data->player_i++;
	}
	data->new_x = data->player_x;
	data->new_y = data->player_y;
	key_movement(data, keycode);
	if (data->new_x >= 0 && data->new_x < data->map_width && data->new_y >= 0
		&& data->new_y < data->map_height)
		check_bounds(data);
	draw_mini_map(data);
	return (0);
}

int	press_key(int keycode, t_data *data)
{
	if (keycode == 65307)
		exit(0);
	else if (keycode == 65361)
		move_player(data, keycode);
	else if (keycode == 65363)
		move_player(data, keycode);
	else if (keycode == 65362)
		move_player(data, keycode);
	else if (keycode == 65364)
		move_player(data, keycode);
	return (0);
}
