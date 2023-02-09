/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanz-ar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 14:29:05 by vsanz-ar          #+#    #+#             */
/*   Updated: 2023/02/09 12:23:02 by vsanz-ar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);
char	*stash_line(char *buff);
int		ft_strlen(char *s);
int		ft_strend(const char *s);
char	*fill_stash(char *stash, char *buff, int bytes);
char	*buff_to_stash(char *stash, int fd);
char	*shrunk_stash(char *stash, int length);
#endif
