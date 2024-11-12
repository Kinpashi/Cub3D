/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahlaqqa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 09:46:43 by aahlaqqa          #+#    #+#             */
/*   Updated: 2023/11/27 14:08:18 by aahlaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*new_s(size_t n)
{
	char	*ptr;

	ptr = (char *)malloc(sizeof(char) * (n + 1));
	if (!ptr)
	{
		return (NULL);
	}
	return (ptr);
}

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*str;
	char	*res;

	if (!s || !f)
		return (NULL);
	str = new_s(ft_strlen(s));
	if (!str)
		return (NULL);
	res = str;
	i = 0;
	while (s[i] != '\0')
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (res);
}

/*char upperchar(unsigned int i, char c)
{
	if( i % 2 == 0)
		return (toupper(c));
	else
		return (tolower(c));
}*/
