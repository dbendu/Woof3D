/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interface_draw.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/26 11:44:03 by user              #+#    #+#             */
/*   Updated: 2020/04/26 11:47:02 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "interface.h"

void				interface_draw(const t_interface *interface,
									SDL_Renderer *renderer)
{
	SDL_Texture	*texture;

	texture = SDL_CreateTextureFromSurface(renderer, interface->surface);
	SDL_RenderSetViewport(renderer, &interface->viewport);
	SDL_RenderCopy(renderer, texture, NULL, NULL);
	SDL_RenderPresent(renderer);
	SDL_DestroyTexture(texture);
}
