/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   woof_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: konsolka <konsolka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 23:33:46 by user              #+#    #+#             */
/*   Updated: 2020/05/07 02:01:46 by konsolka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "initialization.h"
#include "WoofDefines.h"
#include "init_all.h"
#include "libft.h"
#include "button.h"
#include <SDL2/SDL_image.h>
#include "main_menu.h"
#include <SDL2/SDL_ttf.h>

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
	data.map = map_init(filename);
	// data.map = get_input(filename);
	SDL_ShowCursor(0);
	data.quit = false;
	data.gameState = Menu_button;
	xy.x = WND_WIDTH / 2;
	xy.y = WND_HEIGHT / 4;
	data.menu.button = startButtonsInit(data, 5, xy, "Continue", "Start", "Options", "Exit", "Menu");
	data.menu.mouse = mouseInit(data);
	data.maps = NULL;
	return (data);
}
