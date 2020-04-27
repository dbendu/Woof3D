/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/27 21:25:37 by user              #+#    #+#             */
/*   Updated: 2020/04/27 22:53:38 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Woof3D.h"
#include "Woof_defines.h"
#include "ray.h"

/*
** fills ray fields .lenght, .x, .y
*/
void	cast_ray(t_ray *ray, const t_vector_point *map)
{
	int		y;
	int		x;
	float	begin_x;
	float	begin_y;

	begin_x = ray->x;
	begin_y = ray->y;
	y = ray->y / CELL_SIZE;
	x = ray->x / CELL_SIZE;
	while (!map[y][x].wall) {
		ray->x += cos(ray->pov * 3.14 / 180) * 0.5;
		ray->y += sin(ray->pov * 3.14 / 180) * 0.5;
		y = ray->y / CELL_SIZE;
		x = ray->x / CELL_SIZE;
	}
	begin_x -= ray->x;
	begin_y -= ray->y;
	ray->len = sqrt(begin_x * begin_x + begin_y * begin_y);
}

/*
** returns allocated array of rays. You need to free this array
*/
t_ray	*raycast(float pov, float fov, int max_len,
				const t_map *map)
{
	const int	rays_count = fov * RAYS_BY_ANGLE;
	const float	pov_increase = fov / rays_count;
	int			ray_number;
	t_ray		*rays;

	pov -= fov / 2;
	rays = malloc(sizeof(t_ray) * rays_count);
	ray_number = 0;
	while (ray_number < rays_count)
	{
		rays[ray_number].pov = pov;
		rays[ray_number].x = map->hero.position.x;
		rays[ray_number].y = map->hero.position.y;
		cast_ray(rays + ray_number, map->map);
		ray_number += 1;
		pov += pov_increase;
	}
	return (rays);

	(void)max_len;
}
