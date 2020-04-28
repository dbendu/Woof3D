/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   woof_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: konsolka <konsolka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/26 13:00:08 by user              #+#    #+#             */
/*   Updated: 2020/04/28 18:01:14 by konsolka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Woof_defines.h"
#include "Woof3D.h"
#include "input.h"

static t_keyboard	keyboard_init(void)
{
	t_keyboard	keyboard;
	int			i;

	i = 0;
	while (i < KEYS_BINDED)
		keyboard.key[i++] = false;
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
	data.quit = false;
	data.max_rays = data.map.hero.fov * 5;
	return (data);
}
