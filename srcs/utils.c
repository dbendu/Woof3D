/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: konsolka <konsolka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 14:44:43 by konsolka          #+#    #+#             */
/*   Updated: 2020/05/07 16:57:52 by konsolka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SDL2/SDL.h"
#include "point.h"

SDL_Color	setColor(int r, int g, int b, int a)
{
	SDL_Color	color;

	color.r = r;
	color.g = g;
	color.b = b;
	color.a = a;
	return (color);
}

t_point_xy	xyInit(int x, int y)
{
	t_point_xy	xy;

	xy.x = x;
	xy.y = y;
	return (xy);
}

SDL_Rect	setRect(int x, int y, int w, int h)
{
	SDL_Rect	rect;

	rect.x = x;
	rect.y = y;
	rect.w = w;
	rect.h = h;
	return (rect);
}
// int32_t    pack_color(int alpha, int red, int green, int blue)
// {
//     return ((alpha << 24) | (red << 16) | (green << 8) | blue);
// }
