/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanz-ar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 14:31:46 by vsanz-ar          #+#    #+#             */
/*   Updated: 2023/02/09 10:17:31 by vsanz-ar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"get_next_line.h"
#include<stdio.h>
#include<fcntl.h>

int	main(void)
{
	int		fd;
	char	*str;

	fd = open("texto.txt", O_RDONLY);
	str = malloc(sizeof(char) * 10);
	while (str != NULL)
	{
		str = get_next_line(fd);
		if (str != NULL)
			printf("%s", str);
	}
	free(str);
	return (1);
}
