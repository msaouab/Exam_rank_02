#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

char	*get_next_line(int fd)
{
	char	save[999999];
	char	buff[1];
	char	*line;
	int		i;

	i = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	save[i] = '\0';
	while (read(fd, buff, 1) == 1)
	{
		save[i] = buff[0];
		save[i + 1] = '\0';
		if (save[i] == '\n')
			break ;
		i++;
	}
	if (save[0] == '\0')
		return (NULL);
	line = malloc(i + 1);
	i = 0;
	while (save[i])
	{
		line[i] = save[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

int		main(void)
{
	char *line;
	int	fd;

	fd = open("text", O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			return (0);
		printf("%s", line);
	}
}