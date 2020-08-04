/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburl <mburl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 15:08:06 by mburl             #+#    #+#             */
/*   Updated: 2020/08/04 16:02:05 by mburl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <SDL2/SDL.h>
#include "structs/point.h"

SDL_Color	init_sdl_color(int r, int g, int b, int a)
{
	SDL_Color	color;

	color.r = r;
	color.g = g;
	color.b = b;
	color.a = a;
	return (color);
}

void		setup_color(SDL_Renderer *render, t_point *point)
{
	if (point->wall_c == 1)
		SDL_SetRenderDrawColor(render, 0xff, 0, 0, 0xff);
	if (point->wall_c == 2)
		SDL_SetRenderDrawColor(render, 0, 0xff, 0, 0xff);
	if (point->wall_c == 3)
		SDL_SetRenderDrawColor(render, 0, 0, 0xff, 0xff);
	else if (point->wall_c == 4)
		SDL_SetRenderDrawColor(render, 0xff, 0, 0xff, 0xff);
	else if (point->wall_c == 0)
		SDL_SetRenderDrawColor(render, 0xff, 0xff, 0xff, 0xff);
	else
		SDL_SetRenderDrawColor(render, 0xff, 0xff, 0, 0xff);
}
