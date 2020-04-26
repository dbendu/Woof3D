/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wnd_destroy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/26 12:05:35 by user              #+#    #+#             */
/*   Updated: 2020/04/26 22:10:36 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wnd.h"

void		wnd_destroy(t_wnd *wnd)
{
	SDL_FreeSurface(wnd->interface.surface);
	SDL_FreeSurface(wnd->minimap.surface);
	SDL_FreeSurface(wnd->main_canvas);
	SDL_DestroyRenderer(wnd->sdl.renderer);
	SDL_DestroyWindow(wnd->sdl.window);
	SDL_Quit();
}
