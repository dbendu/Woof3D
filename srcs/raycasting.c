/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburl <mburl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/27 21:25:37 by user              #+#    #+#             */
/*   Updated: 2020/08/04 07:58:19 by mburl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"
#include "ray.h"
#include "woof3d.h"
#include "woofdefines.h"


t_ray	*raycast(int fov, float pov, t_position start, t_vector_point *map)
{
	t_ray *rays = malloc(sizeof(t_ray) * WND_WIDTH);
	ft_memset(rays, 0, sizeof(t_ray) * WND_WIDTH);
	t_ray rayx = {0};
	t_ray rayy = {0};
	float	dir = pov + fov / 2;
	if (dir >= 360) {
		dir -= 360;
	}
	float	diff = fov / (float)WND_WIDTH;
	float	dx;
	float	dy;
	int		map_x;
	int		map_y;

	for (int x = 0; x < WND_WIDTH; ++x) {
		// horizontal
		if (dir == 0 || dir == 180) {
			rayx.len = INFINITY;
		} else {
			if (dir > 180) {
				rayx.y = (int)start.y / CELL_SIZE * CELL_SIZE + CELL_SIZE;
				dy = CELL_SIZE;
			} else {
				rayx.y = (int)start.y / CELL_SIZE * CELL_SIZE - 0.001;
				dy = -CELL_SIZE;
			}
			rayx.x = start.x + (start.y - rayx.y) / tan(to_rad(dir));
			dx = -dy / tan(to_rad(dir));

			map_x = rayx.x / CELL_SIZE;
			map_y = rayx.y / CELL_SIZE;

			while (map_x >= 0 && map_y >= 0 && map_x < vec_size(&map[0]) && map_y < vec_size(&map) && map[map_y][map_x].wall == false) {
				rayx.x += dx;
				rayx.y += dy;
				map_x = rayx.x / CELL_SIZE;
				map_y = rayx.y / CELL_SIZE;
			}
			dx = rayx.x - start.x;
			dy = rayx.y - start.y;
			rayx.len = sqrt(dx * dx + dy * dy) * cos(to_rad(pov - dir));
		}

		// vertical
		if (dir == 90 || dir == 270) {
			rayy.len = INFINITY;
		} else {
			if (dir > 270 || dir < 90) {
				rayy.x = (int)start.x / CELL_SIZE * CELL_SIZE + CELL_SIZE;
				dx = CELL_SIZE;
			} else {
				rayy.x = (int)start.x / CELL_SIZE * CELL_SIZE - 0.001;
				dx = -CELL_SIZE;
			}
			rayy.y = start.y + (start.x - rayy.x) * tan(to_rad(dir));
			dy = -dx * tan(to_rad(dir));

			map_x = rayy.x / CELL_SIZE;
			map_y = rayy.y / CELL_SIZE;

			while (map_x >= 0 && map_y >= 0 && map_x < vec_size(&map[0]) && map_y < vec_size(&map) && map[map_y][map_x].wall == false) {
				rayy.x += dx;
				rayy.y += dy;
				map_x = rayy.x / CELL_SIZE;
				map_y = rayy.y / CELL_SIZE;
			}
			dx = rayy.x - start.x;
			dy = rayy.y - start.y;
			rayy.len = sqrt(dx * dx + dy * dy) * cos(to_rad(pov - dir));
		}

		if (rayx.len < rayy.len) {
			rays[x] = rayx;
			rays[x].side = X_SIDE;
		} else {
			rays[x] = rayy;
			rays[x].side = Y_SIDE;
		}
		dir -= diff;
		if (dir < 0) {
			dir += 360;
		}
	}
	return (rays);
}
