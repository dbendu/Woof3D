/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_draw.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburl <mburl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 15:13:04 by mburl             #+#    #+#             */
/*   Updated: 2020/06/29 15:38:00 by mburl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private_menu.h"
#include "sdl_menu.h"
#include "mouse.h"
#include <stdbool.h>

bool	menu_draw(t_menu menu)
{
	int		press;
	bool	cont;
	int		i;

	i = 0;
	cont = 0;
	SDL_SetRenderDrawColor(menu->render, 0, 0, 0, 0xff);
	SDL_RenderClear(menu->render);
	press = update_mouse(&menu->mouse);
	while (i < menu->buttons_count)
	{
		cont += check_hover(menu->buttons[i], &menu->mouse.tip, press, menu);
		button_draw(menu->buttons[i++]);
	}
	draw_mouse(menu->render, menu->mouse);
	return (cont);
}
