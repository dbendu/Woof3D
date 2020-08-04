/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_selected_uid.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburl <mburl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 15:13:11 by mburl             #+#    #+#             */
/*   Updated: 2020/08/04 16:00:32 by mburl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "menu/private_menu.h"
#include "menu/sdl_menu.h"

int32_t		menu_selected_uid(t_menu menu)
{
	return (menu->selected_uid);
}
