/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube_movements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahlaqqa <aahlaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 14:45:20 by aahlaqqa          #+#    #+#             */
/*   Updated: 2025/02/17 15:41:26 by aahlaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int press_key(int key, t_data *data)
{
    printf("Current tile: %c\n", data->mini_map[(int)data->player_x][(int)data->player_y]);
    printf("Tile ahead: %c\n", data->mini_map[(int)(data->player_x + data->dir_x * MOVE_SPEED)][(int)data->player_y]);
    printf("Tile right: %c\n", data->mini_map[(int)data->player_x][(int)(data->player_y + data->dir_y * MOVE_SPEED)]);
    if (key == 65307) // ESC key
        exit(0);
    if (key == 119) // W Key
    {
        printf("Moving forward (W)\n");
        printf("Before movement: x = %f, y = %f\n", data->player_x, data->player_y);

        if (data->mini_map[(int)(data->player_x + data->dir_x * MOVE_SPEED)][(int)data->player_y] != '1')
            data->player_x += data->dir_x * MOVE_SPEED;

        if (data->mini_map[(int)data->player_x][(int)(data->player_y + data->dir_y * MOVE_SPEED)] != '1')
            data->player_y += data->dir_y * MOVE_SPEED;

        printf("After movement: x = %f, y = %f\n", data->player_x, data->player_y);
    }
    else if (key == 115) // S Key
    {
        if (data->mini_map[(int)(data->player_x - data->dir_x * MOVE_SPEED)][(int)data->player_y] != '1')
            data->player_x -= data->dir_x * MOVE_SPEED;

        if (data->mini_map[(int)data->player_x][(int)(data->player_y - data->dir_y * MOVE_SPEED)] != '1')
            data->player_y -= data->dir_y * MOVE_SPEED;
    }
    raycasting(data);
    return (0);
}
