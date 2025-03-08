/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterate_color_map.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahlaqqa <aahlaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 16:13:55 by aahlaqqa          #+#    #+#             */
/*   Updated: 2025/03/08 17:44:06 by aahlaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	allocate_and_copy_prefix1(t_data *data, int i, int *j)
{
	*data->prefix1 = malloc(sizeof(char) * 100);
	if (!(*data->prefix1))
		print_malloc_error_message();
	*j = 0;
	while (data->my_color[i][*j] != ' ' && data->my_color[i][*j] != '\0')
	{
		(*data->prefix1)[*j] = data->my_color[i][*j];
		(*j)++;
	}
	(*data->prefix1)[*j] = '\0';
	if ((*data->prefix1)[0] == 'F')
		data->color_counter++;
	if (data->color_counter > 1)
		print_incorrect_prefix_error_message();
	if (data->my_color[i][*j] == ' ')
		(*j)++;
}

void	allocate_and_copy_rest(t_data *data, int i, int j)
{
	int	w;

	w = 0;
	*data->rest = malloc(sizeof(char) * 100);
	if (!(*data->rest))
		print_malloc_error_message();
	while (data->my_color[i][j] != '\0')
	{
		while (data->my_color[i][j] == '\t' || data->my_color[i][j] == ' ')
			j++;
		(*data->rest)[w] = data->my_color[i][j];
		w++;
		j++;
	}
	(*data->rest)[w] = '\0';
}

void	iterate_color_map(t_data *data, int *i)
{
	int	j;

	while (data->my_color[*i])
	{
		allocate_and_copy_prefix1(data, *i, &j);
		allocate_and_copy_rest(data, *i, j);
		check_data(data);
		(*i)++;
	}
}
