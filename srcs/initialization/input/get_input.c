/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/25 17:47:55 by user              #+#    #+#             */
/*   Updated: 2020/04/25 19:22:28 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input.h"
#include "input_utils.h"

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
	// analysis_file(lines);
	// all else: textures reading, soundl loading, etc.
	map.map = convert_file_to_map(lines);
	map.hero = init_hero(find_hero_position(lines));
	free_file(lines);
	return (map);
}
