/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: konsolka <konsolka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 14:44:43 by konsolka          #+#    #+#             */
/*   Updated: 2020/05/05 14:45:59 by konsolka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SDL2/SDL.h"

SDL_Color	setColor(int r, int g, int b, int a)
{
	SDL_Color	color;

	color.r = r;
	color.g = g;
	color.b = b;
	color.a = a;
	return (color);
}

// int32_t    pack_color(int alpha, int red, int green, int blue)
// {
//     return ((alpha << 24) | (red << 16) | (green << 8) | blue);
// }
