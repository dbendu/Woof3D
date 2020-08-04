/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_select_button.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburl <mburl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 15:13:06 by mburl             #+#    #+#             */
/*   Updated: 2020/08/04 16:00:32 by mburl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "menu/private_menu.h"
#include "menu/sdl_menu.h"

void	menu_select_button(t_menu menu, int32_t uid)
{
	int	btn_ind;

	btn_ind = 0;
	while (btn_ind < menu->buttons_count &&
			uid != button_uid(menu->buttons[btn_ind]))
		btn_ind++;
	if (btn_ind != menu->buttons_count && btn_ind != menu->selected_ind)
	{
		button_deselect(menu->buttons[menu->selected_ind]);
		button_select(menu->buttons[btn_ind]);
		menu->selected_ind = btn_ind;
		menu->selected_uid = uid;
	}
}
