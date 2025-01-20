/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmed <ahmed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 14:40:09 by aahlaqqa          #+#    #+#             */
/*   Updated: 2025/01/20 16:43:34 by ahmed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	check_path(char *path)
{
	int		fd;
	char	*extention;

	fd = open(path, O_RDONLY);
	extention = ft_strrchr(path, '.');
	if (!extention)
	{
		printf("File not found !\n");
		exit(1);
	}
	if (ft_strcmp(extention, ".cub") != 0)
	{
		printf("Error in the extention !\n");
		close(fd);
		exit(1);
	}
	if (fd < 0)
	{
		printf("Error while opening the file !\n");
		exit(1);
	}
	close(fd);
}

void	check_all_in_map(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->mini_map[i])
	{
		j = 0;
		while (data->mini_map[i][j])
		{
			if (data->mini_map[i][j] != '1' && data->mini_map[i][j] != '0'
				&& data->mini_map[i][j] != 'N' && data->mini_map[i][j] != 'W'
				&& data->mini_map[i][j] != 'S' && data->mini_map[i][j] != 'E'
				&& data->mini_map[i][j] != ' ')
			{
				printf("Error\n incorrect caracter !");
				exit(1);
			}
			j++;
		}
		i++;
	}
}

void	read_lines(char *path, t_data *data)
{
	char	*line;
	char	*lines;
	int		fd;
	int		i;

	lines = NULL;
	line = NULL;
	i = 0;
	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		printf("Error while opening the file !\n");
		exit(1);
	}
	lines = directions_map(fd, &i, line);
	data->my_map = ft_split(lines, '\n');
	lines = NULL;
	lines = color_map(fd, &i, line);
	data->my_color = ft_split(lines, '\n');
	lines = NULL;
	lines = main_map(fd, line);
	data->mini_map = ft_split(lines, '\n');
	caller_function(data);
	free(lines);
	close(fd);
}
