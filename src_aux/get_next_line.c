/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanz-ar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 14:28:55 by vsanz-ar          #+#    #+#             */
/*   Updated: 2023/05/02 14:18:02 by vsanz-ar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1024
#endif

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

char	*get_next_line(int fd)
{
	static char stash[BUFFER_SIZE];
	char		*buff;
	char		*str_aux;
	int			pos;
	int 		length;
	int			final;

	final = 0;
	length = 0;
	buff = malloc(BUFFER_SIZE);
	//printf("stash: %s\n", stash);
	if (stash[0] != '\0')
	{
		if ((pos = ft_strend(stash)) != -1)
		{
			str_aux = ft_strdup(stash, '\n');
			ft_memmove(stash, stash + pos + 1, BUFFER_SIZE);
			stash[ft_strlen(stash)] = '\0';
			return (str_aux);
		}
		str_aux = ft_strdup(stash, '\0');
		length += ft_strlen(str_aux);
		ft_lstadd_back(str_list, ft_lstnew(str_aux));
		while(final < length)
			stash[final++] = '\0';
	}
	while ((final = read(fd, buff, BUFFER_SIZE)) >= 0)
	{
		if (final != 0)
			buff[final] = '\0';
		//printf("final:-%i-", final);
		if (((pos = ft_strend(buff)) != -1))
		{
			if(final != 0 && buff[0] != '\0')
			{
				str_aux = ft_strdup(buff, '\n');
				//printf("buff:-%s-", buff);
				//printf("str:-%s-", str_aux);
				length += ft_strlen(str_aux);
				ft_lstadd_back(str_list, ft_lstnew(str_aux));
				ft_memmove(stash, buff+pos+1, BUFFER_SIZE);
				//printf("stash:-%s-", stash);
				//printf("final:-%i-", final);
				stash[ft_strlen(stash)] = '\0';
			}
			return list_line(str_list, length);			
		}
		if (final <= 0)
			return (NULL);
		str_aux = ft_strdup(buff, '\0');
		length += ft_strlen(str_aux);
		ft_lstadd_back(str_list, ft_lstnew(str_aux));
	}
	return (NULL);
}