/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahlaqqa <aahlaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 16:35:33 by aahlaqqa          #+#    #+#             */
/*   Updated: 2025/03/14 15:16:13 by aahlaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	free_texture_one(t_data *data)
{
	printf("Error\n Failed to load South texture: %s\n", data->so_texture);
	mlx_destroy_image(data->mlx, data->no_texture_img);
	exit(1);
}

void	free_texture_two(t_data *data)
{
	printf("Error\n Failed to load West texture: %s\n", data->we_texture);
	mlx_destroy_image(data->mlx, data->no_texture_img);
	mlx_destroy_image(data->mlx, data->so_texture_img);
	exit(1);
}

void	free_texture_three(t_data *data)
{
	printf("Error\n Failed to load East texture: %s\n", data->ea_texture);
	mlx_destroy_image(data->mlx, data->no_texture_img);
	mlx_destroy_image(data->mlx, data->so_texture_img);
	mlx_destroy_image(data->mlx, data->we_texture_img);
	exit(1);
}

void free_door_texture(t_data *data)
{
	printf("Error\n Failed to load Door texture : %s\n", data->door_texture);
	mlx_destroy_image(data->mlx, data->no_texture_img);
	mlx_destroy_image(data->mlx, data->so_texture_img);
	mlx_destroy_image(data->mlx, data->we_texture_img);
	mlx_destroy_image(data->mlx, data->ea_texture_img);
	exit(1);
}
