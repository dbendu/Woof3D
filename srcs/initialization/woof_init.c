/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   woof_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburl <mburl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 23:33:46 by user              #+#    #+#             */
/*   Updated: 2020/08/04 15:59:38 by mburl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "initialization/initialization.h"
#include "woofdefines.h"
#include "initialization/init_all.h"
#include "libft.h"

static void		sdl_init(void)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
		ft_error(SDL_GetError(), "woof_init", 0);
	TTF_Init();
}

static void		pause_init(SDL_Renderer *render, TTF_Font *font, t_menu *pause)
{
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
	int				i;

	*pause = menu_create(render, true);
	i = 0;
	while (i < PAUSE_MENU_BUTTONS)
	{
		button = button_create(render, &rects[i], uids[i]);
		button_add_title(button, titles[i], font);
		menu_add_button(*pause, button);
		i++;
	}
}

static void		main_init(SDL_Renderer *render, TTF_Font *font, t_menu *main)
{
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
	int				i;

	*main = menu_create(render, true);
	i = 0;
	while (i < MAIN_MENU_BUTTONS)
	{
		button = button_create(render, &rects[i], uids[i]);
		button_add_title(button, titles[i], font);
		menu_add_button(*main, button);
		i++;
	}
}

static t_menus	menus_init(SDL_Renderer *render)
{
	t_menus	menus;

	menus.big = TTF_OpenFont("/home/user/Woof3D/res/font/anon.ttf", 30);
	main_init(render, menus.big, &menus.main);
	pause_init(render, menus.big, &menus.pause);
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
	ft_memset(&data.actions, 0, sizeof(t_actions));
	data.menus = menus_init(data.wnd.renderer);
	data.quit = false;
	return (data);
}
