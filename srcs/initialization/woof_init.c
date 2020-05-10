/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   woof_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: konsolka <konsolka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 23:33:46 by user              #+#    #+#             */
/*   Updated: 2020/05/10 12:22:36 by konsolka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include "libft.h"
#include "WoofDefines.h"
#include "data.h"
#include "point.h"
#include "Woof3D.h"

static void	sdl_init(void)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
		ft_error(SDL_GetError(), "woof_init", 0);
}

t_data	woof_init()
{
	t_data	data;

	sdl_init();
	if (TTF_Init() < 0)
		ft_error(TTF_GetError(), "TTF_Init()", 0);
	data.keyboard = keyboard_init();
	data.wnd = wnd_init(WND_TITLE, WND_WIDTH, WND_HEIGHT);
	data.minimap = minimap_init(data);
	SDL_ShowCursor(0);
	data.quit = false;
	data.gameState = Menu_button;
	data.map.map = NULL;
	data.menu.button = startButtonsInit(data,
		4,
		buttonInitData(
			setRect(WND_WIDTH / 2 - 100, WND_HEIGHT / 5, 200, 100),
			xyInit(1, 1),
			0),
			"Continue", "Start", "Options", "Exit");
	data.texture = IMG_LoadTexture(data.wnd.renderer, "res/textures/wolftextures.png");
	data.options = initOptions(data);
	data.menu.mouse = mouseInit(data, "res/textures/cursor.png", 50, 50);
	data.maps = NULL;
	return (data);
}
