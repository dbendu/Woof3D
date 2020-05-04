/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   button.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: konsolka <konsolka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 13:56:09 by konsolka          #+#    #+#             */
/*   Updated: 2020/05/04 20:59:00 by konsolka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <SDL2/SDL_image.h>
#include "Woof3D.h"
#include "data.h"
#include "button.h"


void		checkSelected(t_data *data, int buttonPressed, int press)
{
	data->menu.button[buttonPressed];
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