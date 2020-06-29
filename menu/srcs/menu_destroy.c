/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_destroy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburl <mburl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 15:13:03 by mburl             #+#    #+#             */
/*   Updated: 2020/06/29 15:17:25 by mburl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private_menu.h"
#include "sdl_menu.h"

void	menu_destroy(t_menu menu)
{
	int		btn;

	btn = 0;
	while (btn < menu->buttons_count)
		button_destroy(menu->buttons[btn++]);
	free(menu->buttons);
	free(menu);
}
