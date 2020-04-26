/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_hero.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/25 18:00:42 by user              #+#    #+#             */
/*   Updated: 2020/04/27 02:13:09 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Woof_defines.h"
#include "input_utils.h"

t_hero	init_hero(t_point hero_position)
{
	t_hero	hero;

	hero.ammo = NULL;
	hero.hp = 100;
	hero.lives = 3;
	hero.relative_position.x = hero_position.x;
	hero.relative_position.y = hero_position.y;
	hero.absolute_position.x = hero_position.x * CELL_SIZE + CELL_SIZE / 2;
	hero.absolute_position.y = hero_position.y * CELL_SIZE + CELL_SIZE / 2;
	hero.fov = FOV;
	hero.pov = 0;	// in degrees: [0; 360). Zero means hero looks to the east,
	return (hero);	// 90 -- to the north...
}
