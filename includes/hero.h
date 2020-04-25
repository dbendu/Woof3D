/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hero.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/25 17:29:15 by user              #+#    #+#             */
/*   Updated: 2020/04/25 18:03:31 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HERO_H
# define HERO_H

# include "point.h"

typedef struct		s_hero
{
	t_point			position;
	unsigned		hp;
	unsigned short	lives;
	void			*ammo;
	float			pov;
}					t_hero;

#endif
