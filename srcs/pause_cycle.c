/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pause_cycle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburl <mburl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 15:00:47 by mburl             #+#    #+#             */
/*   Updated: 2020/08/04 16:00:32 by mburl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "woof3d.h"
#include "menu/sdl_menu.h"

static void	input_handle(t_data *data)
{
	int32_t	uid;

	uid = menu_selected_uid(data->menus.pause);
	if (uid == BUTTON_CONTINUE)
		data->actions.to_game = true;
	else if (uid == BUTTON_TO_MAIN)
		data->actions.to_main = true;
	else if (uid == BUTTON_EXIT)
		data->actions.exit = true;
}

void		pause_cycle(t_data *data)
{
	SDL_Event	event;
	bool		ev;

	while (true)
	{
		ev = menu_draw(data->menus.pause);
		SDL_UpdateWindowSurface(data->wnd.window);
		SDL_WaitEvent(&event);
		if (ev)
			input_handle(data);
		if (data->actions.exit)
			exit(0);
		else if (data->actions.to_game || data->actions.to_main)
			break ;
	}
	data->actions.to_game = false;
}
