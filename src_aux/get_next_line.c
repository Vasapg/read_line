/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanz-ar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 14:28:55 by vsanz-ar          #+#    #+#             */
/*   Updated: 2023/04/04 11:19:22 by vsanz-ar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1024
#endif

char	*get_next_line(int fd)
{
	static char	*buff[BUFFER_SIZE];
	t_list 		**str_list;
	char		*str_aux;
	int			pos;
	int 		length;

	length = 0;
	while (read(fd, buff, BUFFER_SIZE) != 0)
	{
		pos = ft_strend(buff);
		if(pos != -1)
		{
			str_aux = ft_strdup(buff);
			memmove(str_aux, buff, pos);
			length += ft_strlen(str_aux);
			ft_lstadd_back(str_list, ft_lstnew(str_aux));
			memmove(buff, buff+pos, ft_strlen(buff + pos));
			free(str_aux);
			return listLine(*str_list, length);
		}
		str_aux = ft_strdup(buff);
		length += ft_strlen(str_aux);
		ft_lstadd_back(str_list, ft_lstnew(str_aux, length));
		free(str_aux);
	}
}

char	*listLine(t_list **str_list, int length)
{
	char *res;
	int pos;

	pos = 0;
	res = malloc(sizeof(char) * (length + 1));
	while ((*str_list)->next == NULL)
	{
		memmove(res + pos, (*str_list)->content, ft_strlen((*str_list)->content));
		pos = ft_strlen((*str_list)->content);
	}
	return (res);
}