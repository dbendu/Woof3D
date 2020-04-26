/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/26 14:24:00 by user              #+#    #+#             */
/*   Updated: 2020/04/27 02:14:32 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

  #include <stdio.h>
  #include <time.h>

#include"Woof3D.h"
#include "Woof_defines.h"


// static void	draw_rect(int32_t *pixels, int size_line, SDL_Rect *rect)
// {
// 	for (int32_t y = 0; y < rect->h; ++y) {
// 		for (int32_t x = 0; x < rect->w; ++x) {
// 			pixels[(rect->y + y) * size_line + x + rect->x] = 0xffffffff;
// 		}
// 	}
// }


typedef struct	s_ray
{
	float		x;
	float		y;
	float		len;
	float		pov;
}				t_ray;

void	ray_cast(t_vector_point *map, t_ray *ray)
{
	int y;
	int x;

	y = ray->y / CELL_SIZE;
	x = ray->x / CELL_SIZE;
	while (!map[y][x].wall) {
		ray->x += cos(ray->pov * 3.14 / 180) * 0.5;
		ray->y += sin(ray->pov * 3.14 / 180) * 0.5;
		y = ray->y / CELL_SIZE;
		x = ray->x / CELL_SIZE;
	}
}




static void	draw_game(t_data *data)
{
	// SDL_Texture	*texture;
	SDL_Rect	rect;

	rect.h = CELL_SIZE;
	rect.w = CELL_SIZE;
	for (int i = 0; i < WIDTH * HEIGHT; ++i)
		((int32_t*)data->wnd.main_canvas->pixels)[i] = 0xff000000;

	SDL_SetRenderDrawColor(data->wnd.sdl.renderer, 0xff, 0xff, 0xff, 0xff);
	rect.y = 0;
	for (int y = 0; y < vec_size(&data->map.map); ++y) {
		rect.x = 0;
		for (int x = 0; x < vec_size(&data->map.map); ++x) {
			if (data->map.map[y][x].wall) {
				SDL_RenderDrawRect(data->wnd.sdl.renderer, &rect);
			}
			rect.x += CELL_SIZE;
		}
		rect.y += CELL_SIZE;
	}

	int max_rays = 128;
		t_ray	ray;
	ray.pov = data->map.hero.pov - data->map.hero.fov / 2;
	for (int rays = 0; rays < max_rays; ++rays) {
		ray.x = data->map.hero.absolute_position.x;
		ray.y = data->map.hero.absolute_position.y;
		ray_cast(data->map.map, &ray);
		SDL_RenderDrawLine(data->wnd.sdl.renderer, data->map.hero.absolute_position.x, data->map.hero.absolute_position.y,
													ray.x, ray.y);
		ray.pov += data->map.hero.fov / max_rays;
	}
	SDL_SetRenderDrawColor(data->wnd.sdl.renderer, 0xff, 0x00, 0x00, 0xff);
	SDL_RenderDrawPoint(data->wnd.sdl.renderer, data->map.hero.absolute_position.x, data->map.hero.absolute_position.y);



	// texture = SDL_CreateTextureFromSurface(data->wnd.sdl.renderer, data->wnd.main_canvas);
	SDL_RenderSetViewport(data->wnd.sdl.renderer, NULL);
	// SDL_RenderCopy(data->wnd.sdl.renderer, texture, NULL, NULL);
	// SDL_DestroyTexture(texture);
}


















// static void	draw_minimap(t_data *data)
// {
// 	SDL_Texture	*texture;

// 	for (int i = 0; i < MINIMAP_SZ * MINIMAP_SZ; ++i)
// 		((int32_t*)data->wnd.minimap.surface->pixels)[i] = 0xff000000;

// 	// put hero and view direction
// 	((int32_t*)data->wnd.minimap.surface->pixels)[MINIMAP_SZ * MINIMAP_SZ / 2 + MINIMAP_SZ / 2] = 0xffffffff;
// 	int dir_x = MINIMAP_SZ / 2 + 8 * cos(data->map.hero.pov * 3.14 / 180);
// 	int dir_y = MINIMAP_SZ / 2 + 8 * sin(data->map.hero.pov * 3.14 / 180);
// 	((int32_t*)data->wnd.minimap.surface->pixels)[MINIMAP_SZ * dir_y + dir_x] = 0xffffffff;





// 	SDL_Rect	rect;

// 	rect.h = 20;
// 	rect.w = 20;
// 	t_hero hero = data->map.hero;
// 	t_map  map  = data->map;
// 	int start_x = ft_max(0, hero.relative_position.x - 4);
// 	int end_x = ft_min(vec_size(&map.map[0]), hero.relative_position.x + 4) + 1;
// 	int start_y = ft_max(0, hero.relative_position.y - 4);
// 	int end_y = ft_min(vec_size(&map.map), hero.relative_position.y + 4) + 1;
// 	for (int y = start_y; y < end_y; ++y) {
// 		for (int x = start_x; x < end_x; ++x) {
// 			if (map.map[y][x].wall) {
// 				rect.x = (x - start_x) * 20; // - (x - start_x);
// 				rect.y = (y - start_y) * 20; // - (y - start_y);
// 				draw_rect(data->wnd.minimap.surface->pixels, &rect);
// 				// if (SDL_RenderDrawRect(data->wnd.sdl.renderer, &rect) < 0)
// 			}
// 		}
// 	}


// 	SDL_RenderSetViewport(data->wnd.sdl.renderer, &data->wnd.minimap.viewport);
// 	texture = SDL_CreateTextureFromSurface( data->wnd.sdl.renderer,
// 											data->wnd.minimap.surface);
// 	SDL_RenderCopy(data->wnd.sdl.renderer, texture, NULL, NULL);
// 	SDL_RenderPresent(data->wnd.sdl.renderer);
// 	SDL_RenderSetViewport(data->wnd.sdl.renderer, NULL);
// 	SDL_DestroyTexture(texture);

// 	((int32_t*)data->wnd.minimap.surface->pixels)[MINIMAP_SZ * MINIMAP_SZ / 2 + MINIMAP_SZ / 2] = 0xff000000;
// 	((int32_t*)data->wnd.minimap.surface->pixels)[MINIMAP_SZ * dir_y + dir_x] = 0xff000000;
// }

static void	draw_interface(t_wnd *wnd)
{
	SDL_Texture	*texture;

	texture = SDL_CreateTextureFromSurface(wnd->sdl.renderer,
											wnd->interface.surface);
	SDL_RenderSetViewport(wnd->sdl.renderer, &wnd->interface.viewport);
	SDL_RenderCopy(wnd->sdl.renderer, texture, NULL, NULL);
	SDL_RenderSetViewport(wnd->sdl.renderer, NULL);
	SDL_DestroyTexture(texture);
}

void	draw(t_data *data)
{
	SDL_SetRenderDrawColor(data->wnd.sdl.renderer, 0x00, 0x00, 0x00, 0xff);
	SDL_RenderClear(data->wnd.sdl.renderer);
	draw_game(data);
	// if (data->wnd.minimap.show)
	// 	draw_minimap(data);
	if (data->wnd.interface.show)
		draw_interface(&data->wnd);
	SDL_RenderPresent(data->wnd.sdl.renderer);
}
