/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wnd_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburl <mburl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 23:36:21 by user              #+#    #+#             */
/*   Updated: 2020/08/04 15:59:24 by mburl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "initialization/init_all.h"
#include "woofdefines.h"

uint32_t	*convert(SDL_Surface *srf)
{
	uint32_t	*src_pixels;
	uint32_t	*dst_pixels;
	int			y;
	int			x;

	src_pixels = srf->pixels;
	dst_pixels = malloc(srf->pitch * srf->h);
	y = 0;
	while (y < srf->w)
	{
		x = 0;
		while (x < srf->h)
		{
			dst_pixels[y * srf->w + x] = src_pixels[x * srf->w + y];
			x++;
		}
		y++;
	}
	return (dst_pixels);
}

t_texture	*load_textures(SDL_Window *wnd)
{
	t_texture	*textures;
	SDL_Surface	*srf;
	int			i;
	const char	texs[TEXTURES_COUNT][43] = {
		"/home/user/Woof3D/res/textures/Earth.bmp",
		"/home/user/Woof3D/res/textures/Grey.bmp",
		"/home/user/Woof3D/res/textures/Stone.bmp",
		"/home/user/Woof3D/res/textures/Window.bmp",
		"/home/user/Woof3D/res/textures/Adolf.bmp"
	};

	textures = malloc(sizeof(t_texture) * TEXTURES_COUNT);
	srf = NULL;
	i = -1;
	while (++i < TEXTURES_COUNT)
	{
		srf = SDL_LoadBMP(texs[i]);
		textures[i].texture = SDL_ConvertSurfaceFormat(srf,
							SDL_GetWindowPixelFormat(wnd), 0);
		textures[i].pixels = textures[i].texture->pixels;
		textures[i].w = textures[i].texture->w;
		textures[i].h = textures[i].texture->h;
		SDL_FreeSurface(srf);
	}
	return (textures);
}

t_wnd		wnd_init()
{
	t_wnd	wnd;

	wnd.window = SDL_CreateWindow(WND_TITLE,
					SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
					WND_WIDTH, WND_HEIGHT, 0);
	wnd.main_canvas = SDL_GetWindowSurface(wnd.window);
	wnd.renderer = SDL_CreateSoftwareRenderer(wnd.main_canvas);
	wnd.textures = load_textures(wnd.window);
	return (wnd);
}
