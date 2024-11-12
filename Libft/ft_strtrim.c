/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahlaqqa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 08:55:44 by aahlaqqa          #+#    #+#             */
/*   Updated: 2023/11/23 15:58:16 by aahlaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*str(size_t n)
{
	char	*p;

	p = (char *)malloc(sizeof(char) * (n + 1));
	if (!p)
		return (NULL);
	return (p);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	char	*ptr;
	size_t	first;
	size_t	last;

	if (!s1 || !set)
		return (NULL);
	first = 0;
	while (s1[first] != '\0' && ft_strchr(set, s1[first]))
		first++;
	last = ft_strlen(s1);
	while (last > first && ft_strchr(set, s1[last - 1]))
		last--;
	ptr = str(last - first);
	if (!ptr)
		return (NULL);
	i = 0;
	while (first + i < last)
	{
		ptr[i] = s1[first + i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
