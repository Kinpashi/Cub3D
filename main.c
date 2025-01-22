/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmed <ahmed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 00:33:48 by aahlaqqa          #+#    #+#             */
/*   Updated: 2025/01/22 17:06:39 by ahmed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int main(int argc, char **argv)
{
    t_data data;
    t_path path;

    data.floor[0] = 0;
    data.floor[1] = 0;
    data.floor[2] = 0;
    data.cell[0] = 0;
    data.cell[1] = 0;
    data.cell[2] = 0;
    data.screenheight = 500;
    data.screenwidth = 1000;
    if (argc != 2)
    {
        printf("Too much arguments !\n");
        exit(1);
    }
    check_path(argv[1]);
    read_lines(argv[1], &data);
    check_all_in_map(&data);
    check_no_identifier(&data);
    check_colors(&data);
    check_mini_map(&data);
    pars_texture(&data, &path);
    double raydirx = 2.9;
    double raydiry = 0.4;
    calculat_dda(&data, raydirx, raydiry);
    printf("Ray Distance to Wall: %f\n", data.raydistans);
    data.mlx = mlx_init();
    data.mlx_win = mlx_new_window(data.mlx, 1000, 500, "Cub3D");
    draw_window(&data);
    draw_mini_map(&data);
    mlx_hook(data.mlx_win, 2, (1L << 0), press_key, &data);
    mlx_hook(data.mlx_win, 17, 0, close_win, &data);
    // data.height = 300;
    // data.width = 300;
    // data.img = mlx_xpm_file_to_image(data.mlx, "copy.xpm",&data.width, &data.height);
    // mlx_put_image_to_window(data.mlx, data.mlx_win, data.img, 0, 0);
    mlx_loop(data.mlx);
    return (0);
}


