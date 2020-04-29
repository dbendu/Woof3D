/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_quit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 00:18:14 by user              #+#    #+#             */
/*   Updated: 2020/04/30 00:35:01 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "quit_all.h"

void	map_quit(t_map *map)
{
	const int	max_y = vec_size(&map->map);
	int			y;

	y = 0;
	while (y < max_y)
	{
		vec_destroy(&map->map[y]);
		y += 1;
	}
	vec_destroy(&map->map);
}
