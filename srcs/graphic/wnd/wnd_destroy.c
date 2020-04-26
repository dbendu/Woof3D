/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wnd_destroy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/26 12:05:35 by user              #+#    #+#             */
/*   Updated: 2020/04/26 13:19:01 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wnd.h"

static void	minimap_destroy(t_minimap *minimap)
{
	SDL_FreeSurface(minimap->surface);
}

void		wnd_destroy(t_wnd *wnd)
{
	if (wnd->interface.exist)
		interface_destroy(&wnd->interface);
	minimap_destroy(&wnd->minimap);
	SDL_FreeSurface(wnd->main_canvas);
	SDL_DestroyRenderer(wnd->sdl.renderer);
	SDL_DestroyWindow(wnd->sdl.window);
	SDL_Quit();
}
