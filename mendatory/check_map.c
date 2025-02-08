/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahlaqqa <aahlaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 14:40:09 by aahlaqqa          #+#    #+#             */
/*   Updated: 2025/02/08 20:56:41 by aahlaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void check_path(char *path)
{
	int fd;
	char *extention;

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

void check_all_in_map(t_data *data)
{
	int i;
	int j;

	i = 0;
	while (data->mini_map[i])
	{
		j = 0;
		while (data->mini_map[i][j])
		{
			if (data->mini_map[i][j] != '1' && data->mini_map[i][j] != '0' && data->mini_map[i][j] != 'N' && data->mini_map[i][j] != 'W' && data->mini_map[i][j] != 'S' && data->mini_map[i][j] != 'E' && data->mini_map[i][j] != ' ')
			{
				printf("Error\n incorrect caracter !");
				exit(1);
			}
			j++;
		}
		i++;
	}
}

char *start_reading(int fd, int *i, char *line)
{
	char *lines;

	lines = NULL;
	while (*i < 6)
	{
		line = get_next_line(fd);
		if (!line)
			break;
		if (line[0] != '\n')
		{
			lines = ft_strjoin(lines, line);
			free(line);
			(*i)++;
		}
	}
	return (lines);
}

void check_prefix(t_data *data)
{
	int i;

	i = 0;
	while (data->start_map[i])
	{
		if (data->start_map[i][0] == 'N' && data->start_map[i][1] == 'O')
			data->flag++;
		else if (data->start_map[i][0] == 'S' && data->start_map[i][1] == 'O')
			data->flag++;
		else if (data->start_map[i][0] == 'W' && data->start_map[i][1] == 'E')
			data->flag++;
		else if (data->start_map[i][0] == 'E' && data->start_map[i][1] == 'A')
			data->flag++;
		else if (data->start_map[i][0] == 'F')
			data->flag++;
		else if (data->start_map[i][0] == 'C')
			data->flag++;
		else
		{
			printf("Error\n Invalid map !!\n");
			exit(1);
		}
		i++;
	}
	if (data->flag != 6)
	{
		printf("Error\n Incoreect prefix !!\n");
		exit(1);
	}
}

void assigne_colors(t_data *data)
{
	int i = 0;
	int j = 0;

	data->my_color = malloc(sizeof(char *) * 3);
	if (!data->my_color)
	{
		printf("Error while allocating memory !!\n");
		exit(1);
	}
	while (data->start_map[i])
	{
		if (data->start_map[i][0] == 'F' || data->start_map[i][0] == 'C')
		{
			data->my_color[j] = data->start_map[i];
			j++;
		}
		i++;
	}
}

void assigne_texture(t_data *data)
{
	int i = 0;
	int j = 0;

	data->my_map = malloc(sizeof(char *) * 5);
	if (!data->my_map)
	{
		printf("Error while allocating memory !!\n");
		exit(1);
	}
	while (data->start_map[i])
	{
		if ((data->start_map[i][0] == 'N' && data->start_map[i][1] == 'O') || (data->start_map[i][0] == 'S' && data->start_map[i][1] == 'O') || (data->start_map[i][0] == 'E' && data->start_map[i][1] == 'A') || (data->start_map[i][0] == 'W' && data->start_map[i][1] == 'E'))
		{
			data->my_map[j] = data->start_map[i];
			j++;
		}
		i++;
	}
}

void skip_sapces(t_data *data)
{
	int i;

	i = 0;
	while (data->start_map[i])
	{
		int j = 0;
		while (data->start_map[i][j])
		{
			if ((data->start_map[i][j] == 32 || data->start_map[i][j] == '\t')
				&& (data->start_map[i][j + 1] != 32 || data->start_map[i][j + 1]))
					j++;
		}
		i++;
	}
}

void read_lines(char *path, t_data *data)
{
	char *line;
	char *lines;
	int fd;
	int i;

	lines = NULL;
	line = NULL;
	i = 0;
	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		printf("Error while opening the file !\n");
		exit(1);
	}
	lines = start_reading(fd, &i, line);
	data->start_map = ft_split(lines, '\n');
	for (int i = 0; data->start_map[i]; i++)
		printf("%s\n", data->start_map[i]);
	skip_sapces(data);
	for (int i = 0; data->start_map[i]; i++)
		printf("%s\n", data->start_map[i]);
	exit(1);
	lines = NULL;
	check_prefix(data);
	assigne_colors(data);
	assigne_texture(data);
	lines = main_map(fd, line);
	data->mini_map = ft_split(lines, '\n');
	caller_function(data);
	free(lines);
	close(fd);
}
