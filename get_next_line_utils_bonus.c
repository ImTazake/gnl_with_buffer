#include "get_next_line_bonus.h"

size_t	stash_len(t_stash *stash)
{
	size_t	n;

	n = 0;
	while (stash->pos + n < stash->end && stash->buf[stash->pos + n] != '\n')
		n++;
	if (stash->pos + n < stash->end)
		n++;
	return (n);
}

int	join_stash(char **line, size_t *len, const char *part, size_t n)
{
	char	*res;
	size_t	i;

	if (*len == SIZE_MAX || n > SIZE_MAX - *len - 1)
		return (0);
	res = malloc(*len + n + 1);
	if (!res)
	{
		free(*line);
		*line = NULL;
		return (0);
	}
	i = -1;
	while (++i < *len)
		res[i] = (*line)[i];
	i = -1;
	while (++i < n)
		res[*len + i] = part[i];
	*len += n;
	res[*len] = '\0';
	free(*line);
	*line = res;
	return (1);
}

int	take_stash(char **line, size_t *len, t_stash *stash)
{
	size_t	n;
	int		ok;

	n = stash_len(stash);
	ok = join_stash(line, len, stash->buf + stash->pos, n);
	if (!ok)
		return (1);
	stash->pos += n;
	return (stash->buf[stash->pos - 1] == '\n');
}

int	refill_buf(int fd, t_stash *stash, char **line)
{
	ssize_t	n;

	n = read(fd, stash->buf, BUFFER_SIZE);
	stash->pos = 0;
	stash->end = 0;
	if (n > 0)
	{
		stash->end = n;
		return (1);
	}
	if (n < 0)
	{
		free(*line);
		*line = NULL;
	}
	return (0);
}
