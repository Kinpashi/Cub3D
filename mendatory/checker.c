/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahlaqqa <aahlaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 17:49:56 by ahmed             #+#    #+#             */
/*   Updated: 2025/03/05 16:14:19 by aahlaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	check_no_identifier(t_data *data)
{
	size_t	i;

	data->count = 0;
	data->prefix = malloc(3 + 1);
	data->texture = malloc(256);
	if (!data->texture || !data->prefix)
		return ;
	i = 0;
	iterate_in_map(&i, data);
	if (data->count != 4)
	{
		printf("Error\n incorrect identifier !");
		exit(1);
	}
}

void	check_data(t_data *data)
{
	data->count1 = check_for_colors((*data->prefix1), data->count1);
	data->len = check_length_color((*data->rest), data->len);
	if (ft_strcmp((*data->prefix1), "F") == 0)
		check_floor_rgb((*data->rest), data);
	else if (ft_strcmp((*data->prefix1), "C") == 0)
		check_cell_rgb((*data->rest), data);
	check_rgb_fllor_range(data);
	check_rgb_cell_range(data);
}
