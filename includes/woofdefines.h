/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   woofdefines.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburl <mburl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 07:57:07 by mburl             #+#    #+#             */
/*   Updated: 2020/08/04 08:18:48 by mburl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOOFDEFINES_H
# define WOOFDEFINES_H

/*
** window
*/
# define WND_WIDTH			1480
# define WND_HEIGHT			720
# define WND_MIN_WIDTH		320
# define WND_MIN_HEIGHT		240
# define WND_TITLE			"Woof3D"

/*
** game
*/
# define CELL_SIZE			62
# define MINIMAP_SZ			300
# define TEXTURES_COUNT		5

/*
** hero
*/
# define HERO_ROTATE        1

/*
** field of view, in degrees
*/
# define HERO_FOV_DEFAULT	60
# define HERO_FOV_MAX		170
# define HERO_FOV_MIN		30
# define HERO_STEP_SPEED	CELL_SIZE * 0.025
# define HERO_RUN_SPEED		1.6

/*
** only integer, not fractional for bouth
*/
# define RAYS_BY_ANGLE		5
# define MAX_RAY_MULTIPLYER	6

#endif
