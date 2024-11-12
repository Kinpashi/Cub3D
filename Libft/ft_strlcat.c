/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahlaqqa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 16:33:44 by aahlaqqa          #+#    #+#             */
/*   Updated: 2023/11/25 19:02:07 by aahlaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	l_dst;
	size_t	l_src;
	size_t	x;

	if (dst == NULL && dstsize == 0)
		return (ft_strlen(src));
	i = 0;
	x = ft_strlen(dst);
	l_dst = x;
	l_src = ft_strlen(src);
	if (dstsize == 0 || dstsize <= l_dst)
		return (l_src + dstsize);
	while (src[i] != '\0' && i < dstsize - l_dst - 1)
	{
		dst[x] = src[i];
		i++;
		x++;
	}
	dst[x] = '\0';
	return (l_dst + l_src);
}
