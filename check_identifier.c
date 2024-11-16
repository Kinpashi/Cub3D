/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_identifier.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahlaqqa <aahlaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 17:24:59 by aahlaqqa          #+#    #+#             */
/*   Updated: 2024/11/16 17:37:29 by aahlaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void check_for_identifier(char *str)
{
    if (ft_strcmp(str, "NO") != 0  && ft_strcmp(str, "SO") != 0 && ft_strcmp(str, "WE") != 0 && ft_strcmp(str, "EA") != 0)
    {
        printf("Error\n incorrect identifier !");
        exit(1);
    }
}