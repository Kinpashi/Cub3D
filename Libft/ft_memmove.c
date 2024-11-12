/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahlaqqa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 12:35:15 by aahlaqqa          #+#    #+#             */
/*   Updated: 2023/11/25 19:58:05 by aahlaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	char	*dest;
	char	*surc;

	dest = (char *)dst;
	surc = (char *)src;
	i = 0;
	if (dst == NULL && src == NULL)
		return (NULL);
	if (dest > surc)
	{
		while (len-- > 0)
		{
			dest[len] = surc[len];
		}
	}
	else
	{
		while (len > i)
		{
			dest[i] = surc[i];
			i++;
		}
	}
	return (dst);
}
