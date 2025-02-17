/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_rgb_colors.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahlaqqa <aahlaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 23:57:58 by aahlaqqa          #+#    #+#             */
/*   Updated: 2025/02/17 16:53:57 by aahlaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	handle_rgb(int red, int green, int blue)
{
	return (red << 16 | green << 8 | blue);
}

void	init_data(t_data *data)
{
	data->floor_color = handle_rgb(data->floor[0], data->floor[1],
			data->floor[2]);
	data->cell_color = handle_rgb(data->cell[0], data->cell[1], data->cell[2]);
}
