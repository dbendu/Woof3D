/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_file_to_map.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburl <mburl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/25 17:56:34 by user              #+#    #+#             */
/*   Updated: 2020/08/04 15:59:05 by mburl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "woofdefines.h"
#include "initialization/input/input_utils.h"

static void				get_point(const char **lineptr, t_point *point)
{
	const char *line = *lineptr;

	if (*line == 'X')
	{
		point->wall = false;
		line += 1;
	}
	else
	{
		point->wall = ft_atoi(line) ? true : false;
		point->wall_c = ft_atoi(line);
		while (ft_isdigit(*line))
			line += 1;
	}
	*lineptr = line;
}

static t_vector_point	convert_line(const char *line, size_t y_position)
{
	t_vector_point	points_line;
	t_point			point;

	point.y = y_position * CELL_SIZE;
	point.x = 0;
	points_line = vec_create(20, sizeof(t_point));
	while (true)
	{
		while (*line == ' ' || *line == '\t')
			line += 1;
		if (*line == '\0')
			break ;
		get_point(&line, &point);
		vec_pushback(&points_line, &point);
		point.x += CELL_SIZE;
	}
	return (points_line);
}

t_vector_point			*convert_file_to_map(const t_vector_char *lines)
{
	const size_t	lines_count = vec_size(&lines);
	size_t			line_index;
	t_vector_point	map_line;
	t_vector_point	*map;

	map = vec_create(lines_count, sizeof(t_vector_point));
	line_index = 0;
	while (line_index < lines_count)
	{
		map_line = convert_line(lines[line_index], line_index);
		vec_pushback(&map, &map_line);
		line_index += 1;
	}
	return (map);
}
