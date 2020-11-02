/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburl <mburl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 08:56:46 by mburl             #+#    #+#             */
/*   Updated: 2020/11/02 20:47:55 by mburl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "woof3d.h"
#include <SDL2/SDL.h>
#include "libft.h"

/*
** calculate h w and everyting else to window size
*/

void	draw_map(SDL_Renderer *render, t_position start, t_vector_point *map)
{
	SDL_Rect	rect;
	int			y;
	int			x;

	rect.h = CELL_SIZE - 1;
	rect.w = CELL_SIZE - 1;
	rect.y = WND_HEIGHT / 2 - start.y;
	y = -1;
	while (++y < vec_size(&map))
	{
		rect.x = WND_WIDTH / 2 - start.x;
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

/*
** void	draw_rays(SDL_Renderer *render, t_ray *rays, t_position start)
** {
** 	int		x;
** 	int		offset_x;
** 	int		offset_y;
** 	int		x1;
** 	int		x2;
** 	int		y1;
** 	int		y2;
**
** 	x = 0;
** 	offset_x = (int)(WND_WIDTH / 2);
** 	offset_y = (int)(WND_HEIGHT / 2);
** 	SDL_SetRenderDrawColor(render, 0xff, 0, 0, 0xff);
** 	while (x < WND_WIDTH)
** 	{
** 		x1 = offset_x - start.x;
** 		x2 = offset_x - rays[x].x;
** 		y1 = offset_y - start.y;
** 		y2 = offset_y - rays[x].y;
** 		SDL_RenderDrawLine(render, x1, y1, x2, y2);
** 		x++;
** 	}
** }
*/
