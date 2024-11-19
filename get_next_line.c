#include "get_next_line.h"

char	*ft_free(char *buf, char *line)
{
	char	*tmp;

	tmp = ft_strjoin(buf, line);
	free(buf);
	return (tmp);
}

char	*get_buf(char *buf)
{
	int		i;
	int		j;
	char	*tmp;

	if (!buf)
		return (NULL);
	i = 0;
	while (buf[i] && buf[i] != '\n')
		i++;
	if (!buf[i])
	{
		free(buf);
        return (NULL);
	}
	tmp = ft_calloc(ft_strlen(buf) - i + 1, sizeof(char));
	if (!tmp)
        return (ft_calloc(1, 1));
	i++;
	j = 0;
	while (buf[i])
		tmp[j++] = buf[i++];
	free(buf);
	return (tmp);
}

char	*ft_line(char *buf)
{
	int		i;
	char	*line;

	if (!buf)
		return (NULL);
	i = 0;
	while (buf[i] && buf[i] != '\n')
		i++;
	line = ft_calloc(i + 2, sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (buf[i] && buf[i] != '\n')
	{
		line[i] = buf[i];
		i++;
	}
	if (buf[i] && buf[i] == '\n')
    {
		line[i++] = '\n';
    }
	return (line);
}

char	*read_file(int fd, char *buf)
{
	char	*buff;
	int		ret;

	if (!buf)
		buf = ft_calloc(1, 1);
	buff = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	ret = 1;
	while (ret > 0)
	{
		ret = read(fd, buff, BUFFER_SIZE);
		if (ret == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[ret] = 0;
		buf = ft_free(buf, buff);
		if (ft_strchr(buf, '\n'))
			break ;
	}
	free(buff);
	return (buf);
}

char	*get_next_line(int fd)
{
	char        *line;
	static char *buf;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, NULL, 0) < 0)
    {
		return (NULL);
    }
	buf = read_file(fd, buf);
	if (!buf)
    {
		return (NULL);
    }
	line = ft_line(buf);
    printf("line = %s\n", line);
    if (!line)
    {
        return (NULL);
    }
	buf = get_buf(buf);
    // if (!buf)
    // {
    //     return (0);
    // }
	return (line);
}