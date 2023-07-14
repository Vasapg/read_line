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

char	*listLine(t_list **str_list, int length)
{
	char *res;
	int pos;

	pos = 0;
	res = malloc(sizeof(char) * (length + 1));
	res[length] = '\0';
	while ((*str_list)->next != NULL)
	{
		ft_memmove(res + pos, (*str_list)->content, ft_strlen((*str_list)->content));
		pos += ft_strlen((*str_list)->content);
		free((*str_list)->content);
		(*str_list) = (*str_list)->next;
	}
	//free(*str_list);
	return (res);
}

char	*get_next_line(int fd)
{
	char	buff[BUFFER_SIZE];
	static char stash[BUFFER_SIZE];
	t_list 		**str_list;
	char		*str_aux;
	int			pos;
	int 		length;
	int			final;

	final = 0;
	length = 0;
	str_list = malloc(sizeof(struct t_list *));
	if (stash[0] != '\0')
	{
		str_aux = ft_strdup(stash, '\0');
		length += ft_strlen(str_aux);
		ft_lstadd_back(str_list, ft_lstnew(str_aux));
		stash[0] = '\0';
	}
	while ((final = read(fd, buff, BUFFER_SIZE)) >= 0)
	{
		if ((pos = ft_strend(buff)) != -1)
		{
			str_aux = ft_strdup(buff, '\n');
			length += ft_strlen(str_aux);
			ft_lstadd_back(str_list, ft_lstnew(str_aux));
			//ft_memmove(buff, buff+pos+1, BUFFER_SIZE);
			//buff[ft_strlen(buff)] = '\0';
			ft_memmove(stash, buff+pos+1, BUFFER_SIZE);
			stash[ft_strlen(stash)] = '\0';
			return listLine(str_list, length);			
		}
		if (final == 0 && stash[0] != '\0')
		{
			str_aux = ft_strdup(buff, '\0');
			stash[0] = '\0';
			return (str_aux);
		}
		if (final == 0)
			return (NULL);
		str_aux = ft_strdup(buff, '\0');
		length += ft_strlen(str_aux);
		ft_lstadd_back(str_list, ft_lstnew(str_aux));
	}
	return (NULL);
}