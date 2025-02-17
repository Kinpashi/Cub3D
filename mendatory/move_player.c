/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahlaqqa <aahlaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 14:35:21 by ahmed             #+#    #+#             */
/*   Updated: 2025/02/17 15:46:39 by aahlaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void check_bounds(t_data *data)
{
	if (data->mini_map[(int)data->new_y][(int)data->new_x] == '0')
	{
		data->mini_map[(int)data->player_y][(int)data->player_x] = '0';
		data->mini_map[(int)data->new_y][(int)data->new_x] = 'N';
		data->player_x = data->new_x;
		data->player_y = data->new_y;
	}
}

// void key_movement(t_data *data, int keycode)
// {
// 	if (keycode == 115)
// 		data->new_x--;
// 	else if (keycode == 119)
// 		data->new_x++;
// 	else if (keycode == 95)
// 		data->new_y--;
// 	else if (keycode == 100)
// 		data->new_y++;
// }

// void check_if_condition(t_data *data)
// {
// 	if (data->mini_map[data->player_i][data->player_j] == 'N' || data->mini_map[data->player_i][data->player_j] == 'W' || data->mini_map[data->player_i][data->player_j] == 'S' || data->mini_map[data->player_i][data->player_j] == 'E')
// 	{
// 		data->player_y = (double)data->player_i;
// 		data->player_x = (double)data->player_j;
// 	}
// }
// int move_player(t_data *data, int keycode)
// {
// 	data->player_i = 0;
// 	while (data->mini_map[data->player_i])
// 	{
// 		data->player_j = 0;
// 		while (data->mini_map[data->player_i][data->player_j])
// 		{
// 			check_if_condition(data);
// 			data->player_j++;
// 		}
// 		data->player_i++;
// 	}
// 	data->new_x = data->player_x;
// 	data->new_y = data->player_y;
// 	key_movement(data, keycode);
// 	if (data->new_x >= 0 && data->new_x < data->map_width &&
// 		data->new_y >= 0 && data->new_y < data->map_height &&
// 		data->mini_map[(int)data->new_y][(int)data->new_x] == '0')
// 	{
// 		data->mini_map[(int)data->player_y][(int)data->player_x] = '0';
// 		if (data->dir_y < -0.5)
// 			data->mini_map[(int)data->new_y][(int)data->new_x] = 'N';
// 		else if (data->dir_y > 0.5)
// 			data->mini_map[(int)data->new_y][(int)data->new_x] = 'S';
// 		else if (data->dir_x < -0.5)
// 			data->mini_map[(int)data->new_y][(int)data->new_x] = 'W';
// 		else if (data->dir_x > 0.5)
// 			data->mini_map[(int)data->new_y][(int)data->new_x] = 'E';
// 		data->player_x = data->new_x;
// 		data->player_y = data->new_y;
// 	}
// 	raycasting(data);
// 	return (0);
// }