/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmed <ahmed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 16:31:26 by aahlaqqa          #+#    #+#             */
/*   Updated: 2025/03/09 01:43:30 by ahmed            ###   ########.fr       */
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
	printf("Error\nInvalid line !!\n");
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

void	print_incorrect_texture_error_message(void)
{
	printf("Error\n Incoreect texture !!\n");
	exit(1);
}
