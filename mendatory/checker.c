/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmed <ahmed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 17:49:56 by ahmed             #+#    #+#             */
/*   Updated: 2025/02/09 23:29:24 by ahmed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void iterate_in_map(size_t *i, t_data *data)
{
	while (*i < 4)
	{
		data->j = 0;
		data->y = 0;
		for (int i = 0; data->my_map[i]; i++)
			printf("%s\n", data->my_map[i]);
		exit(1);
		while (data->my_map[*i][data->j] != ' ')
		{
			data->prefix[data->j] = data->my_map[*i][data->j];
			data->j++;
		}
		data->prefix[data->j] = '\0';
		if (data->my_map[*i][data->j] == ' ')
			data->j++;
		while (data->my_map[*i][data->j] != '\0')
		{
			data->texture[data->y] = data->my_map[*i][data->j];
			data->j++;
			data->y++;
		}
		data->texture[data->y] = '\0';
		data->count = check_for_identifier(data->prefix, data->count);
		check_texture(data->texture, data);
		(*i)++;
	}
}

void check_no_identifier(t_data *data)
{
	size_t i;

	data->count = 0;
	data->prefix = malloc(3 + 1);
	data->texture = malloc(100);
	if (!data->texture || !data->prefix)
		return;
	i = 0;
	iterate_in_map(&i, data);
	if (data->count != 4)
	{
		printf("Error\n incorrect identifier !");
		exit(1);
	}
}

void check_data(t_data *data)
{
	data->count1 = check_for_colors(data->prefix1, data->count1);
	data->len = check_length_color(data->rest, data->len);
	if (ft_strcmp(data->prefix1, "F") == 0)
		check_floor_rgb(data->rest, data);
	else if (ft_strcmp(data->prefix1, "C") == 0)
		check_cell_rgb(data->rest, data);
	check_rgb_fllor_range(data);
	check_rgb_cell_range(data);
}

void iterate_color_map(t_data *data, int *i)
{
	int j;
	int w;

	while (data->my_color[*i])
	{
		j = 0;
		w = 0;
		while (data->my_color[*i][j] != ' ')
		{
			data->prefix1[j] = data->my_color[*i][j];
			j++;
		}
		data->prefix1[j] = '\0';
		if (data->my_color[*i][j] == ' ')
			j++;
		while (data->my_color[*i][j] != '\0')
		{
			data->rest[w] = data->my_color[*i][j];
			w++;
			j++;
		}
		data->rest[w] = '\0';
		check_data(data);
		(*i)++;
	}
}
