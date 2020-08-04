/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_cycle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburl <mburl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 15:00:33 by mburl             #+#    #+#             */
/*   Updated: 2020/08/04 09:18:52 by mburl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "woof3d.h"
#include "sdl_menu.h"
#include "libft.h"
#include <time.h>

void		draw_vis(t_wnd *sdl, t_ray *rays, int fov, t_point **map)
{
	const float	distance = WND_WIDTH / 2 / tan(to_rad(fov / 2));
	int			x;
	int			texture_x;
	uint32_t	*dst_pixels;
	uint32_t	*src_pixels;
	int			texture_ind;
	int			height;
	int			up;
	int			down;
	float		texture_y;
	float		wnd_y;
	float		y_increase;

	x = -1;
	while (++x < WND_WIDTH)
	{
		texture_ind = map[(int)rays[x].y / CELL_SIZE]
							[(int)rays[x].x / CELL_SIZE].wall_c - 1;
		dst_pixels = sdl->main_canvas->pixels;
		src_pixels = sdl->textures[texture_ind].pixels;
		height = CELL_SIZE / rays[x].len * distance;
		up = (WND_HEIGHT / 2) - (height  / 2);
		down = up + height;
		y_increase = sdl->textures[0].h / (float)height;
		wnd_y = up;
		texture_y = 0;
		if (rays[x].side == X_SIDE)
			texture_x = (int)rays[x].x % sdl->textures[0].w;
		else
			texture_x = (int)rays[x].y % sdl->textures[0].w;
		if (wnd_y < 0)
		{
			texture_y += -wnd_y * y_increase;
			wnd_y = 0;
		}
		if (down > WND_HEIGHT)
			down = WND_HEIGHT;
		while (wnd_y < down)
		{
			dst_pixels[(int)wnd_y * WND_WIDTH + x] = src_pixels[(int)texture_y *
				sdl->textures[0].w + texture_x];
			wnd_y += 1;
			texture_y += y_increase;
		}
	}
}

static void	render(t_data *data, bool map)
{
	static const SDL_Rect	up = {0, 0, WND_WIDTH, WND_HEIGHT / 2};
	static const SDL_Rect	dn = {0, WND_HEIGHT / 2, WND_WIDTH, WND_HEIGHT / 2};
	int						fov;
	t_ray					*rays;

	SDL_SetRenderDrawColor(data->wnd.renderer, 0, 0, 0, 0xff);
	SDL_RenderClear(data->wnd.renderer);
	SDL_SetRenderDrawColor(data->wnd.renderer, 0, 0xde, 0xff, 0xff);
	SDL_RenderFillRect(data->wnd.renderer, &up);
	SDL_SetRenderDrawColor(data->wnd.renderer, 0x57, 0x57, 0x57, 0xff);
	SDL_RenderFillRect(data->wnd.renderer, &dn);
	fov = 60;
	rays = raycast(fov, data->map.hero.pov,
		data->map.hero.position, data->map.map);
	draw_vis(&data->wnd, rays, fov, data->map.map);
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

void	game_cycle(t_data *data)
{
	SDL_Event	event;
	bool		draw_map;

	SDL_SetRelativeMouseMode(1);
	draw_map = false;
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
		SDL_Delay(7);
	}
}
