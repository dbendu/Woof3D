/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/27 21:25:37 by user              #+#    #+#             */
/*   Updated: 2020/04/30 00:41:27 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"
#include "ray.h"
#include "Woof3D.h"
#include "WoofDefines.h"


t_ray castx(float pov, t_position start_position, t_vector_point *map)
{
	t_ray	ray;

	float start_y = (int)start_position.y / CELL_SIZE * CELL_SIZE;
	if (pov >= 180)
		start_y += CELL_SIZE;
	else
		start_y -= 1;
	float start_x = (int)start_position.x + ((int)start_position.y - (int)start_y) / tan(to_rad(pov));

	float dy = pov <= 180 ? -CELL_SIZE : CELL_SIZE;
	float dx = -dy / tan(to_rad(pov));


	int x = start_x / CELL_SIZE;
	int y = start_y / CELL_SIZE;

	while (x >= 0 && y >= 0 && x < vec_size(&map[0]) && y < vec_size(&map) &&
			map[y][x].wall == false)
	{
		start_x += dx;
		start_y += dy;
		x = start_x / CELL_SIZE;
		y = start_y / CELL_SIZE;
	}
	ray.x = start_x;
	ray.y = start_y;

	return (ray);
}

t_ray casty(float pov, t_position start_position, t_vector_point *map)
{
	t_ray	ray;

	float start_x = (int)start_position.x / CELL_SIZE * CELL_SIZE;
	if (pov <= 90 || pov >= 270)
		start_x += CELL_SIZE;
	else
		start_x -= 1;
	float start_y = (int)start_position.y + ((int)start_position.x - (int)start_x) * tan(to_rad(pov));

	float dx = (pov <= 90 || pov >= 270) ? CELL_SIZE : -CELL_SIZE;
	float dy = -dx * tan(to_rad(pov));

	int x = start_x / CELL_SIZE;
	int y = start_y / CELL_SIZE;

	while (x >= 0 && y >= 0 && x < vec_size(&map[0]) && y < vec_size(&map) &&
			map[y][x].wall == false)
	{
		start_x += dx;
		start_y += dy;
		x = start_x / CELL_SIZE;
		y = start_y / CELL_SIZE;
	}
	ray.x = start_x;
	ray.y = start_y;

	return (ray);
}


t_ray	*raycast(float pov,
				t_map *map)
{
	const int rays_count = WND_WIDTH;
	const float	pov_decrease = map->hero.fov / rays_count;
	int			ray_number;
	t_ray		*rays;

	pov += map->hero.fov / 2;
	if (pov > 360)
		pov -= 360;
	rays = malloc(sizeof(t_ray) * rays_count);
	ray_number = 0;
	while (ray_number < rays_count)
	{
		t_ray rayx = castx(pov, map->hero.position, map->map);
		t_ray rayy = casty(pov, map->hero.position, map->map);


		t_position pos = map->hero.position;
		float lenx = sqrt((rayx.x - pos.x) * (rayx.x - pos.x) + (rayx.y - pos.y) * (rayx.y - pos.y)) * cos(to_rad(ray_number * map->hero.fov / rays_count - map->hero.fov / 2));
		float leny = sqrt((rayy.x - pos.x) * (rayy.x - pos.x) + (rayy.y - pos.y) * (rayy.y - pos.y)) * cos(to_rad(ray_number * map->hero.fov / rays_count - map->hero.fov / 2));

		rayx.len = lenx;
		rayy.len = leny;
		if (lenx < leny)
			rays[ray_number] = rayx;
		else
			rays[ray_number] = rayy;

		ray_number += 1;
		pov -= pov_decrease;
		if (pov < 0)
			pov += 360;
	}
	return (rays);
}
