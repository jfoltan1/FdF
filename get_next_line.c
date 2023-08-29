/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfoltan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 14:57:20 by jfoltan           #+#    #+#             */
/*   Updated: 2023/08/24 14:59:02 by jfoltan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "fdf.h"

#define BUFFER_SIZE 15

size_t	get_len(const char *c)
{
	int	i;

	i = 0;
	while (c[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s && *s != (char)c)
		s++;
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}

char	*ft_strjoin_void(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!s1)
	{
		s1 = (char *)malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	str = malloc((get_len(s1) + get_len(s2) + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	i = -1;
	j = 0;
	if (s1)
		while (s1[++i])
			str[i] = s1[i];
	while (s2[j])
		str[i++] = s2[j++];
	str[get_len(s1) + get_len(s2)] = '\0';
	free(s1);
	return (str);
}

char	*ft_line(char *storage)
{
	int		i;
	char	*str;

	i = 0;
	if (!storage[i])
		return (NULL);
	while (storage[i] && storage[i] != '\n')
		i++;
	str = (char *)malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (storage[i] && storage[i] != '\n')
	{
		str[i] = storage[i];
		i++;
	}
	if (storage[i] == '\n')
	{
		str[i] = storage[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_save(char *storage)
{
	int		i;
	int		pos;
	char	*str;

	i = 0;
	while (storage[i] && storage[i] != '\n')
		i++;
	if (!storage[i])
	{
		free(storage);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (get_len(storage) - i + 1));
	if (!str)
	{
		free(str);
		return (NULL);
	}
	i++;
	pos = 0;
	while (storage[i])
		str[pos++] = storage[i++];
	str[pos] = '\0';
	free(storage);
	return (str);
}

char	*ft_read_storage(int fd, char *storage)
{
	char	*buff;
	int		bytes;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	bytes = 1;
	while (!ft_strchr(storage, '\n') && bytes != 0)
	{
		bytes = read(fd, buff, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(buff);
			free(storage);
			return (NULL);
		}
		buff[bytes] = '\0';
		storage = ft_strjoin_void(storage, buff);
	}
	free(buff);
	return (storage);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*storage[5000];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	storage[fd] = ft_read_storage(fd, storage[fd]);
	if (!storage[fd])
		return (NULL);
	line = ft_line(storage[fd]);
	storage[fd] = ft_save(storage[fd]);
	return (line);
}

/*char	*ft_nextline(char *buff)
{
	char	*next;
	int		i;
	int		a;

	i = 0;
	a = 0;
	while (buff[i] && buff[i] != '\n')
		i++;
	if (!buff[i])
	{
		free(buff);
		return (NULL);
	}
	next = ft_calloc(((get_len(buff)) - i + 1), sizeof(char));
	i++;
	while (buff[i])
	{
		next[a] = buff[i];
		i++;
		a++;
	}
	free (buff);
	return (next);
}

char	*ft_get_line(char *buff)
{
	char	*line;
	int		i;

	i = 0;
	if (!buff[i])
		return (NULL);
	while (buff[i] && buff[i] != '\n')
		i++;
	line = ft_calloc(i + 2, sizeof(char));
	i = 0;
	while (buff[i] && buff[i] != '\n')
	{
		line[i] = buff[i];
		i++;
	}
	if (buff[i] && buff[i] == '\n')
		line[i++] = '\n';
	return (line);
}

char	*ft_freemebaby(char *result, char *buff)
{
	char	*temp;

	temp = ft_strjoin (result, buff);
	free (result);
	return (temp);
}

char	*ft_read_file(int fd, char *result)
{
	int		bytes_read;
	char	*buff;

	bytes_read = 1;
	if (!result)
		result = ft_calloc(1, 1);
	buff = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buff, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free (buff);
			free (result);
			return (NULL);
		}
		buff[bytes_read] = 0;
		result = ft_freemebaby(result, buff);
		if (ft_strchr_gnl(result, '\n'))
			break ;
	}
	free (buff);
	return (result);
}

char	*get_next_line(int fd)
{
	static char		*buff;
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buff = ft_read_file(fd, buff);
	if (!buff)
		return (NULL);
	line = ft_get_line(buff);
	printf("%s\n", line);
	buff = ft_nextline(buff);
	return (line);
}*/
