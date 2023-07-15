/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanz-ar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 16:24:22 by vsanz-ar          #+#    #+#             */
/*   Updated: 2023/03/19 16:31:15 by vsanz-ar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#ifndef BUFF_SIZE
# define BUFF_SIZE 1024
#endif


char	*ft_strdup(char *s1, char end)
{
	char	*ptr;
	int		i;

	i = 0;
	while (s1[i] != end)
		i++;
	ptr = (char *)malloc((i + 1) * sizeof(char));
	if (ptr == NULL)
		return (0);
	i = 0;
	while (s1[i] != end)
	{
		ptr[i] = s1[i];
		i++;
	}
	ptr[i++] = end;
	ptr[i] = '\0';
	return (ptr);
}

void	*ft_memmove(void *dst, void *src, size_t len)
{
	int	i;

	i = 0;
	if (dst == NULL && src == NULL)
		return (NULL);
	while (i < (int)len)
	{
		if (src > dst)
			((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
		else
			((unsigned char *)dst)[len - i - 1]
				= ((unsigned char *)src)[len - i - 1];
		i++;
	}
	return (dst);
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