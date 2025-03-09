/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahlaqqa <aahlaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 14:40:09 by aahlaqqa          #+#    #+#             */
/*   Updated: 2025/03/08 18:07:26 by aahlaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

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

bool	is_empty_line(char *line)
{
	int		i;
	bool	result;

	i = 0;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	if (line[i] == '\0' || line[i] == '\n')
		result = true;
	else
		result = false;
	return (result);
}

char	*start_reading(int fd, char *line)
{
	char	*lines;

	lines = NULL;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (!is_empty_line(line))
			lines = ft_strjoin(lines, line);
		free(line);
	}
	return (lines);
}

void	read_lines(char *path, t_data *data)
{
	char	*line;
	char	*lines;
	int		fd;

	lines = NULL;
	line = NULL;
	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		printf("Error while opening the file !\n");
		exit(1);
	}
	lines = start_reading(fd, line);
	data->start_map = ft_split(lines, '\n');
	lines = NULL;
	split_map(data);
	handle_spaces(data);
	check_prefix(data);
	assigne_colors(data);
	assigne_texture(data);
	caller_function(data);
	free(lines);
	close(fd);
}
