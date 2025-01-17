/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_borders.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahlaqqa <aahlaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 00:00:08 by aahlaqqa          #+#    #+#             */
/*   Updated: 2025/01/17 02:29:36 by aahlaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void check_len(t_data *data)
{
    int i = 0;
    int len = 0;
    int width_len = 0;
    while (data->mini_map[i])
    {
        len = ft_strlen(data->mini_map[i]);
        if (len > width_len)
            width_len = len;
        i++;
    }
    i = 0;
    len = 0;
    while (data->mini_map[i])
    {
        len = ft_strlen(data->mini_map[i]);
        if (len < width_len)
        {
            char *new_line = malloc((width_len + 1) * sizeof(char));
            if (!new_line)
            {
                printf("Error while allocating memory !\n");
                exit(1);
            }
            ft_strcpy(new_line, data->mini_map[i]);
            ft_memset(new_line + len, ' ', width_len - len);
            new_line[width_len] = '\0';

            free(data->mini_map[i]);
            data->mini_map[i] = new_line;
        }
        i++;
    }
}

void check_top_borders(t_data *data)
{
    int x = 0;
    while (data->mini_map[0][x])
    {
        if (data->mini_map[0][x] != '1' && data->mini_map[0][x] != 32 && data->mini_map[0][x] != '\t')
        {
            printf("Error\nNo border !");
            exit(1);
        }
        x++;
    }
}

void check_bottom_border(t_data *data)
{
    int j = 0;
    while (data->mini_map[j])
        j++;
    int x = 0;
    while (data->mini_map[j - 1][x])
    {
        if (data->mini_map[j - 1][x] != '1' && data->mini_map[j - 1][x] != 32 && data->mini_map[j - 1][x] != '\t')
        {
            printf("Error\nNo border !");
            exit(1);
        }
        x++;
    }
}

void check_left_border(t_data *data)
{
    int len = 0;
    int j = 0;
    while (data->mini_map[j])
    {
        len = ft_strlen(data->mini_map[j]);
        if (data->mini_map[j][len - 1] != '1')
        {
            printf("Error\nNo border !");
            exit(1);
        }
        j++;
        len = 0;
    }
}

void check_right_border(t_data *data)
{
    int j = 0;
    while (data->mini_map[j])
    {
        if (data->mini_map[j][0] != '1' && data->mini_map[j][0] != 32 && data->mini_map[j][0] != '\t')
        {
            printf("Error\nNo border !");
            exit(1);
        }
        j++;
    }
}