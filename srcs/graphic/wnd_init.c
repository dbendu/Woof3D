/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wnd_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/26 10:46:13 by user              #+#    #+#             */
/*   Updated: 2020/04/27 22:43:25 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wnd.h"
#include "Woof_defines.h"
#include "libft.h"

#if SDL_BYTEORDER == SDL_BIG_ENDIAN
# define RMASK	0xff000000
# define GMASK	0x00ff0000
# define BMASK	0x0000ff00
# define AMASK	0x000000ff
#else
# define RMASK	0x000000ff
# define GMASK	0x0000ff00
# define BMASK	0x00ff0000
# define AMASK	0xff000000
#endif

static SDL_Surface	*sdl_create_surface(int width, int height)
{
	SDL_Surface	*surface;

	surface = SDL_CreateRGBSurface(0, width, height, 32,
							RMASK, GMASK, BMASK, AMASK);
	if (surface == NULL)
		ft_error(SDL_GetError(), "sdl_create_surface", 0);
	return (surface);
}


static t_interface	interface_create(void)
{
	t_interface	interface;

	interface.surface = sdl_create_surface(WIDTH, 150);
	interface.show = false;
	interface.viewport.x = 0;
	interface.viewport.y = HEIGHT - 150;
	interface.viewport.w = WIDTH;
	interface.viewport.h = 150;
	return (interface);
}

static t_minimap	minimap_create(void)
{
	t_minimap	minimap;

	minimap.show = false;
	minimap.surface = sdl_create_surface(MINIMAP_SZ, MINIMAP_SZ);
	minimap.viewport.y = 0;
	minimap.viewport.x = WIDTH - MINIMAP_SZ;
	minimap.viewport.w = MINIMAP_SZ;
	minimap.viewport.h = MINIMAP_SZ;
	return (minimap);
}

static void			sdl_init(t_wnd *wnd)
{
	int ret;

	if (SDL_Init(SDL_INIT_VIDEO) < 0)
		ft_error(SDL_GetError(), "wnd_init", 0);
	ret = SDL_CreateWindowAndRenderer(WIDTH, HEIGHT, 0, &wnd->sdl.window,
														&wnd->sdl.renderer);
	if (ret < 0)
		ft_error(SDL_GetError(), "wnd_init", 0);
	SDL_SetWindowTitle(wnd->sdl.window, TITLE);
	// SDL_SetRelativeMouseMode(SDL_ENABLE);
}

t_wnd				wnd_init(void)
{
	t_wnd	wnd;

	sdl_init(&wnd);
	wnd.main_canvas = sdl_create_surface(WIDTH, HEIGHT);
	wnd.minimap = minimap_create();
	wnd.interface = interface_create();
	return (wnd);
}
