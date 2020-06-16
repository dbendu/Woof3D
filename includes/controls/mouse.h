/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: konsolka <konsolka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/16 15:46:30 by konsolka          #+#    #+#             */
/*   Updated: 2020/06/16 16:30:56 by konsolka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOUSE_H
# define MOUSE_H

# include <SDL2/SDL.h>
# include "data.h"

typedef struct	s_mouse
{
	SDL_Rect	cursor;
	SDL_Rect	tip;
	SDL_Texture	*texture;
}				t_mouse;

int			update_mouse(t_mouse *mouse);
t_mouse		mouseInit(SDL_Renderer *render);
void		drawMouse(SDL_Renderer *render, t_mouse mouse);

#endif