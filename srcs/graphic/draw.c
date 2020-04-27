/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/26 14:24:00 by user              #+#    #+#             */
/*   Updated: 2020/04/27 23:40:00 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

  #include <stdio.h>
  #include <time.h>

#include"Woof3D.h"
#include "Woof_defines.h"
#include "ray.h"





// void			d3Render(t_data *data)
// {
// 	int max_rays = FOV;
// 	t_ray	ray;
// 	SDL_Rect	rect;
// 	Uint32		color;
// 	int			a;

// 	rect.h = HEIGHT;
// 	rect.w = WIDTH / FOV;
// 	ray.pov = data->map.hero.pov - data->map.hero.fov / 2;
// 	for (int rays = 0; rays < max_rays; ++rays) {
// 		ray.x = data->map.hero.absolute_position.x;
// 		ray.y = data->map.hero.absolute_position.y;
// 		ray_cast(data->map.map, &ray, data->map.hero);
// 		rect.x = rays * rect.w;
// 		rect.y = 0;
// 		a = ft_map(ray.len, 800, 0, 0, 255);
// 		color = pack_color(255, a, a, a);
// 		SDL_FillRect(data->wnd.main_canvas, &rect, color);
// 		ray.pov += data->map.hero.fov / max_rays;
// 	}
// 	SDL_Texture *texture = SDL_CreateTextureFromSurface(data->wnd.sdl.renderer, data->wnd.main_canvas);
// 	SDL_RenderCopy(data->wnd.sdl.renderer, texture, NULL, NULL);
// 	SDL_DestroyTexture(texture);
// }








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
	for (int ray = 0; ray < hero.fov * RAYS_BY_ANGLE; ++ray) {
		SDL_RenderDrawLine(data->wnd.sdl.renderer, hero.position.x, hero.position.y,
							rays[ray].x, rays[ray].y);

	}

	(void)rays;
}




void	draw(t_data *data)
{
	static bool True = true;
	t_ray	*rays;

	// rays amount equal to RAYS_BY_ANGLE * hero.fov
	rays = raycast(data->map.hero.pov, data->map.hero.fov,	// ray distance now ignored
					POV_DISTANCE, &data->map);


	if (True)
	{
		for (int i = 0; i < RAYS_BY_ANGLE * data->map.hero.fov; ++i) {
			printf("%f-%f\n", rays[i].y, rays[i].x);
		}
		True = false;
	}
	SDL_SetRenderDrawColor(data->wnd.sdl.renderer, 0x00, 0x00, 0x00, 0xff);
	SDL_RenderClear(data->wnd.sdl.renderer);
	// d3Render(data);
	draw_game(data, rays);
	SDL_RenderPresent(data->wnd.sdl.renderer);

	free(rays);
}
