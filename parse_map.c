/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahlaqqa <aahlaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 01:38:03 by aahlaqqa          #+#    #+#             */
/*   Updated: 2024/11/18 00:08:40 by aahlaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void check_player(char **map)
{
    int i;
    int j;
    int p;

    i = 0;
    j = 0;
    p = 0;
    while (map[i])
    {
        j = 0;
        while (map[i][j])
        {
            if (map[i][j] == 'N' || map[i][j] == 'E' || map[i][j] == 'S' || map[i][j] == 'W')
                p++;
            j++;
        }
        i++;
    }
    if (p != 1)
    {
        printf("Error\n One Player Nedded\n");
        exit(1);
    }
}

void check_top_border(char **map)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (map[i])
    {
        while (map[i][j])
        {
            if (map[i][j] != '1')
            {
                printf("Error\n No border !");
                exit(1);
            }
            j++;
        }
        i++;
    }
}

void check_bottem_border(char **map)
{
    size_t len;
    size_t i;

    i = 0;
    while (map[i])
        i++;
    len = i;
    i = 0;
    while (map[len - 1][i])
    {
        if (map[len - 1][i] != '1')
        {
            printf("Error\n No border !");
            exit(1);
        }
        i++;
    }
}

void check_left_border(char **map)
{
    size_t i;

    i = 0;
    while (map[i])
    {
        if (map[i][0] != '1')
        {
            printf("Error\n No border !");
            exit(1);
        }
        i++;
    }
}

void check_right_border(char **map)
{
    size_t len;
    size_t i;

    len = ft_strlen(map[0]);
    i = 0;
    while (map[i])
    {
        if (map[i][len - 1] != '1')
        {
            printf("Error\n No border !");
            exit(1);
        }
        i++;
    }
}

void check_no_identifier(t_data *data)
{
    size_t i;
    size_t j;
    int count;
    char *prefix;

    count = 0;
    prefix = malloc(3 + 1);
    if (!prefix)
        return;
    i = 0;
    while (data->my_map[i] != '\0')
    {
        j = 0;
        while (data->my_map[i][j] != ' ')
        {
            prefix[j] = data->my_map[i][j];
            j++;
        }
        prefix[j] = '\0';
        count = check_for_identifier(prefix, count);
        i++;
    }
    if (count != 4)
    {
        printf("Error\n incorrect identifier !");
        exit(1);
    }
}

void check_colors(t_data *data)
{
    int i;
    int j;
    int w;
    int count;
    int len;
    char *prefix;
    char *rest;

    count = 0;
    len = 0;
    prefix = malloc(2);
    if (!prefix)
        return;
    rest = malloc(100);
    if (!rest)
        return;
    i = 0;
    while (data->my_color[i])
    {
        j = 0;
        w = 0;
        while (data->my_color[i][j] != ' ')
        {
            prefix[j] = data->my_color[i][j];
            j++;
        }
        prefix[j] = '\0';
        while (data->my_color[i][j] != '\0')
        {
            rest[w] = data->my_color[i][j];
            w++;
            j++;
        }
        rest[j] = '\0';
        count = check_for_colors(prefix, count);
        len = check_length_color(rest, len);
        check_rgb(rest);
        i++;
    }
    if (count != 2)
    {
        printf("Error\n incorrect identifier !");
        exit(1);
    }
    if (len != 4)
    {
        printf("Error\n missing or adding ',' !");
        exit(1);
    }
}
