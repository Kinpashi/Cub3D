/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahlaqqa <aahlaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 14:40:09 by aahlaqqa          #+#    #+#             */
/*   Updated: 2024/11/19 14:54:40 by aahlaqqa         ###   ########.fr       */
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
    while (1)
    {
        line = get_next_line(fd);
        if (!line)
            break;
        lines = ft_strjoin(lines, line);
        free(line);
        i++;
    }
    data->mini_map = ft_split(lines, '\n');
}
