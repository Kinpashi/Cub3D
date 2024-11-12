/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahlaqqa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 15:10:50 by aahlaqqa          #+#    #+#             */
/*   Updated: 2023/11/27 11:48:36 by aahlaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	i;
	char	*dup;
	char	*dup_copy;
	size_t	s_len;

	i = 0;
	s_len = ft_strlen(s1);
	dup = ((char *)malloc(sizeof(char) * s_len + 1));
	if (!dup)
	{
		return (NULL);
	}
	dup_copy = dup;
	while (s1[i])
	{
		dup_copy[i] = s1[i];
		i++;
	}
	dup_copy[i] = '\0';
	return (dup_copy);
}
