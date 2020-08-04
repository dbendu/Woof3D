/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_update.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburl <mburl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/27 20:59:56 by user              #+#    #+#             */
/*   Updated: 2020/08/04 11:16:17 by mburl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "woof3d.h"
#include "woofdefines.h"

static void			move_hero_if_possible(t_vector_point *map, t_hero *hero,
										float estimated_x, float estimated_y)
{
	const int	new_x = estimated_x / CELL_SIZE;
	const int	new_y = estimated_y / CELL_SIZE;
	const int	old_x = hero->position.x / CELL_SIZE;
	const int	old_y = hero->position.y / CELL_SIZE;

	if (map[new_y][old_x].wall == false)
		hero->position.y = estimated_y;
	if (map[old_y][new_x].wall == false)
		hero->position.x = estimated_x;
}

static void			update_player_position(t_map *map, bool forward)
{
	float		moving_vector;
	float		new_x;
	float		new_y;

	moving_vector = map->hero.speed * (forward ? 1 : -1);
	new_x = map->hero.position.x +
		cos(to_rad(map->hero.pov)) * moving_vector;
	new_y = map->hero.position.y -
		sin(to_rad(map->hero.pov)) * moving_vector;
	move_hero_if_possible(map->map, &map->hero, new_x, new_y);
}

/*
** xor returns true only if hero moving only in one direction at the moment
** its okay if execute both conditions cause here no overhead calculations
** like in update_position
*/

void				player_update(t_data *data, t_hero *hero)
{
	if (data->keyboard.key[MOVE_FORWARD] ^ data->keyboard.key[MOVE_BACK])
		update_player_position(&data->map, data->keyboard.key[MOVE_FORWARD]);
	if (data->keyboard.key[TURN_RIGHT])
		hero->pov -= HERO_ROTATE;
	if (data->keyboard.key[TURN_LEFT])
		hero->pov += HERO_ROTATE;
	if (data->keyboard.key[FOV_INCREASE] && data->map.hero.fov < HERO_FOV_MAX)
		data->map.hero.fov += 1;
	if (data->keyboard.key[FOV_DECREASE] && data->map.hero.fov > HERO_FOV_MIN)
		data->map.hero.fov -= 1;
	if (hero->pov >= 360)
		hero->pov = 0;
	else if (hero->pov < 0)
		hero->pov += 360;
}
