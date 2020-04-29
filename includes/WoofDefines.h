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
# define WND_WIDTH			1000
# define WND_HEIGHT			1000
# define WND_MIN_WIDTH		320
# define WND_MIN_HEIGHT		240
# define WND_TITLE			"Woof3D"

/*
** game
*/
# define CELL_SIZE			32
# define MINIMAP_SZ			150

/*
** hero
*/
# define HERO_FOV_DEFAULT	66			// field of view, in degrees
# define HERO_FOV_MAX		170
# define HERO_FOV_MIN		30
# define HERO_STEP_SPEED	0.8
# define HERO_RUN_SPEED		1.6

# define RAYS_BY_ANGLE		5	// only integer, not fractional!
# define MAX_RAY_MULTIPLYER	6	// same


#endif
