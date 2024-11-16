/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahlaqqa <aahlaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 01:38:03 by aahlaqqa          #+#    #+#             */
/*   Updated: 2024/11/16 17:32:15 by aahlaqqa         ###   ########.fr       */
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

void check_no_identifier(char *line)
{
    size_t i;
    char *prefix;

    i = 0;
    while (line[i] != ' ' && line[i] != '\0')
        i++;
    prefix = malloc(i + 1);
    if (!prefix)
        return;
    i = 0;
    while (line[i] != ' ' && line[i] != '\0')
    {
        prefix[i] = line[i];
        i++;
    }
    prefix[i] = '\0';
    printf("%s\n", prefix);
    check_for_identifier(prefix);
}
