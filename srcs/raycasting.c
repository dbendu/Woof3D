/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburl <mburl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/27 21:25:37 by user              #+#    #+#             */
/*   Updated: 2020/11/02 15:50:58 by mburl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "structs/ray.h"
#include "woof3d.h"
#include "woofdefines.h"

static t_ray	raycast_x(t_position start, t_vector_point *map,
								float dir, float pov)
{
	float	dx;
	float	dy;
	t_ray	rayx;
	int		map_x;
	int		map_y;

	rayx.y = (int)start.y / CELL_SIZE * CELL_SIZE +
		(dir > 180 ? CELL_SIZE : -0.001);
	dy = dir > 180 ? CELL_SIZE : -CELL_SIZE;
	rayx.x = start.x + (start.y - rayx.y) / tan(to_rad(dir));
	dx = -dy / tan(to_rad(dir));
	map_x = rayx.x / CELL_SIZE;
	map_y = rayx.y / CELL_SIZE;
	while (map_x >= 0 && map_y >= 0 && map_x < vec_size(&map[0]) &&
		map_y < vec_size(&map) && map[map_y][map_x].wall == false)
	{
		rayx.x += dx;
		rayx.y += dy;
		map_x = rayx.x / CELL_SIZE;
		map_y = rayx.y / CELL_SIZE;
	}
	dx = rayx.x - start.x;
	dy = rayx.y - start.y;
	rayx.len = sqrt(dx * dx + dy * dy) * cos(to_rad(pov - dir));
	return (rayx);
}

static t_ray	raycast_y(t_position start, t_vector_point *map,
								float dir, float pov)
{
	float	dx;
	float	dy;
	t_ray	rayy;
	int		map_x;
	int		map_y;

	rayy.x = (int)start.x / CELL_SIZE * CELL_SIZE +
		((dir > 270 || dir < 90) ? CELL_SIZE : -0.001);
	dx = (dir > 270 || dir < 90) ? CELL_SIZE : -CELL_SIZE;
	rayy.y = start.y + (start.x - rayy.x) * tan(to_rad(dir));
	dy = -dx * tan(to_rad(dir));
	map_x = rayy.x / CELL_SIZE;
	map_y = rayy.y / CELL_SIZE;
	while (map_x >= 0 && map_y >= 0 && map_x < vec_size(&map[0]) &&
		map_y < vec_size(&map) && map[map_y][map_x].wall == false)
	{
		rayy.x += dx;
		rayy.y += dy;
		map_x = rayy.x / CELL_SIZE;
		map_y = rayy.y / CELL_SIZE;
	}
	dx = rayy.x - start.x;
	dy = rayy.y - start.y;
	rayy.len = sqrt(dx * dx + dy * dy) * cos(to_rad(pov - dir));
	return (rayy);
}

t_ray			*raycast(float pov, t_position start, t_vector_point *map)
{
	t_ray	*rays;
	t_ray	rayx;
	t_ray	rayy;
	float	dir;
	int		x;

	dir = pov + HERO_FOV_DEFAULT / 2;
	dir = (int)dir % 360;
	rays = malloc(sizeof(t_ray) * WND_WIDTH);
	ft_memset(rays, 0, sizeof(t_ray) * WND_WIDTH);
	x = -1;
	while (++x < WND_WIDTH)
	{
		rayx.len = INFINITY;
		if (!(dir == 0 || dir == 180))
			rayx = raycast_x(start, map, dir, pov);
		rayy.len = INFINITY;
		if (!(dir == 90 || dir == 270))
			rayy = raycast_y(start, map, dir, pov);
		rays[x] = rayx.len < rayy.len ? rayx : rayy;
		rays[x].side = rayx.len < rayy.len ? X_SIDE : Y_SIDE;
		dir -= HERO_FOV_DEFAULT / (float)WND_WIDTH;
		dir += dir < 0 ? 360 : 0;
	}
	return (rays);
}
