/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburl <mburl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 08:56:46 by mburl             #+#    #+#             */
/*   Updated: 2020/08/04 09:37:54 by mburl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "woof3d.h"
#include <SDL2/SDL.h>
#include "libft.h"

/*
** calculate h w and everyting else to window size
*/

void	draw_map(SDL_Renderer *render, t_vector_point *map)
{
	SDL_Rect	rect;
	int			y;
	int			x;

	rect.h = CELL_SIZE - 1;
	rect.w = CELL_SIZE - 1;
	rect.y = 1;
	y = -1;
	while (++y < vec_size(&map))
	{
		rect.x = 1;
		x = -1;
		while (++x < vec_size(&map[y]))
		{
			if (!map[y][x].wall)
				SDL_SetRenderDrawColor(render, 0x78, 0x78, 0x78, 0xff);
			else
				SDL_SetRenderDrawColor(render, 0xff, 0xff, 0xff, 0xff);
			SDL_RenderFillRect(render, &rect);
			rect.x += CELL_SIZE;
		}
		rect.y += CELL_SIZE;
	}
}

void	draw_rays(SDL_Renderer *render, t_ray *rays, t_position start)
{
	int		x;

	x = 0;
	SDL_SetRenderDrawColor(render, 0xff, 0, 0, 0xff);
	while (x < WND_WIDTH)
	{
		SDL_RenderDrawLine(render, start.x, start.y,
							rays[x].x, rays[x].y);
		x++;
	}
}
