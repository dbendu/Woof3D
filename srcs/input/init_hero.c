/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_hero.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/25 18:00:42 by user              #+#    #+#             */
/*   Updated: 2020/04/25 18:03:46 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input_utils.h"

t_hero	init_hero(t_point hero_position)
{
	t_hero	hero;

	hero.ammo = NULL;
	hero.hp = 100;
	hero.lives = 3;
	hero.position = hero_position;
	hero.pov = 0;		// in degrees: [0; 360). Zero means hero looks to the east,
	return (hero);		// 90 -- to the north...
}
