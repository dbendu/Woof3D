/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hero.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/25 17:29:15 by user              #+#    #+#             */
/*   Updated: 2020/04/29 23:10:40 by user             ###   ########.fr       */
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
