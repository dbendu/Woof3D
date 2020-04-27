/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Woof_defines.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/25 18:23:48 by user              #+#    #+#             */
/*   Updated: 2020/04/27 23:40:34 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOOF_DEFINES_H
# define WOOF_DEFINES_H

# define WIDTH			1000
# define HEIGHT			1000
# define MINIMAP_SZ		500
# define TITLE			"Woof3D"	// window title
# define CELL_SIZE		32
// # define PLAYER_CELL_SIZE	CELL_SIZE - 5
# define MINIMAP_CELL	32
# define FOV_DEFAULT	60			// field of view, in degrees
# define FOV_MAX		170
# define FOV_MIN		30

# define POV_DISTANCE	20	// max distance of ray
# define RAYS_BY_ANGLE	5	// only integer, not fractional!

# define HERO_STEP_SPEED	0.3
# define HERO_RUN_SPEED		0.6

#endif
