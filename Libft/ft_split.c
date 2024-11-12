/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahlaqqa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 09:01:38 by aahlaqqa          #+#    #+#             */
/*   Updated: 2023/11/25 14:39:46 by aahlaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**free_str(char **str_arr)
{
	int	i;

	i = 0;
	while (str_arr[i])
	{
		free(str_arr[i]);
		i++;
	}
	free(str_arr);
	return (NULL);
}

static int	count_words(char const *s, char c)
{
	int		i;
	int		j;
	char	word;

	word = c;
	i = 0;
	j = 0;
	if (s == NULL)
		return (0);
	while (s != NULL && s[i] != '\0')
	{
		if (word == c && s[i] != c)
			j++;
		word = s[i];
		i++;
	}
	return (j);
}

static int	c_char(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static char	*word(char const *s, char c)

{
	char	*p;
	int		i;

	i = 0;
	p = (char *)malloc(sizeof(char) * (c_char(s, c) + 1));
	if (!p)
		return (NULL);
	while (s[i] && s[i] != c)
	{
		p[i] = s[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		y;
	char	**big_str;

	i = 0;
	y = 0;
	big_str = (char **)malloc((count_words(s, c) + 1) * sizeof(*big_str));
	if (!big_str)
		return (NULL);
	while (s != NULL && s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		while (s[i] && s[i] != c)
		{
			big_str[y++] = word(s + i, c);
			if (!big_str[y - 1])
				return (free_str(big_str));
			while (s[i] != c && s[i])
				i++;
		}
	}
	big_str[y] = NULL;
	return (big_str);
}
