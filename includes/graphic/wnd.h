/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wnd.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburl <mburl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/26 11:28:57 by user              #+#    #+#             */
/*   Updated: 2020/08/04 07:47:51 by mburl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WND_H
# define WND_H

# include <SDL2/SDL.h>

typedef struct		s_texture
{
	SDL_Surface		*texture;
	uint32_t		*pixels;
	int				w;
	int				h;
}					t_texture;

typedef struct		s_wnd
{
	SDL_Window		*window;
	SDL_Renderer	*renderer;
	SDL_Surface		*main_canvas;
	t_texture		*textures;
}					t_wnd;

#endif
