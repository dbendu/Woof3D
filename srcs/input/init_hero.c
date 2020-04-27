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
	hero.relative_position.x = hero_position.x;
	hero.relative_position.y = hero_position.y;
	hero.absolute_position.x = hero_position.x * CELL_SIZE + CELL_SIZE / 2;
	hero.absolute_position.y = hero_position.y * CELL_SIZE + CELL_SIZE / 2;
	hero.fov = FOV;
	hero.speed = 2;
	hero.rect.x = hero_position.x * CELL_SIZE;
	hero.rect.y = hero_position.y * CELL_SIZE;
	hero.rect.w = CELL_SIZE - 5;
	hero.rect.h = CELL_SIZE - 5;
	hero.pov = 0;	// in degrees: [0; 360). Zero means hero looks to the east,
	return (hero);	// 90 -- to the north...
}

void		updatePosition(t_hero *hero, bool forward)
{
	int		a;

	a = 1;
	if (!forward)
		a = -1;
	hero->absolute_position.x += cos(hero->pov * 3.14 / 180) * hero->speed * a;
	hero->absolute_position.y += sin(hero->pov * 3.14 / 180) * hero->speed * a;
	hero->relative_position.x += hero->absolute_position.x / CELL_SIZE;
	hero->relative_position.y += hero->absolute_position.y / CELL_SIZE;
}

void		playerUpdate(t_data *data, t_hero *hero)
{
	if (data->keyboard.key[1])
		updatePosition(hero, 1);
	else if (data->keyboard.key[3])
		updatePosition(hero, 0);
	if (data->keyboard.key[2])
		hero->pov += 1;
	else if (data->keyboard.key[0])
		hero->pov -= 1;
}