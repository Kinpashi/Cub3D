/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmed <ahmed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 14:40:09 by aahlaqqa          #+#    #+#             */
/*   Updated: 2025/01/20 14:31:37 by ahmed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

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

void read_lines(char *path, t_data *data)
{
    char *line;
    char *lines;
    int fd;
    int i;

    lines = NULL;
    i = 0;
    fd = open(path, O_RDONLY);
    if (fd < 0)
    {
        printf("Error while opening the file !\n");
        exit(1);
    }
    // Map For Directions
    while (i < 4)
    {
        line = get_next_line(fd);
        if (!line)
            break;
        if (line[0] != '\n')
        {
            lines = ft_strjoin(lines, line);
            free(line);
            i++;
        }
    }
    data->my_map = ft_split(lines, '\n');
    lines = NULL;
    // Map For Colors
    while (i < 6)
    {
        line = get_next_line(fd);
        if (!line)
            break;
        if (line[0] != '\n')
        {
            lines = ft_strjoin(lines, line);
            free(line);
            i++;
        }
    }
    data->my_color = ft_split(lines, '\n');
    lines = NULL;
    // Map For The Main Map
    while (1)
    {
        line = get_next_line(fd);
        if (!line)
            break;
        lines = ft_strjoin(lines, line);
        free(line);
    }
    data->mini_map = ft_split(lines, '\n');
    check_top_borders(data);
    check_bottom_border(data);
    check_left_border(data);
    check_right_border(data);
    check_len(data);
    check_around_space(data);
    free(lines);
    close(fd);
}
