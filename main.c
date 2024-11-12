/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahlaqqa <aahlaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 00:33:48 by aahlaqqa          #+#    #+#             */
/*   Updated: 2024/11/11 19:09:45 by aahlaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int main(int argc, char **argv)
{
    char **map;
    t_data data;

    if (argc != 2)
    {
        printf("Too much arguments !\n");
        exit(1);
    }
    check_path(argv[1]);
    map = read_lines(argv[1], &data);
    check_player(map);
    check_top_border(map);
    check_bottem_border(map);
    check_left_border(map);
    check_right_border(map);
    printf("Done");
    return (0);
}
