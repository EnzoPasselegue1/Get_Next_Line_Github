/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enpassel <enpassel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 16:17:25 by enpassel          #+#    #+#             */
/*   Updated: 2024/11/20 16:17:36 by enpassel         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_getline(int fd, int size, char *line, char str[OPEN_MAX][BUFFER_SIZE
		+ 1])
{
	while (size && ft_check_return(line) == 0)
	{
		size = read(fd, str[fd], BUFFER_SIZE);
		if (size == -1)
			return (ft_bzero(str[fd]), free(line), NULL);
		str[fd][size] = '\0';
		line = ft_strjoin(line, str[fd]);
		if (line == NULL)
			return (NULL);
	}
	return (line);
}

char	*ft_strdup(const char *s)
{
	char	*dup;
	size_t	len;
	size_t	i;

	len = 0;
	while (s[len] != '\n' && s[len] != '\0')
		len++;
	if (s[len] == '\n')
		len++;
	dup = malloc((len + 1) * sizeof(char));
	if (dup == NULL)
		return (dup);
	i = 0;
	while (i < len)
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char	*get_next_line(int fd)
{
	static char	str[OPEN_MAX][BUFFER_SIZE + 1];
	char		*line;
	int			size;

	size = 1;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (read(fd, NULL, 0) < 0)
		return (ft_bzero(str[fd]), NULL);
	line = ft_strdup(str[fd]);
	if (!line)
		return (NULL);
	line = ft_getline(fd, size, line, str);
	if (line == NULL)
		return (NULL);
	ft_clean_str(str[fd]);
	if (line[0] == '\0')
		return (free(line), NULL);
	return (line);
}
