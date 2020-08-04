/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_select_next.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburl <mburl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 15:13:08 by mburl             #+#    #+#             */
/*   Updated: 2020/08/04 16:00:32 by mburl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "menu/private_menu.h"
#include "menu/sdl_menu.h"

void	menu_select_next(t_menu menu)
{
	if (menu->selected_ind != menu->buttons_count - 1 ||
		menu->cycling)
	{
		button_deselect(menu->buttons[menu->selected_ind]);
		if (menu->selected_ind == menu->buttons_count - 1)
			menu->selected_ind = 0;
		else
			menu->selected_ind += 1;
		button_select(menu->buttons[menu->selected_ind]);
		menu->selected_uid = button_uid(menu->buttons[menu->selected_ind]);
	}
}
