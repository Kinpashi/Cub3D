/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterate_in_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahlaqqa <aahlaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 16:04:31 by aahlaqqa          #+#    #+#             */
/*   Updated: 2025/03/05 16:04:53 by aahlaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	allocate_and_copy_prefix(t_data *data, size_t i)
{
	data->j = 0;
	*data->prefix = malloc(sizeof(char) * 3);
	if (!(*data->prefix))
		print_malloc_error_message();
	while (data->my_map[i][data->j] != ' ' && data->my_map[i][data->j] != '\0')
	{
		(*data->prefix)[data->j] = data->my_map[i][data->j];
		data->j++;
	}
	(*data->prefix)[data->j] = '\0';
	if (strcmp(*data->prefix, "NO") == 0)
		data->counter++;
	if (data->counter > 1)
		print_incorrect_prefix_error_message();
	while (data->my_map[i][data->j] == ' ')
		data->j++;
}

void	allocate_and_copy_texture(t_data *data, size_t i)
{
	data->y = 0;
	*data->texture = malloc(sizeof(char) * 1000);
	if (!(*data->texture))
		print_malloc_error_message();
	while (data->my_map[i][data->j] != '\0')
	{
		if (data->y >= 999)
			print_incorrect_texture_error_message();
		(*data->texture)[data->y] = data->my_map[i][data->j];
		data->j++;
		data->y++;
	}
	(*data->texture)[data->y] = '\0';
	if (data->y == 0)
		print_incorrect_texture_error_message();
}

void	process_texture_assignment(t_data *data)
{
	data->count = check_for_identifier((*data->prefix), data->count);
	check_texture(*(data->texture), data);
	if (strcmp(*data->prefix, "NO") == 0)
		data->no_texture = strdup(*data->texture);
	else if (strcmp(*data->prefix, "SO") == 0)
		data->so_texture = strdup(*data->texture);
	else if (strcmp(*data->prefix, "WE") == 0)
		data->we_texture = strdup(*data->texture);
	else if (strcmp(*data->prefix, "EA") == 0)
		data->ea_texture = strdup(*data->texture);
	else
		print_incorrect_prefix_error_message();
}

void	iterate_in_map(size_t *i, t_data *data)
{
	while (*i < 4)
	{
		if (!data->my_map[*i] || data->my_map[*i][0] == '\0')
			print_invalid_map_error_message();
		allocate_and_copy_prefix(data, *i);
		allocate_and_copy_texture(data, *i);
		process_texture_assignment(data);
		(*i)++;
	}
}
