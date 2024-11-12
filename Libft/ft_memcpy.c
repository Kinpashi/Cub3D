/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahlaqqa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 09:58:51 by aahlaqqa          #+#    #+#             */
/*   Updated: 2023/11/27 11:45:12 by aahlaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*dst_cpy;
	unsigned char	*src_cpy;

	i = 0;
	dst_cpy = (unsigned char *)dst;
	src_cpy = (unsigned char *)src;
	if (dst_cpy == NULL && src_cpy == NULL)
		return (NULL);
	if (dst_cpy == src_cpy)
		return (src_cpy);
	while (i < n)
	{
		dst_cpy[i] = src_cpy[i];
		i++;
	}
	return (dst);
}
