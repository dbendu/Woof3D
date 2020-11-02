/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_menu_cycle.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburl <mburl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 15:00:43 by mburl             #+#    #+#             */
/*   Updated: 2020/11/02 20:55:22 by mburl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "woof3d.h"
#include "menu/sdl_menu.h"
#include <unistd.h>

static void	handle_event(t_data *data)
{
	int32_t		uid;

	uid = menu_selected_uid(data->menus.main);
	if (uid == BUTTON_EXIT)
		data->actions.exit = true;
	else if (uid == BUTTON_SETTINGS)
		write(1, "Settings unavalible right now\n", 31);
	else if (uid == BUTTON_GAME)
	{
		game_cycle(data);
		data->actions.to_main = false;
	}
}

void		main_menu_cycle(t_data *data)
{
	bool		ev;
	SDL_Event	event;

	while (true)
	{
		ev = menu_draw(data->menus.main);
		SDL_UpdateWindowSurface(data->wnd.window);
		SDL_WaitEvent(&event);
		if (ev)
			handle_event(data);
		if (data->actions.exit)
			break ;
	}
}
