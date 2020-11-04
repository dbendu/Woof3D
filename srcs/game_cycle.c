/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_cycle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburl <mburl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 15:00:33 by mburl             #+#    #+#             */
/*   Updated: 2020/11/04 14:32:25 by mburl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "woof3d.h"
#include "menu/sdl_menu.h"
#include "libft.h"
#include <time.h>
#include "structs/fps.h"

static void	render(t_data *data)
{
	static const SDL_Rect	up = {0, 0, WND_WIDTH, WND_HEIGHT / 2};
	static const SDL_Rect	dn = {0, WND_HEIGHT / 2, WND_WIDTH, WND_HEIGHT / 2};
	t_ray					*rays;

	SDL_SetRenderDrawColor(data->wnd.renderer, 0, 0, 0, 0xff);
	SDL_RenderClear(data->wnd.renderer);
	SDL_SetRenderDrawColor(data->wnd.renderer, 0, 0xde, 0xff, 0xff);
	SDL_RenderFillRect(data->wnd.renderer, &up);
	SDL_SetRenderDrawColor(data->wnd.renderer, 0x57, 0x57, 0x57, 0xff);
	SDL_RenderFillRect(data->wnd.renderer, &dn);
	rays = raycast(data->map.hero.pov,
					data->map.hero.position, data->map.map);
	draw_vis(&data->wnd, rays, data->map.map);
	if (data->actions.show_minimap)
	{
		draw_map(data->wnd.renderer, data->map.hero.position, data->map.map);
		draw_rays(data->wnd.renderer, rays, data->map.hero.position);
	}
	free(rays);
	SDL_UpdateWindowSurface(data->wnd.window);
}

static void	update_actions(t_actions *actions, t_keyboard keyboard)
{
	actions->move_forward = keyboard[MOVE_FORWARD];
	actions->move_back = keyboard[MOVE_BACK];
	actions->move_left = keyboard[MOVE_LEFT];
	actions->move_right = keyboard[MOVE_RIGHT];
	actions->run = keyboard[RUN];
	actions->to_pause = keyboard[ESC];
	actions->sonic_mode = keyboard[SONIC_MODE];
	actions->show_minimap = keyboard[SHOW_MINIMAP];
}

void		game_cycle(t_data *data)
{
	t_fps		fps;

	SDL_GetRelativeMouseState(NULL, NULL);
	while (true)
	{
		fps_init(&fps);
		SDL_PumpEvents();
		update_actions(&data->actions, data->keyboard);
		if (data->actions.to_pause)
			break ;
		update(data);
		render(data);
		fps_think(&fps);
		ft_putnbr((int)fps.framespersecond);
		ft_putchar('\n');
	}
}
