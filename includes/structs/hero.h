/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hero.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburl <mburl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/25 17:29:15 by user              #+#    #+#             */
/*   Updated: 2020/11/02 19:46:44 by mburl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HERO_H
# define HERO_H

typedef struct		s_position
{
	float			x;
	float			y;
}					t_position;

typedef struct		s_hero
{
	t_position		position;
	float			speed;
	float			pov;
	float			fov;
}					t_hero;

#endif
