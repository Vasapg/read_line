/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanz-ar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 14:29:05 by vsanz-ar          #+#    #+#             */
/*   Updated: 2023/04/04 11:21:30 by vsanz-ar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

char	*get_next_line(int fd);
int		ft_strlen(char *s);
int		ft_strend(const char *s);
char	*ft_strdup(char *s1, char end);
char	*ft_strjoin(char *s1, char *s2);
void	*ft_memmove(void *dst, void *src, size_t len);
#endif