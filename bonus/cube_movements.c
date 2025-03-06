/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube_movements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahlaqqa <aahlaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 14:45:20 by aahlaqqa          #+#    #+#             */
/*   Updated: 2025/03/05 16:25:51 by aahlaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	press_key(int key, t_data *data)
{
	if (key == 65307)
		exit(0);
	if (key == 119)
		data->move_forward = true;
	else if (key == 115)
		data->move_backward = true;
	else if (key == 97)
		data->move_left = true;
	else if (key == 100)
		data->move_right = true;
	else if (key == 65361)
		data->rotate_left = true;
	else if (key == 65363)
		data->rotate_right = true;
	return (0);
}

int	release_key(int key, t_data *data)
{
	if (key == 119)
		data->move_forward = false;
	else if (key == 115)
		data->move_backward = false;
	else if (key == 97)
		data->move_left = false;
	else if (key == 100)
		data->move_right = false;
	else if (key == 65361)
		data->rotate_left = false;
	else if (key == 65363)
		data->rotate_right = false;
	return (0);
}

void	move_player(t_data *data)
{
	if (data->move_forward)
		move_up(data);
	if (data->move_backward)
		move_down(data);
	if (data->move_left)
		move_left(data);
	if (data->move_right)
		move_right(data);
	if (data->rotate_left)
		rotate_left(data);
	if (data->rotate_right)
		rotate_right(data);
}

int	game_loop(t_data *data)
{
	static int	first_frame = 1;

	if (first_frame)
	{
		raycasting(data);
		first_frame = 0;
		return (0);
	}
	if (data->move_backward || data->move_forward || data->move_left
		|| data->move_right || data->rotate_left || data->rotate_right)
	{
		move_player(data);
		raycasting(data);
	}
	return (0);
}

void	setup_hook(t_data *data)
{
	data->move_backward = false;
	data->move_forward = false;
	data->move_left = false;
	data->move_right = false;
	data->rotate_left = false;
	data->rotate_right = false;
}
