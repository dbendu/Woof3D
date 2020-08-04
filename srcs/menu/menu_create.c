/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_create.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburl <mburl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 15:13:02 by mburl             #+#    #+#             */
/*   Updated: 2020/08/04 16:04:00 by mburl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "menu/private_menu.h"
#include "menu/sdl_menu.h"
#include "controls/mouse.h"

t_menu	menu_create(SDL_Renderer *render, bool cycling)
{
	t_menu	menu;

	menu = malloc(sizeof(struct s_menu));
	menu->mouse = mouse_init(render);
	menu->render = render;
	menu->cycling = cycling;
	menu->buttons_allocated = BUTTONS_INCREASE;
	menu->buttons_count = 0;
	menu->buttons = malloc(sizeof(t_button) * BUTTONS_INCREASE);
	return (menu);
}
