/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahlaqqa <aahlaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 16:28:55 by aahlaqqa          #+#    #+#             */
/*   Updated: 2025/02/06 15:46:58 by aahlaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	pars_texture(t_data *data, t_path *path)
{
	int		i;
	char	**splited;

	i = 0;
	while (data->my_map[i])
	{
		splited = ft_split(data->my_map[i], ' ');
		if (!splited)
			return ;
		if (splited[0] || splited[1])
		{
			path->key = ft_strdup(splited[0]);
			path->value = ft_strdup(splited[1]);
		}
		i++;
	}
}
