/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahlaqqa <aahlaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 17:56:11 by aahlaqqa          #+#    #+#             */
/*   Updated: 2025/03/05 18:04:17 by aahlaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void rotate_player(t_data *data, double rotation_angle)
{
	double old_dir_x;
	double old_plane_x;

	old_dir_x = data->dir_x;
	old_plane_x = data->plan_x;
	data->dir_x = data->dir_x * cos(rotation_angle) - data->dir_y * sin(rotation_angle);
	data->dir_y = old_dir_x * sin(rotation_angle) + data->dir_y * cos(rotation_angle);
	data->plan_x = data->plan_x * cos(rotation_angle) - data->plan_y * sin(rotation_angle);
	data->plan_y = old_plane_x * sin(rotation_angle) + data->plan_y * cos(rotation_angle);
	raycasting(data);
}

// Assuming you're using SDL or another graphics library
void handle_mouse_movement(t_data *data, int mouse_x, int mouse_y)
{
	static int last_mouse_x = 0;
	static int last_mouse_y = 0;

	// Calculate mouse movement delta
	int delta_x = mouse_x - last_mouse_x;
	int delta_y = mouse_y - last_mouse_y;

	// Update last mouse positions
	last_mouse_x = mouse_x;
	last_mouse_y = mouse_y;

	// Sensitivity control (adjust as needed)
	double sensitivity = 0.005;

	// Rotate player based on horizontal mouse movement
	double rotation_angle = -delta_x * sensitivity;
	rotate_player(data, rotation_angle);

	// Optional: Add vertical look (pitch) if needed
	// This would involve modifying your camera's vertical angle
}
