#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#	define BUFFER_SIZE 8
# endif
# ifndef fd_limit
#	define fd_limit 1024
# endif
int	ft_strlen(char *str);
char *ft_strdup(char *str);
char *ft_strjoin(char *s1, char *s2);
char *ft_strchr(char *str, int c);
void ft_strclr(char *str);
int	ft_strcspn(char *str, char *charset);
int	ret_line(char **stack, char **line);
int get_next_line(char **line);

#endif
