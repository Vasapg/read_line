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
	static char		*buff = NULL;
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
		buff[BUFF_SIZE] = '\0';
	}
	j = ft_strend(buff);
	line = buff_line(buff, j);
	i = 0;
	if (j == 0)
	{
		free(buff);
		buff = NULL;
		return (line);
	}
	return (line);
}

char	*buff_line(char *buff, int npos)
{
	char	*line;
	int		i;

	line = malloc(sizeof(char) * (npos + 3));
	i = 0;
	while (i < npos)
	{
		line[i] = buff[i];
		//printf("char: %c en posicion %i\n", line[i], i);
		i++;
	}
	line[i] = '\n';
	line[i + 1] = '\0';
	return (line);
}

int	ft_strend(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0' && i < BUFF_SIZE)
	{
		if (s[i] == '\n')
			return (i);
		i++;
	}
	return (i);
}
