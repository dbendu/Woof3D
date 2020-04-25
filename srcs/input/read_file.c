/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/25 18:04:49 by user              #+#    #+#             */
/*   Updated: 2020/04/25 19:00:25 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/stat.h>
#include <fcntl.h>
#include "input.h"

static bool		is_dir(const char *filename)
{
	struct stat	statbuf;

	if (stat(filename, &statbuf) != 0)
		return (false);
	if (S_ISDIR(statbuf.st_mode))
		return (true);
	else
		return (false);
}

t_vector_char	*read_file(const char *filename)
{
	int				fd;
	t_vector_char	*lines;
	char			*line;

	if (is_dir(filename))
		ft_error("received path is directory", "read_file", 0);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		ft_error("can\'t open file", "read_file", 0);
	lines = vec_create(20, sizeof(t_vector_char));
	while (gnl(fd, &line, NULL) == GNL_OK)
	{
		if (*line != '\0')
			vec_pushback(&lines, &line);
		else
			free(line);
	}
	return (lines);
}
