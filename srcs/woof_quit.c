/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   woof_quit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/25 18:58:31 by user              #+#    #+#             */
/*   Updated: 2020/04/25 18:59:55 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Woof3D.h"

static void	free_map(t_vector_point *map)
{
	const size_t	cols = vec_size(&map);
	size_t			col;

	col = 0;
	while (col < cols)
	{
		vec_destroy(&map[col]);
		col += 1;
	}
	vec_destroy(&map);
}

void	woof_quit(t_map *map)
{
	free_map(map->map);

}
