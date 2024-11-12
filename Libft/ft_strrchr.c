/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahlaqqa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 12:28:57 by aahlaqqa          #+#    #+#             */
/*   Updated: 2023/11/22 22:06:03 by aahlaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	len;

	if (s == NULL)
		return (NULL);
	len = ft_strlen(s);
	while (len > 0)
	{
		if (s[len] == (char)c)
			return ((char *)(s + len));
		len--;
	}
	if (s[0] == (char)c)
		return ((char *)s);
	return (NULL);
}

