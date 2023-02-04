/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanz-ar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 14:28:55 by vsanz-ar          #+#    #+#             */
/*   Updated: 2023/02/04 18:56:33 by vsanz-ar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"
#ifndef BUFF_SIZE
# define BUFF_SIZE 1024
#endif

char	*get_next_line(int fd)
{
	static char	*stash = NULL;
	char		*line;
	int			i;
	int			j;

	if (stash == NULL)
	{
		stash = malloc(sizeof(char) * 20000);
		stash[0] = '\0';
	}
	if (stash[ft_strend(stash)] == '\0')
	{
		stash = buff_to_stash(stash, fd);
		if (stash == NULL)
			return (NULL);
	}
	line = stash_line(stash);
	i = 0;
	j = ft_strend(stash) + 1;
	while (stash[j] != '\0')
		stash[i++] = stash[j++];
	stash[i] = '\0';
	return (line);
}

char	*buff_to_stash(char *stash, int fd)
{
	int		bytes;
	char	*buff;

	buff = malloc(sizeof(char) * BUFF_SIZE);
	bytes = read(fd, buff, BUFF_SIZE);
	if ((bytes == 0 || bytes == -1) && ft_strlen(stash) == 0)
	{
		free(buff);
		free(stash);
		return (NULL);
	}
	while (bytes > 0 && stash[ft_strend(stash)] == '\0')
	{
		stash = fill_stash(stash, buff);
		bytes = read(fd, buff, BUFF_SIZE);
	}
	free(buff);
	return (stash);
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
	int		i;
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
