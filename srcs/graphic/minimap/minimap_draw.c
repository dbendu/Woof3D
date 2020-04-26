/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_draw.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/26 11:32:08 by user              #+#    #+#             */
/*   Updated: 2020/04/26 11:36:57 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minimap.h"

void		minimap_draw(const t_minimap *minimap, SDL_Renderer *renderer)
{
	SDL_Texture	*texture;

	texture = SDL_CreateTextureFromSurface(renderer, minimap->surface);
	SDL_RenderSetViewport(renderer, &minimap->viewport);
	SDL_RenderCopy(renderer, texture, NULL, NULL);
	SDL_RenderPresent(renderer);
	SDL_DestroyTexture(texture);
}
