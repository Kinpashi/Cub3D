/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahlaqqa <aahlaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 16:31:26 by aahlaqqa          #+#    #+#             */
/*   Updated: 2025/02/17 16:51:21 by aahlaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	print_malloc_error_message(void)
{
	printf("Error while allocating memory for new_map!!\n");
	exit(1);
}

void	print_parsing_error_message(void)
{
	printf("Error: start_map has less than 6 lines!\n");
	exit(1);
}

void	print_invalid_map_error_message(void)
{
	printf("Error\n Invalid map !!\n");
	exit(1);
}

void	print_incorrect_prefix_error_message(void)
{
	printf("Error\n Incoreect prefix !!\n");
	exit(1);
}

void print_incorrect_texture_error_message()
{
	printf("Error\n Incoreect texture !!\n");
	exit(1);
}