/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahlaqqa <aahlaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 01:38:03 by aahlaqqa          #+#    #+#             */
/*   Updated: 2024/11/19 15:36:19 by aahlaqqa         ###   ########.fr       */
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

void check_top_border(t_data *data)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (data->mini_map[i])
    {
        while (data->mini_map[i][j])
        {
            if (data->mini_map[i][j] != '1')
            {
                printf("Error\n No border !");
                exit(1);
            }
            j++;
        }
        i++;
    }
}

void check_bottem_border(t_data *data)
{
    size_t len;
    size_t i;

    i = 0;
    while (data->mini_map[i])
        i++;
    len = i;
    i = 0;
    while (data->mini_map[len - 1][i])
    {
        if (data->mini_map[len - 1][i] != '1')
        {
            printf("Error\n No border !");
            exit(1);
        }
        i++;
    }
}

void check_left_border(t_data *data)
{
    size_t i;

    i = 0;
    while (data->mini_map[i])
    {
        if (data->mini_map[i][0] != '1')
        {
            printf("Error\n No border !");
            exit(1);
        }
        i++;
    }
}

void check_right_border(t_data *data)
{
    size_t len;
    size_t i;

    len = ft_strlen(data->mini_map[0]);
    i = 0;
    while (data->mini_map[i])
    {
        if (data->mini_map[i][len - 1] != '1')
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

void check_mini_map(t_data *data)
{
    check_player(data);
    check_left_border(data);
    check_right_border(data);
    check_top_border(data);
    check_bottem_border(data);
}
