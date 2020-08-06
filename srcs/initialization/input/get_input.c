/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburl <mburl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/25 17:47:55 by user              #+#    #+#             */
/*   Updated: 2020/08/04 15:59:05 by mburl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "initialization/input/input.h"
#include "initialization/input/input_utils.h"
#include <stdio.h>

static void	free_file(t_vector_char *lines)
{
	const size_t	lines_count = vec_size(&lines);
	size_t			line_index;

	line_index = 0;
	while (line_index < lines_count)
	{
		free(lines[line_index]);
		line_index += 1;
	}
	vec_destroy(&lines);
}

bool		invalid_row(t_vector_point *map, int y, int x)
{
	int		i;
	int		j;

	i = 0;
	while (i < y)
	{
		j = 0;
		while (j < x)
		{
			if (!(0 <= map[i][j].wall_c && map[i][j].wall_c < 6))
				return (true);
			if ((i == 0 || i == y - 1) && !map[i][j].wall)
				return (true);
			j++;
		}
		i++;
	}
	return (false);
}

bool		invalid_map(t_map map)
{
	int		i;
	int		j;
	int		saved_row;

	i = 0;
	saved_row = vec_size(&map.map[0]);
	while (i < vec_size(map.map))
	{
		j = 0;
		if (!(map.map[i][0].wall && map.map[i][vec_size(&map.map[i]) - 1].wall))
			return (true);
		while (j < vec_size(&map.map[i]))
			j++;
		if (saved_row != j)
			return (true);
		i++;
	}
	if (invalid_row(map.map, vec_size(map.map), vec_size(&map.map[0])))
		return (true);
	return (false);
}

t_map		get_input(const char *filename)
{
	t_map			map;
	t_vector_char	*lines;

	lines = read_file(filename);
	map.map = convert_file_to_map(lines);
	map.hero = init_hero(find_hero_position(lines));
	if (invalid_map(map))
		ft_error("Invalid map", NULL, 0);
	free_file(lines);
	return (map);
}
