#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 10000000

#endif
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t elementCount, size_t elementSize);
char	*ft_strjoin(char const *s1, char const *s2);
char *ft_nextline (char *buff);
char *ft_get_line (char *buff);
char *ft_freemebaby(char *result, char *buff);
char	*ft_read_file(int fd, char *result);
char	*ft_strchr(const char *string, int searchedChar);
size_t	ft_strlen(const char *theString);
char	*get_next_line(int fd);
#endif
