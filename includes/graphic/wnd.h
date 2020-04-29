/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wnd.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/26 11:28:57 by user              #+#    #+#             */
/*   Updated: 2020/04/30 00:08:49 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WND_H
# define WND_H

# include <SDL2/SDL.h>

typedef struct		s_wnd
{
	SDL_Window		*window;
	SDL_Renderer	*renderer;
	SDL_Surface		*main_canvas;
}					t_wnd;


#endif
