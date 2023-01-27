#include"get_next_line.h"
#ifndef BUFF_SIZE
# define BUFF_SIZE 1024
#endif

char	*get_next_line(int fd)
{
	char		*buff;
	static int	nline = 1;

	buff = malloc(sizeof(char) * BUFF_SIZE);
	if (nline == 1)
		bytes = read(fd, buff, BUFF_SIZE);
	if (ft_strchr(buff, '\n') != 0)
	{

	}
	else
		return (buff);
	if (bytes == 0)
		return (NULL);
}

int	ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c && s[i + 1] != '\0')
			return (i);
		i++;
	}
	return (0);
}
