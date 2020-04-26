/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/26 10:58:46 by user              #+#    #+#             */
/*   Updated: 2020/04/26 12:25:58 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphic_utils.h"
#include "libft.h"

#if SDL_BYTEORDER == SDL_BIG_ENDIAN
# define RMASK	0xff000000
# define GMASK	0x00ff0000
# define BMASK	0x0000ff00
# define AMASK	0x000000ff
#else
# define RMASK	0x000000ff
# define GMASK	0x0000ff00
# define BMASK	0x00ff0000
# define AMASK	0xff000000
#endif

SDL_Surface	*sdl_create_surface(int width, int height)
{
	SDL_Surface	*surface;

	surface = SDL_CreateRGBSurface(0, width, height, 32,
							RMASK, GMASK, BMASK, AMASK);
	if (surface == NULL)
		ft_error(SDL_GetError(), "sdl_create_surface", 0);
	return (surface);
}
