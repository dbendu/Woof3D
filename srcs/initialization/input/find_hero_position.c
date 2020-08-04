/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_hero_position.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburl <mburl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/25 18:29:35 by user              #+#    #+#             */
/*   Updated: 2020/08/04 15:59:05 by mburl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "woofdefines.h"
#include "initialization/input/input_utils.h"

static t_point	get_hero_position(const char *line, size_t y_position)
{
	t_point	hero_posititon;

	hero_posititon.y = y_position;
	hero_posititon.x = 0;
	while (true)
	{
		while (*line == ' ' || *line == '\t')
			line += 1;
		if (*line == 'X')
			break ;
		else
		{
			while (ft_isdigit(*line))
				line += 1;
			hero_posititon.x += 1;
		}
	}
	return (hero_posititon);
}

t_point			find_hero_position(const t_vector_char *lines)
{
	const size_t	lines_count = vec_size(&lines);
	size_t			line_index;
	t_point			hero_position;
	bool			hero_founded;

	hero_founded = false;
	line_index = 0;
	ft_memset(&hero_position, 0, sizeof(t_point));
	while (line_index < lines_count)
	{
		if (ft_strchr(lines[line_index], 'X') != NULL)
		{
			hero_position = get_hero_position(lines[line_index], line_index);
			hero_founded = true;
			break ;
		}
		line_index += 1;
	}
	if (hero_founded == false)
		ft_error("can\'t find a hero", "find_hero_position", 0);
	return (hero_position);
}
