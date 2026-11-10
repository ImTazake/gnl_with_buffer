#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static t_stash	stash[OPEN_MAX];
	char			*line;
	size_t			len;

	if (fd < 0 || fd >= OPEN_MAX || BUFFER_SIZE <= 0
		|| read(fd, NULL, 0) < 0)
		return (NULL);
	line = NULL;
	len = 0;
	while (1)
	{
		if (stash[fd].pos == stash[fd].end
			&& !refill_buf(fd, &stash[fd], &line))
			return (line);
		if (take_stash(&line, &len, &stash[fd]))
			return (line);
	}
}

// #include <fcntl.h>
// #include <stdio.h>

// int	main(int argc, char **argv)
// {
// 	int		fd1;
// 	int		fd2;
// 	int		fd3;
// 	char	*line1;
// 	char	*line2;
// 	char	*line3;

// 	if (argc != 4)
// 		return (1);
// 	fd1 = open(argv[1], O_RDONLY);
// 	fd2 = open(argv[2], O_RDONLY);
// 	fd3 = open(argv[3], O_RDONLY);
// 	if (fd1 < 0 || fd2 < 0 || fd3 < 0)
// 		return (1);
// 	while (1)
// 	{
// 		line1 = get_next_line(fd1);
// 		line2 = get_next_line(fd2);
// 		line3 = get_next_line(fd3);
// 		if (!line1 && !line2 && !line3)
// 			break ;
// 		if (line1)
// 			printf("FD1: %s", line1);
// 		if (line2)
// 			printf("FD2: %s", line2);
// 		if (line3)
// 			printf("FD3: %s", line3);
// 		free(line1);
// 		free(line2);
// 		free(line3);
// 	}
// 	close(fd1);
// 	close(fd2);
// 	close(fd3);
// 	return (0);
// }
