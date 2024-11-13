#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE 
#   define BUFFER_SIZE 10
#endif

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h> 

typedef struct s_list
{
    char    *str_buf;
    struct s_list   *next;
}       t_list;

char    *get_next_line(int fd);
char    *get_line(t_list *list);
char    *get_next_line(int fd);

int     len_to_newline(t_list *list);
int     found_newline(t_list *list);


void    ft_dealloc(t_list **list, t_list *clean_node, char *buf);
void    copy_str(t_list *list, char *str);
void    create_list(t_list **list, int fd);
void    append(t_list **list, char *buf);
void    clean_list(t_list **list);

t_list  *find_last_node(t_list  *list);

int     main(void);

#endif