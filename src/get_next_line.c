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

char	*get_next_line(int fd)
{
	static char	*stash = NULL;
	char		*buff;
	int			bytes;

	if (stash == NULL)
	{
		stash = malloc(sizeof(char) * 2048);
		stash[0] = '\0';
	}
	if (ft_strend(stash) == -1)
	{
		buff = malloc(sizeof(char) * BUFF_SIZE);
		while (ft_strend(stash) == -1)
		{
			bytes = read(fd, buff, BUFF_SIZE);
			buff[BUFF_SIZE] = '\0';
			//printf("stash:\n%s\n", stash);
			stash = fill_stash(stash, buff);
			if (ft_strlen(stash) == 0 || bytes == 0 || bytes == -1)
			{
				free(buff);
				return (NULL);
			}
		}
		free(buff);
	}
	buff = stash_line(stash);
	stash += ft_strend(stash) + 1;
	return (buff);
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
	//printf("primer caracter linea:%c\n", line[0]);
	return (line);
}
