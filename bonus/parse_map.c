/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahlaqqa <aahlaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 01:38:03 by aahlaqqa          #+#    #+#             */
/*   Updated: 2025/03/15 01:57:55 by aahlaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	pars_error(int argc)
{
	if (argc != 2)
	{
		printf("Inccorect number of arguments !\n");
		exit(1);
	}
}

void	check_player(t_data *data)
{
	int	i;
	int	j;
	int	p;

	i = 0;
	j = 0;
	p = 0;
	while (data->mini_map[i])
	{
		j = 0;
		while (data->mini_map[i][j])
		{
			if (data->mini_map[i][j] == 'N' || data->mini_map[i][j] == 'E'
				|| data->mini_map[i][j] == 'S' || data->mini_map[i][j] == 'W')
				p++;
			j++;
		}
		i++;
	}
	if (p != 1)
	{
		printf("Error\n One Player Nedded\n");
		exit(1);
	}
}

void	check_colors(t_data *data)
{
	int	i;

	data->count1 = 0;
	data->len = 0;
	data->prefix1 = malloc(2 + 1);
	data->rest = malloc(256);
	if (!data->rest || !data->prefix1)
		return ;
	i = 0;
	iterate_color_map(data, &i);
	if (data->count1 != 2)
	{
		printf("Error\n incorrect identifier !");
		exit(1);
	}
	if (data->len != 4)
	{
		printf("Error\n missing or adding ',' !");
		exit(1);
	}
}

void	check_map(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->mini_map[i])
	{
		j = 0;
		while (data->mini_map[i][j])
		{
			if (data->mini_map[i][j] == ' ')
			{
				if (data->mini_map[i][j + 1] == '0')
				{
					printf("Error\n a space is found !");
					exit(1);
				}
			}
			j++;
		}
		i++;
	}
}

void	check_mini_map(t_data *data)
{
	check_player(data);
	check_door(data);
	check_map(data);
}
