/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburl <mburl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 15:08:06 by mburl             #+#    #+#             */
/*   Updated: 2020/11/04 14:44:17 by mburl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <SDL2/SDL.h>
#include "structs/point.h"
#include "structs/fps.h"
#include "woofdefines.h"

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

void		count_cols(const char *line, size_t *max_size)
{
	size_t		cols;

	cols = 0;
	while (true)
	{
		while (*line == ' ' || *line == '\t')
			line += 1;
		if (*line == '\0')
			break ;
		cols++;
		line++;
	}
	*max_size = (cols > *max_size) ? cols : *max_size;
}

void		fps_init(t_fps *fps)
{
	ft_memset(fps->frametimes, 0, sizeof(fps->frametimes));
	fps->framecount = 0;
	fps->framespersecond = 0;
	fps->frametimelast = SDL_GetTicks();
}

void		fps_think(t_fps *fps)
{
	Uint32	frametimesindex;
	Uint32	getticks;
	Uint32	count;
	Uint32	i;

	frametimesindex = fps->framecount % FRAME_VALUES;
	getticks = SDL_GetTicks();
	fps->frametimes[frametimesindex] = getticks - fps->frametimelast;
	fps->frametimelast = getticks;
	fps->framecount++;
	if (fps->framecount < FRAME_VALUES)
		count = fps->framecount;
	else
		count = FRAME_VALUES;
	fps->framespersecond = 0;
	i = 0;
	while (i < count)
		fps->framespersecond += fps->frametimes[i++];
	fps->framespersecond /= count;
	fps->framespersecond = 1000.f / fps->framespersecond;
}
