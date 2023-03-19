/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanz-ar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 16:24:22 by vsanz-ar          #+#    #+#             */
/*   Updated: 2023/03/19 16:39:47 by vsanz-ar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#ifndef BUFF_SIZE
# define BUFF_SIZE 1024
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

char	*ft_strjoin(char *s1, char *s2)
{
	int		size1;
	int		size2;
	char	*s3;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	size1 = ft_strlen(s1);
	size2 = ft_strlen(s2);
	s3 = malloc((size1 + size2 + 1) * sizeof(char));
	if (s3 == NULL)
		return (NULL);
	size2 = 0;
	size1 = 0;
	while (s1[size1] != '\0')
	{
		s3[size1] = s1[size1];
		size1++;
	}
	while (s2[size2] != '\0')
		s3[size1++] = s2[size2++];
	s3[size1] = '\0';
	return (s3);
}
