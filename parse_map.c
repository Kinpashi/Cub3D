/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahlaqqa <aahlaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 01:38:03 by aahlaqqa          #+#    #+#             */
/*   Updated: 2025/01/17 02:12:03 by aahlaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void check_player(t_data *data)
{
    int i;
    int j;
    int p;

    i = 0;
    j = 0;
    p = 0;
    while (data->mini_map[i])
    {
        j = 0;
        while (data->mini_map[i][j])
        {
            if (data->mini_map[i][j] == 'N' || data->mini_map[i][j] == 'E' || data->mini_map[i][j] == 'S' || data->mini_map[i][j] == 'W')
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

void check_no_identifier(t_data *data)
{
    size_t i;
    size_t j;
    int y;
    int count;
    char *prefix;
    char *texture;

    count = 0;
    prefix = malloc(3 + 1);
    if (!prefix)
        return;
    texture = malloc(100);
    if (!texture)
        return;
    i = 0;
    while (i < 4)
    {
        j = 0;
        y = 0;
        while (data->my_map[i][j] != ' ')
        {
            prefix[j] = data->my_map[i][j];
            j++;
        }
        prefix[j] = '\0';
        if (data->my_map[i][j] == ' ')
            j++;
        while (data->my_map[i][j] != '\0')
        {
            texture[y] = data->my_map[i][j];
            j++;
            y++;
        }
        texture[y] = '\0';
        count = check_for_identifier(prefix, count);
        check_texture(texture, data);
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
        if (data->my_color[i][j] == ' ')
            j++;
        while (data->my_color[i][j] != '\0')
        {
            rest[w] = data->my_color[i][j];
            w++;
            j++;
        }
        rest[w] = '\0';
        count = check_for_colors(prefix, count);
        len = check_length_color(rest, len);
        if (ft_strcmp(prefix, "F") == 0)
            check_floor_rgb(rest, data);
        else if (ft_strcmp(prefix, "C") == 0)
            check_cell_rgb(rest, data);
        check_rgb_fllor_range(data);
        check_rgb_cell_range(data);
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

void check_map(t_data *data)
{
    int i;
    int j;

    i = 0;
    while (data->mini_map[i])
    {
        j = 0;
        while (data->mini_map[i][j])
        {
            if (data->mini_map[i][j] == ' ')
            {
                if (data->mini_map[i][j + 1] == '0')
                {
                    printf("Error\n a space is found !");
                    exit(1);
                }
            }
            j++;
        }
        i++;
    }
}

void check_mini_map(t_data *data)
{
    check_player(data);
    check_map(data);
}
