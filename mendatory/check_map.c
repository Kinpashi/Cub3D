/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmed <ahmed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 14:40:09 by aahlaqqa          #+#    #+#             */
/*   Updated: 2025/02/09 23:31:03 by ahmed            ###   ########.fr       */
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

bool is_empty_line(char *line)
{
	int i = 0;

	while (line[i] == ' ' || line[i] == '\t')
		i++;
	return (line[i] == '\0' || line[i] == '\n'); // Check if the line is empty
}

char *start_reading(int fd, char *line)
{
	char *lines = NULL;

	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break;
		if (!is_empty_line(line))
		{
			lines = ft_strjoin(lines, line);
		}
		free(line);
	}
	return (lines);
}

void check_prefix(t_data *data)
{
	int i;

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
	while (data->new_map[i])
	{
		if (data->new_map[i][0] == 'F' || data->new_map[i][0] == 'C')
		{
			data->my_color[j] = data->new_map[i];
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
	while (data->new_map[i])
	{
		if ((data->new_map[i][0] == 'N' && data->new_map[i][1] == 'O') || (data->new_map[i][0] == 'S' && data->new_map[i][1] == 'O') || (data->new_map[i][0] == 'E' && data->new_map[i][1] == 'A') || (data->new_map[i][0] == 'W' && data->new_map[i][1] == 'E'))
		{
			data->my_map[j] = data->start_map[i];
			j++;
		}
		i++;
	}
}
void split_map(t_data *data)
{
	int i = 0, j = 0, total_lines = 0;
	while (data->start_map[total_lines])
		total_lines++;
	data->new_map = malloc(sizeof(char *) * (6 + 1));
	if (!data->new_map)
	{
		printf("Error while allocating memory for new_map!!\n");
		exit(1);
	}
	while (i < 6)
	{
		if (!data->start_map[i])
		{
			printf("Error: start_map has less than 6 lines!\n");
			exit(1);
		}
		data->new_map[i] = ft_strdup(data->start_map[i]);
		if (!data->new_map[i])
		{
			printf("Error while allocating memory for new_map[%d]!\n", i);
			exit(1);
		}
		i++;
	}
	data->new_map[i] = NULL;
	int remaining_lines = total_lines - 6;
	data->mini_map = malloc(sizeof(char *) * (remaining_lines + 1));
	if (!data->mini_map)
	{
		printf("Error while allocating memory for mini_map!!\n");
		exit(1);
	}
	while (i < total_lines)
	{
		data->mini_map[j] = ft_strdup(data->start_map[i]);
		if (!data->mini_map[j])
		{
			printf("Error while allocating memory for mini_map[%d]!\n", j);
			exit(1);
		}
		i++;
		j++;
	}
	data->mini_map[j] = NULL;
}

void handle_spaces(t_data *data)
{
	int i = 0;
	char *trimmed;

	while (data->new_map[i])
	{
		int j = 0;
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

void read_lines(char *path, t_data *data)
{
	char *line;
	char *lines;
	int fd;

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
