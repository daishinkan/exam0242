#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#  ifndef BUFFER_SIZE
#   define BUFFER_SIZE 8
#  endif

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>


int get_next_line(char **line);

#endif
