/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_hero.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/25 18:00:42 by user              #+#    #+#             */
/*   Updated: 2020/04/27 23:20:31 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Woof_defines.h"
#include "hero.h"
#include "input_utils.h"
#include "map.h"
#include "data.h"

t_hero	init_hero(t_point hero_position)
{
	t_hero	hero;

	hero.ammo = NULL;
	hero.hp = 100;
	hero.lives = 3;
	hero.position.x = hero_position.x * CELL_SIZE + CELL_SIZE / 2;
	hero.position.y = hero_position.y * CELL_SIZE + CELL_SIZE / 2;
	hero.fov = FOV_DEFAULT;
	hero.speed = HERO_STEP_SPEED;
	// hero.rect.x = hero_position.x * CELL_SIZE;
	// hero.rect.y = hero_position.y * CELL_SIZE;
	// hero.rect.w = CELL_SIZE - 5;
	// hero.rect.h = CELL_SIZE - 5;
	hero.pov = 0;	// in degrees: [0; 360). Zero means hero looks to the east,
	return (hero);	// 90 -- to the north...
}
