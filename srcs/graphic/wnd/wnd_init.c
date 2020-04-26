/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wnd_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/26 10:46:13 by user              #+#    #+#             */
/*   Updated: 2020/04/26 13:18:06 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wnd.h"
#include "Woof_defines.h"
#include "libft.h"
#include "graphic_utils.h"

static t_minimap	minimap_create(void)
{
	t_minimap	minimap;

	minimap.show = true;
	minimap.surface = sdl_create_surface(MINIMAP_SZ, MINIMAP_SZ);
	minimap.viewport.y = 0;
	minimap.viewport.x = WIDTH - MINIMAP_SZ;
	minimap.viewport.w = MINIMAP_SZ;
	minimap.viewport.h = MINIMAP_SZ;
	return (minimap);
}

t_wnd				wnd_init(void)
{
	t_wnd	wnd;
	int		ret;

	if (SDL_Init(SDL_INIT_VIDEO) < 0)
		ft_error(SDL_GetError(), "wnd_init", 0);
	ret = SDL_CreateWindowAndRenderer(WIDTH, HEIGHT, 0, &wnd.sdl.window,
														&wnd.sdl.renderer);
	if (ret < 0)
		ft_error(SDL_GetError(), "wnd_init", 0);
	SDL_SetWindowTitle(wnd.sdl.window, TITLE);
	wnd.main_canvas = sdl_create_surface(WIDTH, HEIGHT);
	wnd.minimap = minimap_create();
	wnd.minimap.show = true;
	wnd.interface.exist = false;
	return (wnd);
}
