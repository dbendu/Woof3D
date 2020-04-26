/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interface_create.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/26 11:47:11 by user              #+#    #+#             */
/*   Updated: 2020/04/26 12:34:29 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "interface.h"
#include "Woof_defines.h"
#include "graphic_utils.h"

t_interface	interface_create(void)
{
	t_interface	interface;

	interface.surface = sdl_create_surface(WIDTH, 150);
	interface.exist = true;
	interface.viewport.x = 0;
	interface.viewport.y = HEIGHT - 150;
	interface.viewport.w = WIDTH;
	interface.viewport.h = 150;
	return (interface);
}
