/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahlaqqa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 13:40:23 by aahlaqqa          #+#    #+#             */
/*   Updated: 2024/01/01 14:53:17 by aahlaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	size_t	i;

	if (count && size && size > SIZE_MAX / count)
		return (NULL);
	ptr = malloc(count * size);
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < count * size)
	{
		((char *)ptr)[i] = '\0';
		i++;
	}
	return (ptr);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	x;
	char	*ptr;
	size_t	i;

	i = 0;
	x = 0;
	ptr = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!ptr)
		return (free(s1), free(s2), NULL);
	while (s1 && s1[i] != '\0')
	{
		ptr[i] = s1[i];
		i++;
	}
	ptr[i] = '\0';
	while (s2[x] != '\0')
	{
		ptr[i] = s2[x];
		i++;
		x++;
	}
	ptr[i] = '\0';
	return (free(s1), ptr);
}

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((char *)s)[i] = '\0';
		i++;
	}
}

char	*ft_strdup(const char *s1)
{
	size_t	i;
	char	*dup;
	size_t	s_len;

	i = 0;
	s_len = ft_strlen(s1);
	dup = ((char *)malloc(sizeof(char) * s_len + 1));
	if (!dup)
		return (NULL);
	while (s1[i])
	{
		dup[i] = s1[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
