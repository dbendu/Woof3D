/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_hero_position.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburl <mburl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/25 18:29:35 by user              #+#    #+#             */
/*   Updated: 2020/11/04 12:53:20 by mburl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "woofdefines.h"
#include "initialization/input/input_utils.h"

static t_point	get_hero_position(const char *line, size_t y_position,
									bool *hero_founded)
{
	t_point	hero_posititon;

	hero_posititon.y = y_position;
	hero_posititon.x = 0;
	while (*line)
	{
		while (*line == ' ' || *line == '\t')
			line++;
		if (*line == 'X')
		{
			*hero_founded = true;
			break ;
		}
		else
		{
			line++;
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
			hero_position = get_hero_position(lines[line_index], line_index,
				&hero_founded);
			hero_position.x++;
			hero_position.y++;
			break ;
		}
		line_index += 1;
	}
	if (hero_founded == false)
		ft_error("can\'t find a hero", "find_hero_position", 0);
	return (hero_position);
}
