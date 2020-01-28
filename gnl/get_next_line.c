/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekindomb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 11:56:05 by ekindomb          #+#    #+#             */
/*   Updated: 2020/01/28 09:34:22 by ekindomb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while(str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *str)
{
	int i;
	char *copy;
	
	i = 0;
	if (!(copy = (char *)malloc(sizeof(char) * ft_strlen(str) + 1)))
		return (NULL);
	while (str[i])
	{
		copy[i] = str[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int i;
	int j;
	char *join;
	int n;
	int m;

	n = ft_strlen(s1);
	m = ft_strlen(s2);
	i = 0;
	j = 0;
	if (!(join = (char *)malloc(sizeof(char) * (n + m) + 1)))
		return (NULL);
	while (s1[i])
	{
		join[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		join[i + j] = s2[j];
		j++;
	}
	join[i + j] = '\0';
	return (join);
}

char *ft_strchr(char *str, int c)
{
	int i;

	i = 0;
	if ((char) c == '\0')
	   return (&str[ft_strlen(str)]);
	while (str[i])
	{
		if (str[i] == (char)c)
			return (&str[i]);
		i++;
	}
	return (NULL);
}
		
void	ft_strclr(char *str)
{
	int i;

	i = 0;
	while (i < ft_strlen(str))
	{
		str[i] = '\0';
		i++;
	}
}

int		ft_strcspn(char *str, char *charset)
{
	int count;

	count = 0;
	while (ft_strchr(charset, *str++) == 0)
		count++;
	return (count);
}

int		ret_line(char **stack, char **line)
{
	char *buff;

	if (!*stack[0])
		return (0);
	if (ft_strchr(stack[0], '\n'))
	{
		*(stack[0] + ft_strcspn(stack[0], "\n")) = '\0';
		*line = ft_strdup(stack[0]);
		buff= ft_strdup(ft_strchr(stack[0], '\0') + 1);
		ft_strclr(stack[0]);
		free(stack[0]);
		stack[0] = ft_strdup(buff);
		free(buff);
		return (1);
	}
	else
	{
		*line = ft_strdup(stack[0]);
		ft_strclr(stack[0]);
		free(stack[0]);
	}
	return (0);
}

char	*ft_strnew(int size)
{
	char *new;
	int i;

	i = 0;
	if (!(new = (char *)malloc(sizeof(char) * size + 1 )))
		return (NULL);
	while (i < size)
	{
		new[i] = '\0';
		i++;
	}
	new[i] = '\0';
	return (new);
}

int		get_next_line(char **line)
{
	char buffer[BUFFER_SIZE + 1];
	char *buf;
	static char *stack[fd_limit];
	int i;
	int ret;
	char *eol = NULL;

	if (!line || read(0, buffer, 0) == -1 || BUFFER_SIZE == 0)
		return (-1);
	if (!(stack[0]))
		stack[0] = ft_strnew(0);
	while (!(ft_strchr(stack[0], '\n')))
	{
		i = read(0, buffer, BUFFER_SIZE);
		buffer[i] = '\0';
		if (i == 0)
			break;
		buf = stack[0];
		stack[0] = ft_strjoin(buf, buffer);
		free(buf);
	}
	ret = ret_line(stack, line);
	if (ret == 1)
		return (1);
	else if (ret == 0)
	{
		if (!*line)
			*line = ft_strdup("\0");
		else
		{
			eol = ft_strjoin(*line, "\0");
			ft_strclr(*line);
			free(*line);
			*line = ft_strdup(eol);
		}
		stack[0] = NULL;
		return (0);
	}
	else
		return (-1);
}
