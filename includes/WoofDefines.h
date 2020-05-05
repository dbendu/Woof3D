/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WoofDefines.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/25 18:23:48 by user              #+#    #+#             */
/*   Updated: 2020/04/29 23:09:32 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WoofDefines_H
# define WoofDefines_H

/*
** window
*/
# define WND_WIDTH			1480
# define WND_HEIGHT			720
# define WND_MIN_WIDTH		320
# define WND_MIN_HEIGHT		240
# define WND_TITLE			"Woof3D"


# if SDL_BYTEORDER == SDL_BIG_ENDIAN
#  define RMASK	0xff000000
#  define GMASK	0x00ff0000
#  define BMASK	0x0000ff00
#  define AMASK	0x000000ff
# else
#  define RMASK	0x000000ff
#  define GMASK	0x0000ff00
#  define BMASK	0x00ff0000
#  define AMASK	0xff000000
# endif

/*
** game
*/
# define CELL_SIZE			64
# define MINIMAP_SZ			300
/*
** hero
*/
# define HERO_ROTATE        1
# define HERO_FOV_DEFAULT	66			// field of view, in degrees
# define HERO_FOV_MAX		170
# define HERO_FOV_MIN		30
# define HERO_STEP_SPEED	CELL_SIZE * 0.025
# define HERO_RUN_SPEED		1.6

# define RAYS_BY_ANGLE		5	// only integer, not fractional!
# define MAX_RAY_MULTIPLYER	6	// same

# define START_BUTTON		0
# define EXIT_BUTTON		1
#endif
