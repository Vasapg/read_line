/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanz-ar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 14:31:46 by vsanz-ar          #+#    #+#             */
/*   Updated: 2023/03/19 16:09:51 by vsanz-ar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"../src/get_next_line.h"
#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<string.h>

int	main(int argc, char *argv[])
{
	int		fd;
	char	*str;

	if (argc < 2)
		fd = 1;
	else if (argv[1] == "0")
		fd = open("no-text?", O_RDONLY);
	else
	{
		fd = open(argv[1], O_RDONLY);
	}
	str = malloc(sizeof(char) * 2048);
	while (str != NULL)
	{
		str = get_next_line(fd);
		if (str != NULL)
			printf("%s", str);
	}
	free(str);
	return (1);
}
