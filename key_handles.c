/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handles.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahlaqqa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 22:08:07 by aahlaqqa          #+#    #+#             */
/*   Updated: 2024/11/13 22:08:09 by aahlaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int handle_esc(int keycode, void *param)
{
    (void)param;

    if (keycode == 65307)
        exit(0);
    return (0);
}

int close_win(t_data *data)
{
    (void)data;

    exit(0);
}