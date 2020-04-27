/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hero.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/25 17:29:15 by user              #+#    #+#             */
/*   Updated: 2020/04/27 02:12:54 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HERO_H
# define HERO_H

# include <SDL2/SDL.h>
# include "point.h"

typedef struct		s_position
{
	float			x;
	float			y;
}					t_position;

typedef struct		s_hero
{
	t_point			relative_position;
	t_position		absolute_position;
	unsigned		hp;
	unsigned short	lives;
	int				speed;
	void			*ammo;
	float			pov;
	float			fov;
	SDL_Rect		rect;
}					t_hero;

#endif
