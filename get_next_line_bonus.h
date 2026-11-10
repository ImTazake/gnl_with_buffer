#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
# ifndef OPEN_MAX
#  define OPEN_MAX 1024
# endif

typedef struct s_stash
{
	char	buf[BUFFER_SIZE + 1];
	size_t	pos;
	size_t	end;
}	t_stash;

char	*get_next_line(int fd);
size_t	stash_len(t_stash *stash);
int		join_stash(char **line, size_t *len, const char *part, size_t n);
int		take_stash(char **line, size_t *len, t_stash *stash);
int		refill_buf(int fd, t_stash *stash, char **line);

#endif