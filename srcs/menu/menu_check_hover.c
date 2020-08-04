/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_check_hover.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburl <mburl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 15:13:00 by mburl             #+#    #+#             */
/*   Updated: 2020/08/04 16:01:34 by mburl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "button/private_button.h"
#include "button/button.h"
#include <SDL2/SDL.h>
#include "structs/data.h"
#include "menu/private_menu.h"

bool	check_hover(t_button button, SDL_Rect *rect, int press, t_menu menu)
{
	if (SDL_HasIntersection(&button->btn_rect, rect))
	{
		button_select(button);
		if (press)
		{
			menu->selected_uid = button_uid(button);
			return (true);
		}
	}
	else if (button->selected)
		button_deselect(button);
	return (false);
}
