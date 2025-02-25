/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahlaqqa <aahlaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 16:21:07 by ahmed             #+#    #+#             */
/*   Updated: 2025/02/06 15:47:09 by aahlaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

char	*directions_map(int fd, int *i, char *line)
{
	char	*lines;

	lines = NULL;
	while (*i < 4)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (line[0] != '\n')
		{
			lines = ft_strjoin(lines, line);
			free(line);
			(*i)++;
		}
	}
	return (lines);
}

char	*color_map(int fd, int *i, char *line)
{
	char	*lines;

	lines = NULL;
	while (*i < 6)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (line[0] != '\n')
		{
			lines = ft_strjoin(lines, line);
			free(line);
			(*i)++;
		}
	}
	return (lines);
}

char	*main_map(int fd, char *line)
{
	char	*lines;

	lines = NULL;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		lines = ft_strjoin(lines, line);
		free(line);
	}
	return (lines);
}

void	caller_function(t_data *data)
{
	check_top_borders(data);
	check_bottom_border(data);
	check_left_border(data);
	check_right_border(data);
	check_len(data);
	check_around_space(data);
}
