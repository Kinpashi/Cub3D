/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_errors.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahlaqqa <aahlaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 16:43:15 by aahlaqqa          #+#    #+#             */
/*   Updated: 2025/03/14 15:33:08 by aahlaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	texture_east_error_message(void)
{
	printf("Error\n Failed to get data address for East texture.\n");
	exit(1);
}

void	texture_west_error_message(void)
{
	printf("Error\n Failed to get data address for West texture.\n");
	exit(1);
}

void	texture_south_error_message(void)
{
	printf("Error\n Failed to get data address for South texture.\n");
	exit(1);
}

void	texture_north_error_message(void)
{
	printf("Error\n Failed to get data address for North texture.\n");
	exit(1);
}

void texture_door_error_message(void)
{
	printf("Error\n Failed to get data addres for Door texture.\n");
	exit(1);
}
