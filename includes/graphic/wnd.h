/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wnd.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/26 11:28:57 by user              #+#    #+#             */
/*   Updated: 2020/04/26 13:35:11 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WND_H
# define WND_H

# include <SDL2/SDL.h>
# include "minimap.h"
# include "interface.h"

typedef struct		s_sdl
{
	SDL_Window		*window;
	SDL_Renderer	*renderer;
}					t_sdl;

typedef struct		s_wnd
{
	t_sdl			sdl;
	SDL_Surface		*main_canvas;
	t_interface		interface;
	t_minimap		minimap;
}					t_wnd;

t_wnd				wnd_init(void);

void				wnd_destroy(t_wnd *wnd);

#endif
