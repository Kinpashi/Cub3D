/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahlaqqa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 09:30:50 by aahlaqqa          #+#    #+#             */
/*   Updated: 2024/01/03 09:30:52 by aahlaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*extracted_line(char *str)
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

char	*remain_line(char *str)
{
	char	*new_str;
	int		i;
	int		x;

	i = 0;
	x = 0;
	if (str == NULL)
		return (NULL);
	while (str[i] != '\0' && str[i] != '\n')
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

int	new_line_check(char *s)
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
			return (free(buffer), free(str), NULL);
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
	static char	*str[OPEN_MAX];
	char		*line;

	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	str[fd] = read_line(str[fd], fd);
	if (!str[fd])
		return (NULL);
	line = extracted_line(str[fd]);
	if (line == NULL)
	{
		free(str[fd]);
		str[fd] = NULL;
	}
	str[fd] = remain_line(str[fd]);
	return (line);
}
int main()
{
	int i = 0;
	int fd1 = open("file1.txt", O_RDONLY);
	int fd2 = open("file2.txt", O_RDONLY);
	int fd3 = open("file3.txt", O_RDONLY);

	while(i++ < 4)
	{
		char *s1 = get_next_line(fd1);
		char *s2 = get_next_line(fd2);
		char *s3 = get_next_line(fd3);

		printf("%s", s1);
		printf("%s", s2);
		printf("%s", s3);
	}
}