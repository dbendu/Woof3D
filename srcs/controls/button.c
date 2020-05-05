/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   button.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: konsolka <konsolka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 13:56:09 by konsolka          #+#    #+#             */
/*   Updated: 2020/05/05 15:43:09 by konsolka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Woof3D.h"
#include "WoofDefines.h"
#include "data.h"
#include "font.h"
#include "button.h"
#include "point.h"
#include "libft.h"

void		checkSelected(t_data *data, int buttonPressed, int press)
{
	if (SDL_HasIntersection(&data->menu.mouse.tip, &data->menu.button[buttonPressed].dRect))
	{
		data->menu.button[buttonPressed].selected = true;
		data->menu.button[buttonPressed].sRect.x = 300;
		if (press == 1)
			data->gameState = buttonPressed;
	}
	else
	{
		data->menu.button[buttonPressed].selected = false;
		data->menu.button[buttonPressed].sRect.x = 0;
	}
}



void		buttonDraw(t_data data, t_font font, SDL_Rect dest_rect, SDL_Color col)
{
	SDL_Surface	*surf;
	SDL_Texture	*texture;
	// SDL_Rect	rect2;

	// surf = SDL_CreateRGBSurface(0, dest_rect.h, dest_rect.w, 32,
	// 										RMASK, GMASK, BMASK, AMASK);
	SDL_SetRenderDrawColor(data.wnd.renderer, 0xff, 0xff, 0xff, 0xff);
	SDL_RenderFillRect(data.wnd.renderer, &dest_rect);
	SDL_SetRenderDrawColor(data.wnd.renderer, 0x00, 0x00, 0x00, 0xff);
	
	// SDL_FillRect(surf, &dest_rect, SDL_MapRGBA(surf->format, col.r, col.g, col.b, col.a));
	// texture = SDL_CreateTextureFromSurface(data.wnd.renderer, surf);
	// if (SDL_RenderCopy(data.wnd.renderer, texture, NULL, &dest_rect) < 0)
	// 	ft_error(SDL_GetError(), "SDL_RenderCopy", 0);
	font.rect.x = dest_rect.x + font.rect.w / 2;
	font.rect.y = dest_rect.y + font.rect.h / 2;
	SDL_RenderCopy(data.wnd.renderer, font.text_texture, NULL, &font.rect);
	// SDL_FreeSurface(surf);
}

t_button	initButton(t_data data, int x, int y)
{
	t_button	b;

	b.selected = false;
	b.sRect.x = x;
	b.sRect.y = y;
	b.sRect.w = 300;
	b.sRect.h = 150;
	b.dRect.x = x;
	b.dRect.y = y;
	b.dRect.w = 300;
	b.dRect.h = 150;
	b.texture = data.menu.textureButton;
	return (b);
}	

SDL_Rect	setButton(t_button button, int x, int y)
{
	SDL_Rect	rect;

	rect = button.dRect;
	rect.x = x;
	rect.y = y;
	return (rect);
}

void	drawButton(t_data *data, int buttonPressed, int press)
{
	checkSelected(data, buttonPressed, press);
	SDL_RenderCopy(data->wnd.renderer, data->menu.textureButton,
		&data->menu.button[buttonPressed].sRect, &data->menu.button[buttonPressed].dRect);
}