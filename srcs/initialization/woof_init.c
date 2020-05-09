/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   woof_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: konsolka <konsolka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 23:33:46 by user              #+#    #+#             */
/*   Updated: 2020/05/09 06:24:40 by konsolka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include "initialization.h"
#include "WoofDefines.h"
#include "init_all.h"
#include "libft.h"
#include "button.h"
#include "main_menu.h"
#include "Woof3D.h"
#include "data.h"

static void	sdl_init(void)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
		ft_error(SDL_GetError(), "woof_init", 0);
}

t_data	woof_init(const char *filename)
{
	t_data	data;
	t_point_xy xy;

	sdl_init();
	if (TTF_Init() < 0)
		ft_error(TTF_GetError(), "TTF_Init()", 0);
	data.keyboard = keyboard_init();
	data.wnd = wnd_init(WND_TITLE, WND_WIDTH, WND_HEIGHT);
	data.minimap = minimap_init();
	// data.map = get_input(filename);
	SDL_ShowCursor(0);
	data.quit = false;
	data.gameState = Menu_button;
	xy.x = WND_WIDTH / 2;
	xy.y = WND_HEIGHT / 4;
	data.map.map = NULL;
	data.menu.button = startButtonsInit(data,
		4,
		buttonInitData(
			setRect(WND_WIDTH / 2 - 100, WND_HEIGHT / 5, 200, 100),
			xyInit(1, 1),
			0),
			"Continue", "Start", "Options", "Exit");
	data.texture = IMG_LoadTexture(data.wnd.renderer, "res/textures/wolftextures.png");
	data.menu.mouse = mouseInit(data);
	data.maps = NULL;
	return (data);
}
