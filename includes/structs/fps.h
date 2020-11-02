/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fps.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburl <mburl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 14:37:33 by mburl             #+#    #+#             */
/*   Updated: 2020/11/02 16:03:14 by mburl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FPS_H
# define FPS_H

# include <SDL2/SDL.h>
# include "libft.h"
# define FRAME_VALUES 10

typedef struct	s_fps
{
	Uint32	frametimes[FRAME_VALUES];
	Uint32	frametimelast;
	Uint32	framecount;
	float	framespersecond;
}				t_fps;

void			fps_think(t_fps *fps);
void			fps_init(t_fps *fps);

#endif
