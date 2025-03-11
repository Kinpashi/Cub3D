/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rgb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahlaqqa <aahlaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 16:01:40 by ahmed             #+#    #+#             */
/*   Updated: 2025/03/09 16:04:36 by aahlaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	pars_rgb_line(char *str, int *index)
{
	char	res[4];
	int		j;

	j = 0;
	while (str[*index] && str[*index] != '\0' && str[*index] != ',')
	{
		if (j <= 3)
		{
			res[j] = str[*index];
			j++;
		}
		(*index)++;
	}
	res[j] = '\0';
	if (str[*index] == ',')
		(*index)++;
	return (ft_atoi(res));
}

void	check_floor_rgb(char *str, t_data *data)
{
	int	i;
	int	x;
	int	value;

	i = 0;
	x = 0;
	while (x < 3)
	{
		value = pars_rgb_line(str, &i);
		data->floor[x] = value;
		x++;
	}
}

void	check_cell_rgb(char *str, t_data *data)
{
	int	i;
	int	x;
	int	value;

	i = 0;
	x = 0;
	while (x < 3)
	{
		value = pars_rgb_line(str, &i);
		data->cell[x] = value;
		x++;
	}
}

void	check_rgb_fllor_range(t_data *data)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		if (data->floor[i] < 0 || data->floor[i] > 255)
		{
			printf("Error\n RGB range is incorrect !");
			exit(1);
		}
		i++;
	}
}

void	check_rgb_cell_range(t_data *data)
{
	int	j;

	j = 0;
	while (j < 3)
	{
		if (data->cell[j] < 0 || data->cell[j] > 255)
		{
			printf("Error\n RGB range is incorrect !");
			exit(1);
		}
		j++;
	}
}
