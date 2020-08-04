/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   woof_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburl <mburl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 23:33:46 by user              #+#    #+#             */
/*   Updated: 2020/08/04 07:58:20 by mburl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "initialization.h"
#include "woofdefines.h"
#include "init_all.h"
#include "libft.h"

static void		sdl_init(void)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
		ft_error(SDL_GetError(), "woof_init", 0);
	TTF_Init();
}

static t_menu	pause_init(SDL_Renderer *render, TTF_Font *font)
{
	t_menu			pause;
	const SDL_Rect	rects[PAUSE_MENU_BUTTONS] = {
			{WND_WIDTH / 2 - 150 / 2, WND_HEIGHT / 2 - 140, 150, 80},
			{WND_WIDTH / 2 - 150 / 2, WND_HEIGHT / 2 - 40, 150, 80},
			{WND_WIDTH / 2 - 150 / 2, WND_HEIGHT / 2 + 60, 150, 80}
	};
	const char		titles[PAUSE_MENU_BUTTONS][10] = {
			"Continue", "Main menu", "Exit"
	};
	const int32_t	uids[PAUSE_MENU_BUTTONS] = {
			BUTTON_CONTINUE, BUTTON_TO_MAIN, BUTTON_EXIT
	};
	t_button		button;

	pause = menu_create(render, true);
	for (int i = 0; i < PAUSE_MENU_BUTTONS; ++i) {
		button = button_create(render, &rects[i], uids[i]);
		button_add_title(button, titles[i], font);
		menu_add_button(pause, button);
	}
	return (pause);
}

static t_menu	main_init(SDL_Renderer *render, TTF_Font *font)
{
	t_menu			main;
	const SDL_Rect	rects[MAIN_MENU_BUTTONS] = {
		{WND_WIDTH / 2 - 150 / 2, WND_HEIGHT / 2 - 140, 150, 80},
		{WND_WIDTH / 2 - 150 / 2, WND_HEIGHT / 2 - 40, 150, 80},
		{WND_WIDTH / 2 - 150 / 2, WND_HEIGHT / 2 + 60, 150, 80}
	};
	const char		titles[MAIN_MENU_BUTTONS][10] = {
		"Game", "Settings", "Exit"
	};
	const int32_t	uids[MAIN_MENU_BUTTONS] = {
		BUTTON_GAME, BUTTON_SETTINGS, BUTTON_EXIT
	};
	t_button		button;

	main = menu_create(render, true);
	for (int i = 0; i < MAIN_MENU_BUTTONS; ++i) {
		button = button_create(render, &rects[i], uids[i]);
		button_add_title(button, titles[i], font);
		menu_add_button(main, button);
	}
	return (main);
}

static t_menus	menus_init(SDL_Renderer *render)
{
	t_menus	menus;

	menus.big = TTF_OpenFont("anon.ttf", 30);
	menus.main = main_init(render, menus.big);
	menus.settings = NULL;
	menus.pause = pause_init(render, menus.big);
	return (menus);
}

t_data			woof_init(const char *filename)
{
	t_data	data;

	sdl_init();
	data.keyboard = keyboard_init();
	data.wnd = wnd_init(WND_TITLE, WND_WIDTH, WND_HEIGHT);
	data.minimap = minimap_init();
	data.map = map_init(filename);
	data.jumps.exit = false;
	data.jumps.to_game = false;
	data.jumps.to_main = false;
	data.menus = menus_init(data.wnd.renderer);
	data.quit = false;
	return (data);
}
