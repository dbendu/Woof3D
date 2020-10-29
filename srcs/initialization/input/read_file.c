/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburl <mburl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/25 18:04:49 by user              #+#    #+#             */
/*   Updated: 2020/10/29 12:38:02 by mburl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/stat.h>
#include <fcntl.h>
#include "initialization/input/input.h"
#include "libft.h"

static bool		useless_line(const char *line)
{
	while (*line == ' ' || *line == '\t')
		line += 1;
	if (*line == '\0')
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
		if (useless_line(line))
			free(line);
		else
			vec_pushback(&lines, &line);
	}
	return (lines);
}
