/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enpassel <enpassel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 16:14:26 by enpassel          #+#    #+#             */
/*   Updated: 2024/11/20 16:15:46 by enpassel         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	static char	str[BUFFER_SIZE + 1] = "\0";
	char		*line;
	int			size;

	size = 1;
	if (read(fd, NULL, 0) < 0)
		return (ft_bzero(str), NULL);
	line = ft_strdup(str);
	if (!line)
		return (NULL);
	while (size && ft_check_return(line) == 0)
	{
		size = read(fd, str, BUFFER_SIZE);
		if (size == -1)
			return (ft_bzero(str), free(line), NULL);
		str[size] = '\0';
		line = ft_strjoin(line, str);
		if (line == NULL)
			return (NULL);
	}
	ft_clean_str(str);
	if (line[0] == '\0')
		return (free(line), NULL);
	return (line);
}
