/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: konsolka <konsolka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 23:46:33 by user              #+#    #+#             */
/*   Updated: 2020/05/10 12:27:06 by konsolka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <SDL2/SDL.h>

#include "WoofDefines.h"
#include "Woof3D.h"
#include "mouse.h"
#include "minimap.h"
#include "ft_utils.h"

t_minimap	minimap_init(t_data data)
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
	minimap.playerTex = mouseInit(data, "res/textures/player.png", 15, 15);
	return (minimap);
}
