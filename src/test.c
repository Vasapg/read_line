/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanz-ar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 14:31:46 by vsanz-ar          #+#    #+#             */
/*   Updated: 2023/01/28 15:15:46 by vsanz-ar         ###   ########.fr       */
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
		str = get_next_line(1);
		if (str != NULL)
			printf("LECTURA:%s", str);
	}
	free(str);
	return (1);
}
