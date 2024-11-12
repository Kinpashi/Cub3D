/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahlaqqa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 15:43:30 by aahlaqqa          #+#    #+#             */
/*   Updated: 2024/01/01 17:23:03 by aahlaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

char	*extract_line(char *str)
{
	char	*line;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (str[0] == '\0')
		return (NULL);
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	if (str[i] == '\n')
	{
		line = malloc(i + 2);
		if (!line)
			return (NULL);
		line[i + 1] = '\0';
		while (j <= i)
		{
			line[j] = str[j];
			j++;
		}
	}
	else
		line = ft_strdup(str);
	return (line);
}

int	new_line_check(const char *s)
{
	int	i;

	i = 0;
	if (s == NULL)
		return (0);
	while (s[i])
	{
		if (s[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*remain_line(char *str)
{
	char	*new_str;
	int		i;
	int		x;

	x = 0;
	i = 0;
	if (str == NULL)
		return (NULL);
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	if (str[i] == '\0')
		return (free(str), NULL);
	new_str = malloc(ft_strlen(str) - i);
	if (!new_str)
		return (free(str), NULL);
	if (str[i] == '\n')
		i++;
	while (str[i + x])
	{
		new_str[x] = str[i + x];
		x++;
	}
	new_str[x] = '\0';
	return (free(str), new_str);
}

char	*read_line(char *str, int fd)
{
	char	*buffer;
	ssize_t	num_bytes;

	buffer = ft_calloc(BUFFER_SIZE + 1, 1);
	if (!buffer)
		return (free(str), NULL);
	while (new_line_check(str) == 0)
	{
		num_bytes = read(fd, buffer, BUFFER_SIZE);
		if (num_bytes <= 0)
		{
			if (num_bytes == 0)
				return (free(buffer), str);
			return (free(str), free(buffer), NULL);
		}
		str = ft_strjoin(str, buffer);
		if (!str)
			return (NULL);
		ft_bzero(buffer, BUFFER_SIZE);
	}
	free(buffer);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*lines;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str = read_line(str, fd);
	if (!str)
		return (NULL);
	lines = extract_line(str);
	if (lines == NULL)
	{
		free(str);
		str = NULL;
	}
	str = remain_line(str);
	return (lines);
}

// int main()
// {
// 	int fd;
// 	char *line;
// 	fd = open("file.txt", O_RDONLY);
// 	line = get_next_line(fd);
// 	printf("%s", line);
// 	free(line);
// 	line = get_next_line(fd);
// 	printf("%s",line);
// 	system("leaks a.out");
// 	free(line);

// }
