/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanz-ar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 14:28:55 by vsanz-ar          #+#    #+#             */
/*   Updated: 2023/01/28 15:22:16 by vsanz-ar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"
#ifndef BUFF_SIZE
# define BUFF_SIZE 1024
#endif

//TODO BUFFER TAMAÑO 0 INVALIDO
char	*get_next_line(int fd)
{
	static char	*stash = NULL;
	char		*buff;
	char		*res;
	int			bytes;

	if (stash == NULL)
	{
		stash = malloc(sizeof(char) * 2048);
		stash[0] = '\0';
	}
	buff = malloc(sizeof(char) * BUFF_SIZE);
	buff[BUFF_SIZE] = '\0';
	bytes = read(fd, buff, BUFF_SIZE);
	if (bytes == 0 || bytes == -1)
	{
		free(buff);
		free(stash);
		return (NULL);
	}
	stash = fill_stash(stash, buff);
	while (ft_strend(buff) == -1)
	{
		bytes += read(fd, buff, BUFF_SIZE);
		stash = fill_stash(stash, buff);
	}
	free(buff);
	res = stash_line(stash);
	stash = stash + ft_strend(stash) + 1;
	return (res);
}

char	*fill_stash(char *stash, char *buff)
{
	int	i;
	int	j;

	j = 0;
	i = ft_strlen(stash);
	while (buff[j] != '\0')
		stash[i++] = buff[j++];
	stash[i] = '\0';
	return (stash);
}

char	*stash_line(char *stash)
{
	int 	i;
	char	*line;

	i = ft_strend(stash);
	line = malloc(sizeof(char) * (i + 2));
	line[i + 1] = '\0';
	while (i >= 0)
	{
		line[i] = stash[i];
		i--;
	}
	return (line);
}

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
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
	return (-1);
}
