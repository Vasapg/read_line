/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanz-ar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 14:28:55 by vsanz-ar          #+#    #+#             */
/*   Updated: 2023/02/09 17:09:03 by vsanz-ar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line_bonus.h"
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1024
#endif

char	*get_next_line(int fd)
{
	static char	**stash = NULL;
	char		*line;
	int			i;

	if (stash == NULL)
	{
		stash = malloc(sizeof(char *) * 20000);
		stash[19999] = NULL;
		i = 0;
		while (stash[i] != NULL)
			stash[i++] = NULL;
	}
	if (stash[fd] == NULL)
	{
		stash[fd] = malloc(sizeof(char) * 100000);
		stash[fd][0] = '\0';
	}
	if (ft_strend(stash[fd]) == -1)
	{
		stash[fd] = buff_to_stash(stash[fd], fd);
		if (stash[fd] == NULL)
		{
			free(stash);
			stash = NULL;
			return (NULL);
		}
	}
	line = stash_line(stash[fd]);
	stash[fd] = shrunk_stash(stash[fd], ft_strlen(line));
	return (line);
}

char	*buff_to_stash(char *stash, int fd)
{
	char	*buff;
	int		bytes;

	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	bytes = read(fd, buff, BUFFER_SIZE);
	if ((bytes <= 0 && ft_strlen(stash) == 0) || bytes == -1)
	{
		free(buff);
		free(stash);
		return (NULL);
	}
	buff[bytes] = '\0';
	stash = fill_stash(stash, buff, bytes);
	while (bytes > 0 && ft_strend(stash) == -1)
	{
		bytes = read(fd, buff, BUFFER_SIZE);
		buff[bytes] = '\0';
		stash = fill_stash(stash, buff, bytes);
	}
	free(buff);
	return (stash);
}

char	*shrunk_stash(char	*stash, int length)
{
	int	i;

	i = 0;
	while (stash[length] != '\0')
		stash[i++] = stash[length++];
	stash[i] = '\0';
	return (stash);
}

char	*fill_stash(char *stash, char *buff, int bytes)
{
	int	i;
	int	j;

	j = 0;
	i = ft_strlen(stash);
	while (buff[j] != '\0')
		stash[i++] = buff[j++];
	stash[i] = '\0';
	bytes = i;
	return (stash);
}

char	*stash_line(char *stash)
{
	int		i;
	char	*line;

	i = ft_strend(stash);
	if (i == -1)
		i = ft_strlen(stash) - 1;
	line = malloc(sizeof(char) * (i + 2));
	line[i + 1] = '\0';
	while (i >= 0)
	{
		line[i] = stash[i];
		i--;
	}
	return (line);
}
