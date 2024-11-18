/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahlaqqa <aahlaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 00:33:48 by aahlaqqa          #+#    #+#             */
/*   Updated: 2024/11/17 22:59:44 by aahlaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int main(int argc, char **argv)
{
    t_data data;

    if (argc != 2)
    {
        printf("Too much arguments !\n");
        exit(1);
    }
    check_path(argv[1]);
    read_lines(argv[1], &data);
    check_no_identifier(&data);
    check_colors(&data);
    // check_player(map); 
    // check_top_border(map);
    // check_bottem_border(map);
    // check_left_border(map);
    // check_right_border(map);
    data.mlx = mlx_init();
    data.mlx_win = mlx_new_window(data.mlx, 500, 500, "Cub3D");
    mlx_hook(data.mlx_win, 2, (1L << 0), handle_esc, &data);
    mlx_hook(data.mlx_win, 17, 0, close_win, &data);
    // data.height = 300;
    // data.width = 300;
    // data.img = mlx_xpm_file_to_image(data.mlx, "copy.xpm",&data.width, &data.height);
    // mlx_put_image_to_window(data.mlx, data.mlx_win, data.img, 0, 0);
    mlx_loop(data.mlx);
    printf("Done");
    return (0);
}
