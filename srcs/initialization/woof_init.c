/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   woof_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: konsolka <konsolka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 23:33:46 by user              #+#    #+#             */
/*   Updated: 2020/05/04 21:12:47 by konsolka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "initialization.h"
#include "WoofDefines.h"
#include "init_all.h"
#include "libft.h"
#include "button.h"
#include <SDL2/SDL_image.h>
#include "main_menu.h"

static void	sdl_init(void)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
		ft_error(SDL_GetError(), "woof_init", 0);
}

t_data	woof_init(const char *filename)
{
	t_data	data;

	sdl_init();
	data.keyboard = keyboard_init();
	data.wnd = wnd_init(WND_TITLE, WND_WIDTH, WND_HEIGHT);
	data.minimap = minimap_init();
	data.map = map_init(filename);
	data.menu = menuInit(data);
	// data.map = get_input(filename);
	SDL_ShowCursor(0);
	data.quit = false;
	data.gameState = Menu;
	
	return (data);
}
