/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_cycle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburl <mburl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 15:00:33 by mburl             #+#    #+#             */
/*   Updated: 2020/08/04 08:18:35 by mburl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "woof3d.h"
#include "sdl_menu.h"
#include "libft.h"

static void	handle_key_press(t_keyboard *keyboard, SDL_Keycode key)
{
	if (key == SDLK_w) {
		keyboard->key[MOVE_FORWARD] = true;
	} else if (key == SDLK_s) {
		keyboard->key[MOVE_BACK] = true;
	} else if (key == SDLK_a) {
		keyboard->key[TURN_LEFT] = true;
	} else if (key == SDLK_d) {
		keyboard->key[TURN_RIGHT] = true;
	} else if (key == SDLK_LSHIFT) {
		keyboard->key[RUN] = true;
	}
}

static void	handle_key_release(t_keyboard *keyboard, SDL_Keycode key)
{
	if (key == SDLK_w) {
		keyboard->key[MOVE_FORWARD] = false;
	} else if (key == SDLK_s) {
		keyboard->key[MOVE_BACK] = false;
	} else if (key == SDLK_a) {
		keyboard->key[TURN_LEFT] = false;
	} else if (key == SDLK_d) {
		keyboard->key[TURN_RIGHT] = false;
	} else if (key == SDLK_LSHIFT) {
		keyboard->key[RUN] = true;
	}
}

void	draw_vis(t_wnd *sdl, t_ray *rays, int fov, t_point **map)
{
	const int wall_height = 62;
	const float distance = WND_WIDTH / 2 / tan(to_rad(fov / 2));
	int		x;
	int texture_x;

	x = -1;
	while (++x < WND_WIDTH)
	{
		int texture_ind = map[(int)rays[x].y / CELL_SIZE][(int)rays[x].x / CELL_SIZE].wall_c - 1;
		uint32_t *dst_pixels = sdl->main_canvas->pixels;
		uint32_t *src_pixels = sdl->textures[texture_ind].pixels;
		int height = wall_height / rays[x].len * distance;
		int up = (WND_HEIGHT / 2) - (height  / 2);
		int down = up + height;
		float y_increase = sdl->textures[0].h / (float)height;
		float wnd_y = up;
		float texture_y = 0;

		if (rays[x].side == X_SIDE) {
			texture_x = (int)rays[x].x % sdl->textures[0].w;
		} else {
			texture_x = (int)rays[x].y % sdl->textures[0].w;
		}

		if (wnd_y < 0) {
			texture_y += -wnd_y * y_increase;
			wnd_y = 0;
		}
		if (down > WND_HEIGHT) {
			down = WND_HEIGHT;
		}
		int i_down = down;
		while (wnd_y < i_down) {
			dst_pixels[(int)wnd_y * WND_WIDTH + x] = src_pixels[(int)texture_y * sdl->textures[0].w + texture_x];
			wnd_y += 1;
			texture_y += y_increase;
		}
	}
}

void	draw_map(SDL_Renderer *render, t_vector_point *map)
{
	SDL_Rect	rect;

	rect.h = CELL_SIZE - 1;
	rect.w = CELL_SIZE - 1;
	rect.y = 1;
	for (int y = 0; y < vec_size(&map); ++y) {
		rect.x = 1;
		for (int x = 0; x < vec_size(&map[y]); ++x) {
			if (!map[y][x].wall) {
				SDL_SetRenderDrawColor(render, 0x78, 0x78, 0x78, 0xff);
				SDL_RenderFillRect(render, &rect);
			} else {
				SDL_SetRenderDrawColor(render, 0xff, 0xff, 0xff, 0xff);
				SDL_RenderFillRect(render, &rect);
			}
			rect.x += CELL_SIZE;
		}
		rect.y += CELL_SIZE;
	}
}

void	draw_rays(SDL_Renderer *render, t_ray *rays, t_position start)
{
	SDL_SetRenderDrawColor(render, 0xff, 0, 0, 0xff);
	for (int x = 0; x < WND_WIDTH; ++x) {
		SDL_RenderDrawLine(render, start.x, start.y,
						   rays[x].x, rays[x].y);
	}
}

#include <time.h>

static
void	render(t_data *data, bool map)
{
	SDL_SetRenderDrawColor(data->wnd.renderer, 0, 0, 0, 0xff);
	SDL_RenderClear(data->wnd.renderer);
	static const SDL_Rect	up = {0, 0, WND_WIDTH, WND_HEIGHT / 2};
	static const SDL_Rect	down = {0, WND_HEIGHT / 2, WND_WIDTH, WND_HEIGHT / 2};
	SDL_SetRenderDrawColor(data->wnd.renderer, 0, 0xde, 0xff, 0xff);
	SDL_RenderFillRect(data->wnd.renderer, &up);
	SDL_SetRenderDrawColor(data->wnd.renderer, 0x57, 0x57, 0x57, 0xff);
	SDL_RenderFillRect(data->wnd.renderer, &down);
	int fov = 60;
	t_ray *rays = raycast(fov, data->map.hero.pov, data->map.hero.position, data->map.map);
	draw_vis(&data->wnd, rays, fov, data->map.map);
	if (map) {
		draw_map(data->wnd.renderer, data->map.map);
		draw_rays(data->wnd.renderer, rays, data->map.hero.position);
	}
	free(rays);
	SDL_UpdateWindowSurface(data->wnd.window);
}



static
void	event_handle(const SDL_Event *event, t_data *data)
{
	switch (event->type) {
		case SDL_QUIT:
			data->jumps.exit = true;
			break;
		case SDL_KEYDOWN:
			switch (event->key.keysym.sym) {
				case SDLK_ESCAPE:
					pause_cycle(data);
					break;
				default:
					handle_key_press(&data->keyboard, event->key.keysym.sym);
					break;
			}
			break;
		case SDL_KEYUP:
			handle_key_release(&data->keyboard, event->key.keysym.sym);
			break;
	}
}

void	game_cycle(t_data *data)
{
	SDL_Event	event;
	bool		draw_map = false;

	SDL_SetRelativeMouseMode(1);
	while (true) {
		if (SDL_PollEvent(&event))
		{
			if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_m) {
				draw_map = !draw_map;
			} else {
				event_handle(&event, data);
			}
			if (data->jumps.to_main || data->jumps.exit)
				break ;
		}
		update(data);
		render(data, draw_map);
		SDL_Delay(7);
	}
}
