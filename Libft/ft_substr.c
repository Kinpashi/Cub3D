/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahlaqqa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 09:13:54 by aahlaqqa          #+#    #+#             */
/*   Updated: 2023/11/23 15:30:41 by aahlaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t			i;
	char			*ptr;

	i = 0;
	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
	{
		ptr = (char *)malloc(1);
		if (!ptr)
			return (NULL);
		ptr[0] = '\0';
		return (ptr);
	}
	if (len > ft_strlen(s + start))
		ptr = (char *)malloc(sizeof(char) * (ft_strlen(s + start) + 1));
	else
		ptr = (char *)malloc(sizeof(char) * (len + 1));
	if (!ptr)
		return (NULL);
	i = 0;
	while (s[start] && i < len)
		ptr[i++] = s[start++];
	ptr[i] = '\0';
	return (ptr);
}
