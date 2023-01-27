#include"get_next_line.h"
#include<stdio.h>
#include<fcntl.h>

int	main()
{
	int fd = open("texto.txt", O_RDONLY);
	char *str;
	
	str = malloc(sizeof(char) * 10);
	while (str != NULL)
	{
		str = get_next_line(fd);
		printf("lectura:%s", str);
	}
	free(str);
	return (1);
}
