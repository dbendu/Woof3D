/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburl <mburl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/25 17:47:55 by user              #+#    #+#             */
/*   Updated: 2020/11/04 12:49:43 by mburl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "initialization/input/input.h"
#include "initialization/input/input_utils.h"

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

t_map		get_input(const char *filename)
{
	t_map			map;
	t_vector_char	*lines;

	lines = read_file(filename);
	map.map = convert_file_to_map(lines);
	map.hero = init_hero(find_hero_position(lines));
	free_file(lines);
	return (map);
}
