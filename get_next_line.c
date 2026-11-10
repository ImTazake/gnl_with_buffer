#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static t_stash	stash;
	char			*line;
	size_t			len;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, NULL, 0) < 0)
		return (NULL);
	line = NULL;
	len = 0;
	while (1)
	{
		if (stash.pos == stash.end && !refill_buf(fd, &stash, &line))
			return (line);
		if (take_stash(&line, &len, &stash))
			return (line);
	}
}

// #include <fcntl.h>
// #include <stdio.h>

// int	main(int argc, char **argv)
// {
// 	int		fd;
// 	char	*line;

// 	if (argc != 2)
// 		return (1);
// 	fd = open(argv[1], O_RDONLY);
// 	if (fd < 0)
// 		return (1);
// 	line = get_next_line(fd);
// 	while (line)
// 	{
// 		printf("%s", line);
// 		free(line);
// 		line = get_next_line(fd);
// 	}
// 	close(fd);
// 	return (0);
// }