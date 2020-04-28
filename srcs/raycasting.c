/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: konsolka <konsolka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/27 21:25:37 by user              #+#    #+#             */
/*   Updated: 2020/04/28 17:00:17 by konsolka         ###   ########.fr       */
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
	ray->wall_c = map[y][x].wall_c;
	begin_x -= ray->x;
	begin_y -= ray->y;
	ray->len = sqrt(begin_x * begin_x + begin_y * begin_y);
}

/*
	d *= cos(a)
	into ray_cast
*/
int			addToAngle(int angle, int add)
{
	if (angle <= -360)
		angle += (int)(-angle / 360) * 360;
	else if(angle >= 360)
		angle -= (int)(angle / 360) * 360;
	if (add != 0)
	{
		if (add > 0 && angle < 0)
		{
			angle -= add;
			if (angle <= -360)
			{
				angle += (int)(-angle / 360) * 360;
				angle *= -1;
			}
		}
		else
		{
			angle += add;
			if (angle >= 360)
				angle -= (int)(-angle / 360) * 360;
		}
	}
	return (angle);
	
}

/*
** returns allocated array of rays. You need to free this array
*/
t_ray	*raycast(float pov, float fov, int max_len,
				const t_map *map)
{
	const int	rays_count = fov;
	const float	pov_increase = fov / rays_count;
	int			ray_number;
	t_ray		*rays;

	pov -= fov / 2;
	rays = malloc(sizeof(t_ray) * rays_count);
	ray_number = 0;
	while (ray_number < rays_count)
	{
		rays[ray_number].pov = pov;
		rays[ray_number].angle = addToAngle(-rays_count / 2, ray_number);
		rays[ray_number].x = map->hero.position.x;
		rays[ray_number].y = map->hero.position.y;
		cast_ray(rays + ray_number, map->map);
		ray_number += 1;
		pov += pov_increase;
	}
	return (rays);

	(void)max_len;
}
