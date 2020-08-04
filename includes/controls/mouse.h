/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburl <mburl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/16 15:46:30 by konsolka          #+#    #+#             */
/*   Updated: 2020/08/04 16:01:34 by mburl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOUSE_H
# define MOUSE_H

# include <SDL2/SDL.h>
# include "structs/data.h"

typedef struct	s_mouse
{
	SDL_Rect	cursor;
	SDL_Rect	tip;
	SDL_Texture	*texture;
}				t_mouse;

int				update_mouse(t_mouse *mouse);
t_mouse			mouse_init(SDL_Renderer *render);
void			draw_mouse(SDL_Renderer *render, t_mouse mouse);

#endif
