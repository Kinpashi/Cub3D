/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahlaqqa <aahlaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 00:33:48 by aahlaqqa          #+#    #+#             */
/*   Updated: 2024/11/22 16:50:36 by aahlaqqa         ###   ########.fr       */
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
    if (argc != 2)
    {
        printf("Too much arguments !\n");
        exit(1);
    }
    check_path(argv[1]);
    read_lines(argv[1], &data);
    check_all_in_map(&data);
    find_player_position(&data);
    check_no_identifier(&data);
    check_colors(&data);
    check_mini_map(&data);
    pars_texture(&data, &path);
    double raydirx = 2.0;
    double raydiry = 0.5;
    calculat_dda(&data, raydirx, raydiry);
    printf("Ray Distance to Wall: %f\n", data.raydistans);
    exit(1);
    data.mlx = mlx_init();
    data.mlx_win = mlx_new_window(data.mlx, 500, 500, "Cub3D");
    draw_window(&data);
    mlx_hook(data.mlx_win, 2, (1L << 0), handle_esc, &data);
    mlx_hook(data.mlx_win, 17, 0, close_win, &data);
    // data.height = 300;
    // data.width = 300;
    // data.img = mlx_xpm_file_to_image(data.mlx, "copy.xpm",&data.width, &data.height);
    // mlx_put_image_to_window(data.mlx, data.mlx_win, data.img, 0, 0);
    mlx_loop(data.mlx);
    return (0);
}
