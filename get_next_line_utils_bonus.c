/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enpassel <enpassel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 16:18:30 by enpassel          #+#    #+#             */
/*   Updated: 2024/11/20 16:18:53 by enpassel         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_bzero(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		s[i] = 0;
		i++;
	}
}

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_clean_str(char *str)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	if (str[i] == '\n')
		i++;
	j = 0;
	while (str[i + j])
	{
		str[j] = str[i + j];
		j++;
	}
	str[j] = '\0';
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	size_t	i;
	size_t	j;
	size_t	size;

	i = 0;
	j = 0;
	size = 0;
	while (s2[size] != '\n' && s2[size] != '\0')
		size++;
	if (s2[size] == '\n')
		size++;
	str = malloc(sizeof(char) * (ft_strlen(s1) + size + 1));
	if (str == NULL)
		return (free(s1), NULL);
	while (s1[i] && s1)
	{
		str[i] = s1[i];
		i++;
	}
	while (s2 && j++ < size)
		str[i + j - 1] = s2[j - 1];
	str[i + j - 1] = '\0';
	free(s1);
	return (str);
}

int	ft_check_return(char *str)
{
	size_t	i;

	i = 0;
	if (ft_strlen(str + i) == 0)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}
