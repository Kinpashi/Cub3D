/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahlaqqa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 09:30:09 by aahlaqqa          #+#    #+#             */
/*   Updated: 2023/11/23 12:22:16 by aahlaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static size_t	num_len(int nb)
{
	unsigned int	count;

	count = 0;
	while (nb != 0)
	{
		nb = nb / 10;
		count++;
	}
	return (count);
}

static size_t	alloc_len(int nb)
{
	size_t	length;

	if (nb <= 0)
		length = num_len(nb) + 2;
	else
		length = num_len(nb) + 1;
	return (length);
}

char	*ft_itoa(int n)
{
	char	*str;
	size_t	len;
	long	x;

	x = n;
	len = alloc_len(x);
	str = (char *)malloc(sizeof(char) * len);
	if (!str)
		return (NULL);
	if (x == 0)
		str[0] = '0';
	if (x < 0)
	{
		str[0] = '-';
		x = -x;
	}
	str[len - 1] = '\0';
	while (x)
	{
		--len;
		str[len - 1] = (x % 10) + 48;
		x = x / 10;
	}
	return (str);
}
