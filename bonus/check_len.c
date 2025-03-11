/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_len.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmed <ahmed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 15:04:37 by ahmed             #+#    #+#             */
/*   Updated: 2025/03/09 02:22:20 by ahmed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	find_max_width(char **mini_map)
{
	int	i;
	int	len;
	int	width_len;

	i = 0;
	len = 0;
	width_len = 0;
	while (mini_map[i])
	{
		len = ft_strlen(mini_map[i]);
		if (len > width_len)
			width_len = len;
		i++;
	}
	return (width_len);
}

char	*pad_line(char *line, int width_len)
{
	int		len;
	char	*new_line;

	len = ft_strlen(line);
	new_line = malloc((width_len + 1) * sizeof(char));
	if (!new_line)
	{
		printf("Error while using malloc !!\n");
		exit(1);
	}
	ft_strcpy(new_line, line);
	ft_memset(new_line + len, ' ', width_len - len);
	new_line[width_len] = '\0';
	return (new_line);
}

void	check_len(t_data *data)
{
	int		i;
	int		len;
	int		width_len;
	char	*new_line;

	i = 0;
	len = 0;
	width_len = find_max_width(data->mini_map);
	while (data->mini_map[i])
	{
		len = ft_strlen(data->mini_map[i]);
		if (len < width_len)
		{
			new_line = pad_line(data->mini_map[i], width_len);
			free(data->mini_map[i]);
			data->mini_map[i] = new_line;
		}
		i++;
	}
	data->mini_map[i] = NULL;
}
