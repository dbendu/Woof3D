/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/26 14:24:00 by user              #+#    #+#             */
/*   Updated: 2020/04/29 13:59:57 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

  #include <stdio.h>
  #include <time.h>

#include"Woof3D.h"
#include "Woof_defines.h"
#include "ray.h"
#include <SDL2/SDL.h>

void			d3Render(t_data *data, t_ray *ray)
{
	SDL_Rect	rect;
	SDL_Rect	cloud;
	SDL_Rect	floor;
	Uint32		color;

	rect.w = WIDTH / data->max_rays;
	cloud.w = rect.w;
	floor.w = rect.w;
	for (int rays = 0; rays < data->max_rays; rays++)
	{
		// printf("angle = %d\n", ray[rays].angle);
		rect.h = (int)ft_map(ray[rays].len, 0, WIDTH, HEIGHT, 0);
		rect.y = (HEIGHT - rect.h) / 2;
		cloud.y = 0;
		cloud.h = rect.y;
		cloud.x = rays * rect.w;
		floor.x = rays * rect.w;
		floor.y = rect.y + rect.h;
		floor.h = HEIGHT - floor.y;
		rect.x = rays * rect.w;
		if (ray[rays].wall_c == 1)
			color = SDL_MapRGB(data->wnd.main_canvas->format, 255, 0, 0);
		else if (ray[rays].wall_c == 2)
			color = SDL_MapRGB(data->wnd.main_canvas->format, 0, 255, 0);
		else if (ray[rays].wall_c == 3)
			color = SDL_MapRGB(data->wnd.main_canvas->format, 0, 0, 255);
		else
			color = SDL_MapRGB(data->wnd.main_canvas->format, 255, 255, 0);
		SDL_FillRect(data->wnd.main_canvas, &rect, color);
		SDL_FillRect(data->wnd.main_canvas, &cloud, 0xFFFFC800);
		SDL_FillRect(data->wnd.main_canvas, &floor, 0xFF2A435D);
	}
	SDL_Texture *texture = SDL_CreateTextureFromSurface(data->wnd.sdl.renderer, data->wnd.main_canvas);
	SDL_RenderCopy(data->wnd.sdl.renderer, texture, NULL, NULL);
	SDL_DestroyTexture(texture);
}

static void	draw_game(t_data *data, const t_ray *rays)
{
	SDL_Rect	rect;

	rect.h = CELL_SIZE;
	rect.w = CELL_SIZE;
	rect.y = 0;

	SDL_SetRenderDrawColor(data->wnd.sdl.renderer, 0xff, 0xff, 0xff, 0xff);
	for (int y = 0; y < vec_size(&data->map.map); ++y) {
		rect.x = 0;
		for (int x = 0; x < vec_size(&data->map.map[y]); ++x) {
			if (data->map.map[y][x].wall) {
				SDL_RenderDrawRect(data->wnd.sdl.renderer, &rect);
			}
			rect.x += CELL_SIZE;
		}
		rect.y += CELL_SIZE;
	}

	t_hero hero = data->map.hero;
	for (int ray = 0; ray < data->map.hero.fov; ++ray) {
		SDL_RenderDrawLine(data->wnd.sdl.renderer, hero.position.x, hero.position.y,
							rays[ray].x, rays[ray].y);

	}

	(void)rays;
}


void	draw(t_data *data)
{
	SDL_SetRenderDrawColor(data->wnd.sdl.renderer, 0x00, 0x00, 0x00, 0xff);
	SDL_RenderClear(data->wnd.sdl.renderer);
	// rays amount equal to RAYS_BY_ANGLE * hero.fov
	data->ray = raycast(data->map.hero.pov, data, &data->map);	// ray distance now ignored

	// if (True)
	// {
	// 	for (int i = 0; i < RAYS_BY_ANGLE * data->map.hero.fov; ++i) {
	// 		printf("%f-%f\n", rays[i].y, rays[i].x);
	// 	}
	// 	True = false;
	// }
	SDL_SetRenderDrawColor(data->wnd.sdl.renderer, 0x00, 0x00, 0x00, 0xff);
	SDL_RenderClear(data->wnd.sdl.renderer);
	// d3Render(data, data->ray);
	draw_game(data, data->ray);
	SDL_RenderPresent(data->wnd.sdl.renderer);

	free(data->ray);
}
