/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_selected_uid.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburl <mburl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 15:13:11 by mburl             #+#    #+#             */
/*   Updated: 2020/06/29 15:13:12 by mburl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private_menu.h"
#include "sdl_menu.h"

int32_t		menu_selected_uid(t_menu menu)
{
	return (menu->selected_uid);
}
