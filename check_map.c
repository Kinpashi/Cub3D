/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahlaqqa <aahlaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 14:40:09 by aahlaqqa          #+#    #+#             */
/*   Updated: 2024/11/11 19:26:51 by aahlaqqa         ###   ########.fr       */
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

char **read_lines(char *path, t_data *data)
{
    char *line;
    char *lines;
    int fd;
    char **res;

    lines = NULL;
    fd = open(path, O_RDONLY);
    if (fd < 0)
    {
        printf("Error while opening the file !\n");
        exit(1);
    }
    while (1)
    {
        line = get_next_line(fd);
        if (!line)
            break;
        lines = ft_strjoin(lines, line);
        free(line);
    }
    res = ft_split(lines, '\n');
    data->my_map = ft_split(lines, '\n');
    return (res);
}
