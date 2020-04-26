/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/26 15:45:05 by user              #+#    #+#             */
/*   Updated: 2020/04/27 02:07:39 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Woof3D.h"
#include "mouse.h"
#include "Woof_defines.h"

static void	wrap_mouse(t_mouse *mouse, SDL_Window *window)
{
	int x;
	int y;

	SDL_GetMouseState(&x, &y);
	if (x == 0)
		SDL_WarpMouseInWindow(window, WIDTH - 3, y);
	else
		SDL_WarpMouseInWindow(window, 2, y);
	mouse->x = x;
}

void		mouse_motion(t_data *data, const SDL_MouseMotionEvent *m)
{
	if ((m->x == 0 && data->mouse.x == 0) ||
		(m->x == WIDTH - 1 && data->mouse.x == WIDTH - 1))
		wrap_mouse(&data->mouse, data->wnd.sdl.window);
	if (m->x > data->mouse.x)
		data->map.hero.pov += 1;
	else if (m->x < data->mouse.x)
		data->map.hero.pov -= 1;
	if (data->map.hero.pov >= 360 || data->map.hero.pov <= -360)
		data->map.hero.pov = 0;
	data->mouse.x = m->x;
}
