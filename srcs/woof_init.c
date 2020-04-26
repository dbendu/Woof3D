/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   woof_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/26 13:00:08 by user              #+#    #+#             */
/*   Updated: 2020/04/26 22:05:25 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Woof_defines.h"
#include "Woof3D.h"
#include "input.h"

static t_keyboard	keyboard_init(void)
{
	t_keyboard	keyboard;

	keyboard.move_back = false;
	keyboard.move_forvard = false;
	keyboard.move_left = false;
	keyboard.move_right = false;
	return (keyboard);
}

static t_mouse		mouse_init(void)
{
	t_mouse	mouse;

	mouse.left_button = false;
	mouse.right_button = false;
	mouse.x = WIDTH / 2;
	return (mouse);
}

t_data	woof_init(const char *map)
{
	t_data data;

	data.wnd = wnd_init();
	data.map = get_input(map);
	data.keyboard = keyboard_init();
	data.mouse = mouse_init();
	return (data);
}
