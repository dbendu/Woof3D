/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/26 14:24:00 by user              #+#    #+#             */
/*   Updated: 2020/04/30 01:05:33 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

  #include <stdio.h>
  #include <time.h>

#include "libft.h"
#include"Woof3D.h"
#include "WoofDefines.h"
#include "ray.h"
#include <SDL2/SDL.h>

// double			ft_map(double value, double start_range, double end_range, double new_range_start, double new_range_end)
// {
// 	return ((value - start_range) / (end_range - start_range) *
// 				(new_range_end - new_range_start) + new_range_start);
// }

// void			d3Render(t_data *data, t_ray *ray)
// {
// 	SDL_Rect	rect;
// 	SDL_Rect	cloud;
// 	SDL_Rect	floor;
// 	Uint32		color;

// 	rect.w = WND_WIDTH / data->map.hero.fov;
// 	cloud.w = rect.w;
// 	floor.w = rect.w;
// 	for (int rays = 0; rays < WND_WIDTH; rays++)
// 	{
// 		// printf("angle = %d\n", ray[rays].angle);
// 		rect.h = (int)ft_map(ray[rays].len, 0, WND_WIDTH, WND_HEIGHT, 0);
// 		rect.y = (WND_HEIGHT - rect.h) / 2;
// 		cloud.y = 0;
// 		cloud.h = rect.y;
// 		cloud.x = rays * rect.w;
// 		floor.x = rays * rect.w;
// 		floor.y = rect.y + rect.h;
// 		floor.h = WND_HEIGHT - floor.y;
// 		rect.x = rays * rect.w;
// 		if (ray[rays].wall_c == 1)
// 			color = SDL_MapRGB(data->wnd.main_canvas->format, 255, 0, 0);
// 		else if (ray[rays].wall_c == 2)
// 			color = SDL_MapRGB(data->wnd.main_canvas->format, 0, 255, 0);
// 		else if (ray[rays].wall_c == 3)
// 			color = SDL_MapRGB(data->wnd.main_canvas->format, 0, 0, 255);
// 		else
// 			color = SDL_MapRGB(data->wnd.main_canvas->format, 255, 255, 0);
// 		SDL_FillRect(data->wnd.main_canvas, &rect, color);
// 		SDL_FillRect(data->wnd.main_canvas, &cloud, 0xFFFFC800);
// 		SDL_FillRect(data->wnd.main_canvas, &floor, 0xFF2A435D);
// 	}
// 	SDL_Texture *texture = SDL_CreateTextureFromSurface(data->wnd.renderer, data->wnd.main_canvas);
// 	SDL_RenderCopy(data->wnd.renderer, texture, NULL, NULL);
// 	SDL_DestroyTexture(texture);
// }

void setup_color(t_data *data, int x_, t_ray *ray)
{
	const int x = ray[x_].x / CELL_SIZE;
	const int y = ray[x_].y / CELL_SIZE;

	if (data->map.map[y][x].wall_c == 1)
		SDL_SetRenderDrawColor(data->wnd.renderer, 0xff, 0x00, 0x00, 0xff);
	else if (data->map.map[y][x].wall_c == 2)
		SDL_SetRenderDrawColor(data->wnd.renderer, 0x0, 0xff, 0x00, 0xff);
	else if (data->map.map[y][x].wall_c == 3)
		SDL_SetRenderDrawColor(data->wnd.renderer, 0x0, 0x00, 0xff, 0xff);
	else if (data->map.map[y][x].wall_c == 4)
		SDL_SetRenderDrawColor(data->wnd.renderer, 0xff, 0x00, 0xff, 0xff);

}

void			d3Render(t_data *data, t_ray *ray)
{
	int			up;
	int			down;
	float		distance = WND_WIDTH / 2 / tan(to_rad(data->map.hero.fov / 2));
	const		float wall_height = WND_HEIGHT / 12;

	for (int x = 0; x < WND_WIDTH; ++x)
	{
		setup_color(data, x, ray);
		float height = wall_height / ray[x].len * distance;
		up = WND_HEIGHT / 2 - height / 2;
		down = WND_HEIGHT / 2 + height / 2;
		SDL_RenderDrawLine(data->wnd.renderer, x, up, x, down);
	}
}

static void	draw_game(t_data *data, const t_ray *rays)
{
	SDL_Rect	rect;

	rect.h = MINIMAP_SZ / vec_size(&data->map.map);
	rect.w = rect.h;
	rect.y = 0;

	SDL_SetRenderDrawColor(data->wnd.renderer, 0xff, 0xff, 0xff, 0xff);
	for (int y = 0; y < vec_size(&data->map.map); ++y) {
		rect.x = 0;
		for (int x = 0; x < vec_size(&data->map.map[y]); ++x) {
			if (data->map.map[y][x].wall) {
				SDL_RenderDrawRect(data->wnd.renderer, &rect);
			}
			rect.x += rect.h;
		}
		rect.y += rect.h;
	}

	t_hero hero = data->map.hero;
	for (int ray = 0; ray < WND_WIDTH; ++ray) {
		SDL_RenderDrawLine(data->wnd.renderer, hero.position.x / CELL_SIZE * rect.h, hero.position.y / CELL_SIZE * rect.h,
							rays[ray].x / CELL_SIZE * rect.h, rays[ray].y / CELL_SIZE * rect.h);

	}
	(void)rays;
}


void	draw(t_data *data)
{
	t_ray	*rays;

	SDL_SetRenderDrawColor(data->wnd.renderer, 0x00, 0x00, 0x00, 0xff);
	SDL_RenderClear(data->wnd.renderer);
	rays = raycast(data->map.hero.pov, &data->map);
	d3Render(data, rays);
	if (data->minimap.show)
		draw_game(data, rays);
	SDL_RenderPresent(data->wnd.renderer);
	free(rays);
}
