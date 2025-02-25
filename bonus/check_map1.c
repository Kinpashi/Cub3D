/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahlaqqa <aahlaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 16:29:25 by aahlaqqa          #+#    #+#             */
/*   Updated: 2025/02/17 16:42:05 by aahlaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	split_map(t_data *data)
{
	int	i;
	int	total_lines;
	int	remaining_lines;
	int	j;

	i = 0;
	j = 0;
	total_lines = 0;
	while (data->start_map[total_lines])
		total_lines++;
	data->new_map = malloc(sizeof(char *) * (6 + 1));
	if (!data->new_map)
		print_malloc_error_message();
	while (i < 6)
	{
		if (!data->start_map[i])
			print_parsing_error_message();
		data->new_map[i] = ft_strdup(data->start_map[i]);
		if (!data->new_map[i])
			print_malloc_error_message();
		i++;
	}
	data->new_map[i] = NULL;
	remaining_lines = total_lines - 6;
	data->mini_map = malloc(sizeof(char *) * (remaining_lines + 1));
	if (!data->mini_map)
		print_malloc_error_message();
	while (i < total_lines)
	{
		data->mini_map[j] = ft_strdup(data->start_map[i]);
		if (!data->mini_map[j])
			print_malloc_error_message();
		i++;
		j++;
	}
	data->mini_map[j] = NULL;
}

void	handle_spaces(t_data *data)
{
	int		i;
	char	*trimmed;
	int		j;

	i = 0;
	while (data->new_map[i])
	{
		j = 0;
		while (data->new_map[i][j] == ' ' || data->new_map[i][j] == '\t')
			j++;
		if (data->new_map[i][j] != '\0')
		{
			trimmed = ft_strdup(&data->new_map[i][j]);
			if (!trimmed)
			{
				printf("Error while allocating memory for trimmed line!\n");
				exit(1);
			}
			free(data->new_map[i]);
			data->new_map[i] = trimmed;
		}
		i++;
	}
}

void	check_prefix(t_data *data)
{
	int	i;

	i = 0;
	while (data->new_map[i])
	{
		if (data->new_map[i][0] == 'N' && data->new_map[i][1] == 'O')
			data->flag++;
		else if (data->new_map[i][0] == 'S' && data->new_map[i][1] == 'O')
			data->flag++;
		else if (data->new_map[i][0] == 'W' && data->new_map[i][1] == 'E')
			data->flag++;
		else if (data->new_map[i][0] == 'E' && data->new_map[i][1] == 'A')
			data->flag++;
		else if (data->new_map[i][0] == 'F')
			data->flag++;
		else if (data->new_map[i][0] == 'C')
			data->flag++;
		else
			print_invalid_map_error_message();
		i++;
	}
	if (data->flag != 6)
		print_incorrect_prefix_error_message();
}
