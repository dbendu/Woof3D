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
	const char	*line = *lineptr;
	int			wall_c;

	if (*line == 'X')
	{
		point->wall = false;
		line += 1;
	}
	else
	{
		wall_c = ft_atoi(line);
		point->wall = wall_c ? true : false;
		point->wall_c = (wall_c > 5) ? 1 : wall_c;
		while (ft_isdigit(*line))
			line += 1;
	}
	*lineptr = line;
}

static void				create_fake_point(int x, t_point *point)
{
	point->x = x;
	point->wall = 1;
	point->wall_c = 1;
}

static t_vector_point	convert_line(const char *line, size_t y_position,
	size_t *m_size)
{
	t_vector_point	points_line;
	t_point			point;
	size_t			cols;

	point.y = y_position * CELL_SIZE;
	point.x = 0;
	cols = 2;
	points_line = vec_create(20, sizeof(t_point));
	create_fake_point(point.x, &point);
	vec_pushback(&points_line, &point);
	while (true)
	{
		point.x += CELL_SIZE;
		while (*line == ' ' || *line == '\t')
			line += 1;
		if (*line == '\0')
			break ;
		get_point(&line, &point);
		vec_pushback(&points_line, &point);
		cols++;
	}
	create_fake_point(point.x + CELL_SIZE, &point);
	vec_pushback(&points_line, &point);
	*m_size = (cols > *m_size) ? cols : *m_size;
	return (points_line);
}

static t_vector_point	create_fake_line(size_t y_position, size_t size)
{
	t_vector_point	points_line;
	t_point			point;
	size_t			i;

	i = 0;
	point.wall_c = 1;
	point.wall = 1;
	point.x = 0;
	point.y = y_position;
	points_line = vec_create(20, sizeof(t_point));
	while (i < size)
	{
		create_fake_point(point.x, &point);
		vec_pushback(&points_line, &point);
		point.x += CELL_SIZE;
		i++;
	}
	return (points_line);
}

t_vector_point			*convert_file_to_map(const t_vector_char *lines)
{
	const size_t	lines_count = vec_size(&lines) + 2;
	size_t			line_index;
	t_vector_point	map_line;
	t_vector_point	*map;
	size_t			max_size;

	map = vec_create(lines_count, sizeof(t_vector_point));
	line_index = 1;
	max_size = 0;
	map_line = create_fake_line(0, 500);
	vec_pushback(&map, &map_line);
	while (line_index < lines_count - 1)
	{
		map_line = convert_line(lines[line_index - 1], line_index, &max_size);
		vec_pushback(&map, &map_line);
		line_index++;
	}
	map_line = create_fake_line(line_index, max_size);
	vec_pushback(&map, &map_line);
	return (map);
}
