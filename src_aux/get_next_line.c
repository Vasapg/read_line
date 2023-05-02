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
		(*str_list) = (*str_list)->next;
	}
	ft_memmove(res + pos, (*str_list)->content, ft_strlen((*str_list)->content));
	free(str_list);
	return (res);
}

char	*get_next_line(int fd)
{
	static char	buff[BUFFER_SIZE + 1];
	t_list 		**str_list;
	char		*str_aux;
	int			pos;
	int 		length;

	length = 0;
	str_list = malloc(sizeof(struct t_list *));
	if ((read(fd, buff, BUFFER_SIZE)) <= 0)
		return (NULL);
	while ((pos = ft_strend(buff)) == -1)
	{
		str_aux = ft_strdup(buff);
		length += ft_strlen(str_aux);
		printf("añado %s, con long total: %i\n", str_aux, length);
		ft_lstadd_back(str_list, ft_lstnew(str_aux));
		read(fd, buff, BUFFER_SIZE);
	}
	str_aux = malloc(pos + 2);
	str_aux[pos + 1] = '\0';
	ft_memmove(str_aux, buff, pos + 1);
	length += ft_strlen(str_aux);
	printf("añado %s, con long total: %i\n", str_aux, length);
	ft_lstadd_back(str_list, ft_lstnew(str_aux));
	ft_memmove(buff, buff+pos+1, ft_strlen(buff + pos + 1));
	return listLine(str_list, length);
}

/*Antiguo while
	while (read(fd, buff, BUFFER_SIZE) != 0)
	{
		if (str_list == NULL)
			str_list = malloc(sizeof(struct t_list *));
		pos = ft_strend(buff);
		printf("buff: %s, pos: %i\n", buff, pos);
		if(pos != -1)
		{
			str_aux = malloc(pos + 2);
			str_aux[pos + 1] = '\0';
			ft_memmove(str_aux, buff, pos + 1);
			length += ft_strlen(str_aux);
			//printf("añado %s, con long total: %i\n", str_aux, length);
			ft_lstadd_back(str_list, ft_lstnew(str_aux));
			ft_memmove(buff, buff+pos, ft_strlen(buff + pos));
			return listLine(str_list, length);
		}
		str_aux = ft_strdup(buff);
		length += ft_strlen(str_aux);
		//printf("añado %s, con long total: %i\n", str_aux, length);
		ft_lstadd_back(str_list, ft_lstnew(str_aux));
	}
*/