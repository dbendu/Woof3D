/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburl <mburl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 23:46:33 by user              #+#    #+#             */
/*   Updated: 2020/08/04 15:59:24 by mburl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "initialization/init_all.h"

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

t_minimap	minimap_init(void)
{
	t_minimap	minimap;

	minimap.surface = SDL_CreateRGBSurface(0, MINIMAP_SZ, MINIMAP_SZ, 32,
											RMASK, GMASK, BMASK, AMASK);
	if (minimap.surface == NULL)
		ft_error(SDL_GetError(), "woof_init/minimap_init", 0);
	minimap.viewport.x = WND_WIDTH - MINIMAP_SZ;
	minimap.viewport.y = 0;
	minimap.viewport.h = MINIMAP_SZ;
	minimap.viewport.w = MINIMAP_SZ;
	minimap.show = true;
	return (minimap);
}
