/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahlaqqa <aahlaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 14:35:21 by ahmed             #+#    #+#             */
/*   Updated: 2025/03/05 16:29:23 by aahlaqqa         ###   ########.fr       */
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
