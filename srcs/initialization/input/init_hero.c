/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_hero.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburl <mburl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/25 18:00:42 by user              #+#    #+#             */
/*   Updated: 2020/08/04 07:58:20 by mburl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "woofdefines.h"
#include "hero.h"
#include "input_utils.h"
#include "map.h"
#include "data.h"

t_hero	init_hero(t_point hero_position)
{
	t_hero	hero;

	hero.position.x = hero_position.x * CELL_SIZE + CELL_SIZE / 2;
	hero.position.y = hero_position.y * CELL_SIZE + CELL_SIZE / 2;
	hero.fov = HERO_FOV_DEFAULT;
	hero.speed = CELL_SIZE * 0.15;
	hero.pov = 90;
	return (hero);
}
