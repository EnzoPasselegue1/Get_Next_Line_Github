/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enpassel <enpassel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 13:57:17 by enpassel          #+#    #+#             */
/*   Updated: 2024/11/13 13:25:14 by enpassel         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void    clean_list(t_list **list)
{
    t_list  *last_node;
    t_list  * clean_node;
    int     i;
    int     j;
    char    *buf;

    buf = malloc(BUFFER_SIZE + 1);
    clean_node = malloc(sizeof(t_list));
    if (!buf || !clean_node)
        return ;
    last_node = find_last_node(*list);
    i = 0;
    j = 0;
    while (last_node->str_buf[i] != '\0' && last_node->str_buf[i] != '\n' )
        ++i;
    while (last_node->str_buf[i] != '\0' && last_node->str_buf[++i])
    {
        buf[j++] = last_node->str_buf[i];
    }
    buf[j] = '\0';
    clean_node->str_buf = buf;
    clean_node->next = NULL;
    ft_dealloc(list, clean_node, buf);
}
char *get_next_line(int fd)
{
    static t_list       *list = NULL;
    char                *next_line;

    if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &next_line, 0) < 0)
        return (NULL);
    create_list(&list, fd);
    if (list == NULL)
        return (NULL);
    next_line = get_line(list);
    clean_list(&list);
    return (next_line);
}

void    create_list(t_list **list, int fd)
{
    char    read_buf;
    char    *buf;
    
    while (!found_newline(*list))
    {
        buf = malloc(BUFFER_SIZE + 1);
        if (!buf)
            return ;
        read_buf = read(fd, buf, BUFFER_SIZE);
        if (!read_buf)
        {
            free (buf);
            return ;
        }
        buf[read_buf] = '\0';
        append(list, buf); 
    }
    
}
void    append(t_list **list, char *buf)
{
    t_list  *new_node;
    t_list  *last_node;

    last_node = find_last_node(*list);
    new_node = malloc(sizeof(t_list));
    if (new_node == NULL)
        return ;
    if (last_node == NULL)
        *list = new_node;
    else
        last_node -> next = new_node;
    
    new_node -> str_buf = buf;
    new_node -> next = NULL;
}

char    *get_line(t_list *list)
{
    int size;
    char    *next_str;

    if (list == NULL)
        return (NULL);
    size = len_to_newline(list);
    next_str = malloc(size + 1);
    if (next_str == NULL)
        return (NULL);
    copy_str(list, next_str);
    return (next_str);
}

