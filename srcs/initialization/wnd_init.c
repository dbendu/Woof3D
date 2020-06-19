/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wnd_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 23:36:21 by user              #+#    #+#             */
/*   Updated: 2020/06/19 16:02:17 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_all.h"


static void	check_args(const char *title, int width, int height)
{
	if (!title || *title == '\0')
		ft_error(SDL_GetError(), "woof_init/wnd_init", 0);
	if (width < WND_MIN_WIDTH || height < WND_MIN_HEIGHT)
		ft_error("too small window", "woof_init/wnd_init", 0);
}

uint32_t *convert(SDL_Surface *srf)
{
	uint32_t *src_pixels = srf->pixels;
	printf("%d\n", srf->pitch * srf->h);
	uint32_t *dst_pixels = malloc(srf->pitch * srf->h);
	for (int y = 0; y < srf->w; ++y) {
		for (int x = 0; x < srf->h; ++x) {
			dst_pixels[y * srf->w + x] = src_pixels[x * srf->w + y];
		}
	}
	return (dst_pixels);
}

#define count 5

t_texture	*load_textures(SDL_Window *wnd)
{
	t_texture	*textures = malloc(sizeof(t_texture) * count);
	SDL_Surface	*srf = NULL;
	const char texs[count][40] = {
		"Earth.bmp",
		"Grey.bmp",
		"Stone.bmp",
		"Window.bmp",
		"Adolf.bmp"
	};

	for (int i = 0; i < count; ++i) {
		srf = SDL_LoadBMP(texs[i]);
		textures[i].texture = SDL_ConvertSurfaceFormat(srf, SDL_GetWindowPixelFormat(wnd), 0);
		textures[i].pixels = textures[i].texture->pixels;
		textures[i].w = textures[i].texture->w;
		textures[i].h = textures[i].texture->h;
		SDL_FreeSurface(srf);
	}
	return (textures);
}

t_wnd		wnd_init(const char *title, int width, int height)
{
	t_wnd	wnd;

	check_args(title, width, height);
	wnd.window = SDL_CreateWindow("Woof", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, 0);
	wnd.main_canvas = SDL_GetWindowSurface(wnd.window);
	wnd.renderer = SDL_CreateSoftwareRenderer(wnd.main_canvas);
	wnd.textures = load_textures(wnd.window);
	SDL_SetWindowTitle(wnd.window, title);
	return (wnd);
}
