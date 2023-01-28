#include"get_next_line.h"
#ifndef BUFF_SIZE
# define BUFF_SIZE 1024
#endif

char	*get_next_line(int fd)
{
	char static		*buff = NULL;
	int				bytes;

	bytes = 0;
	if (buff == NULL)
	{
		buff = malloc(sizeof(char) * BUFF_SIZE);	
		bytes = read(fd, buff, BUFF_SIZE);
	}
	if (ft_strchr(buff, '\n') != 0)
		return (cut_str(buff, ft_strchr()));
	else
	{
		return (buff);
	}
	if (bytes == 0)
	{
		free(buff);
		buff = NULL;
		return (NULL);
	}
}

char *cut_str(char *buff, int npos)
{
	int		i;
	char	*line;

	line = malloc(sizeof(char) * (npos + 1))
	i = 0;
	while (i <= npos)
	{
		line[i] = buff[i];
		i++;
	}
	npos = 0;
	while (buff[i] != '\0')
		buff[npos++] = buff[i++];
	buff[npos] = '\0';
	return (line);
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
