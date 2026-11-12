/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisilva <tisilva@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 07:04:05 by tisilva           #+#    #+#             */
/*   Updated: 2026/11/12 19:30:39 by tisilva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
# if BUFFER_SIZE <= 0 || BUFFER_SIZE > 2147483647
#  error "Invalid BUFFER_SIZE"
# endif

typedef struct s_stash
{
	char	buf[BUFFER_SIZE];
	size_t	pos;
	size_t	end;
}	t_stash;

char	*get_next_line(int fd);
size_t	stash_len(t_stash *stash);
int		join_stash(char **line, size_t *len, const char *part, size_t n);
int		take_stash(char **line, size_t *len, t_stash *stash);
int		refill_buf(int fd, t_stash *stash, char **line);
#endif