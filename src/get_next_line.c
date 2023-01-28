/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanz-ar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 14:28:55 by vsanz-ar          #+#    #+#             */
/*   Updated: 2023/01/28 14:47:49 by vsanz-ar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"
#ifndef BUFF_SIZE
# define BUFF_SIZE 1024
#endif

char	*get_next_line(int fd)
{
	char static		*buff = NULL;
	char			*line;
	int				i;
	int				j;

	if (buff == NULL)
	{
		buff = malloc(sizeof(char) * BUFF_SIZE);
		i = read(fd, buff, BUFF_SIZE);
		if (i == 0 || i == -1)
		{
			free(buff);
			buff = NULL;
			return (NULL);
		}
	}
	j = ft_strend(buff);
	line = buff_line(buff, j);
	i = 0;
	while (buff[j] != '\0')
		buff[i++] = buff[j++];
	buff[i] = '\0';
	if ((i == 0 || buff[j + 1] == '\0'))
	{
		free(buff);
		buff = NULL;
	}
	return (line);
}

char	*buff_line(char *buff, int npos)
{
	char	*line;
	int		i;

	line = malloc(sizeof(char) * (npos + 1));
	i = 0;
	while (i <= npos)
	{
		line[i] = buff[i];
		i++;
	}
	return (line);
}

int	ft_strend(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '\n')
			return (i);
		i++;
	}
	return (i);
}
