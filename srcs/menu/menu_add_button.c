/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_add_button.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburl <mburl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 15:12:58 by mburl             #+#    #+#             */
/*   Updated: 2020/08/04 16:00:32 by mburl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "menu/private_menu.h"
#include "menu/sdl_menu.h"

static t_button	*increase(t_button *buttons, int count)
{
	const int	new_size = count + BUTTONS_INCREASE;
	t_button	*new_buttons;
	int			i;

	new_buttons = malloc(sizeof(t_button) * new_size);
	i = -1;
	while (++i < count)
		new_buttons[i] = buttons[i];
	free(buttons);
	return (new_buttons);
}

void			menu_add_button(t_menu menu, t_button button)
{
	if (menu->buttons_count == menu->buttons_allocated)
		menu->buttons = increase(menu->buttons,
									menu->buttons_count);
	menu->buttons[menu->buttons_count] = button;
	if (menu->buttons_count == 0)
	{
		button_select(menu->buttons[0]);
		menu->selected_ind = 0;
		menu->selected_uid = button_uid(button);
	}
	menu->buttons_count += 1;
}
