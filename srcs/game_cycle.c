/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_cycle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburl <mburl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 15:00:33 by mburl             #+#    #+#             */
/*   Updated: 2020/11/02 16:00:43 by mburl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "woof3d.h"
#include "menu/sdl_menu.h"
#include "libft.h"
#include <time.h>
#include "structs/fps.h"

static void	render(t_data *data, bool map)
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
	if (map)
	{
		draw_map(data->wnd.renderer, data->map.map);
		draw_rays(data->wnd.renderer, rays, data->map.hero.position);
	}
	free(rays);
	SDL_UpdateWindowSurface(data->wnd.window);
}

static void	event_handle(const SDL_Event *event, t_data *data)
{
	if (event->type == SDL_QUIT)
		data->jumps.exit = true;
	else if (event->type == SDL_KEYDOWN)
	{
		if (event->key.keysym.sym == SDLK_ESCAPE)
			pause_cycle(data);
		else
			handle_key_press(&data->keyboard, event->key.keysym.sym);
	}
	else if (event->type == SDL_KEYUP)
		handle_key_release(&data->keyboard, event->key.keysym.sym);
}

static void	ft_putchar(char c)
{
	write(1, &c, 1);
}

static void	ft_putnbr(int n)
{
	if (n >= 10)
		ft_putnbr(n / 10);
	ft_putchar((n % 10) + '0');
}

void		game_cycle(t_data *data)
{
	SDL_Event	event;
	bool		draw_map;
	t_fps		fps;

	SDL_SetRelativeMouseMode(1);
	draw_map = false;
	fps_init(&fps);
	while (true)
	{
		if (SDL_PollEvent(&event))
		{
			if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_m)
				draw_map = !draw_map;
			else
				event_handle(&event, data);
			if (data->jumps.to_main || data->jumps.exit)
				break ;
		}
		update(data);
		render(data, draw_map);
		fps_think(&fps);
		ft_putnbr((int)fps.framespersecond);
		ft_putchar('\n');
	}
}
