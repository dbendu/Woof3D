/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   button.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: konsolka <konsolka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 13:56:09 by konsolka          #+#    #+#             */
/*   Updated: 2020/05/05 18:42:32 by konsolka         ###   ########.fr       */
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
#include <stdarg.h>

SDL_Color		checkSelected(t_data *data, t_button button, SDL_Color col, int press)
{
	Uint8		temp;
	if (SDL_HasIntersection(&data->menu.mouse.tip, &button.dRect))
	{
		temp = col.r;
		col.r = col.g;
		col.g = col.b;
		col.b = temp;
		if (press == 1)
			data->gameState = button.state;
	}
	return (col);
}



void		buttonDraw(t_data *data, t_button button, SDL_Color col, int press)
{
	SDL_Surface	*surf;
	SDL_Texture	*texture;
	SDL_Rect	rect_cpy;

	col = checkSelected(data, button, col, press);
	SDL_SetRenderDrawColor(data->wnd.renderer, col.r, col.g, col.b, col.a);
	SDL_RenderFillRect(data->wnd.renderer, &button.dRect);
	SDL_SetRenderDrawColor(data->wnd.renderer, col.b, col.r, col.g, col.a);
	rect_cpy.h = button.dRect.h - button.dRect.h / 10;
	rect_cpy.w = button.dRect.w - button.dRect.w / 10;
	rect_cpy.x = button.dRect.x + button.dRect.w / 20;
	rect_cpy.y = button.dRect.y + button.dRect.h / 20;
	SDL_RenderFillRect(data->wnd.renderer, &rect_cpy);
	SDL_SetRenderDrawColor(data->wnd.renderer, 0x00, 0x00, 0x00, 0xff);
	SDL_RenderCopy(data->wnd.renderer, button.font.text_texture, NULL, &rect_cpy);
}

SDL_Rect	setButton(t_button button, int x, int y)
{
	SDL_Rect	rect;

	rect = button.dRect;
	rect.x = x;
	rect.y = y;
	return (rect);
}

t_button	*startButtonsInit(t_data data, int size, ...)
{
	t_button	*but;
	int			i;
	va_list		ap;
	char		*s;

	i = 0;
	but = (t_button *)malloc(sizeof(t_button) * size);
	va_start(ap, size);
	while (i < size)
	{
		s = va_arg(ap, char *);
		but[i].font = fontInit(data, 100, s, setColor(255, 255, 255, 255));
		but[i].dRect.h = 100;
		but[i].dRect.w = 200;
		but[i].dRect.x = WND_WIDTH / 2 - but[i].dRect.w / 2;
		but[i].dRect.y = WND_HEIGHT / 4 + but[i].dRect.h * i + 10 * i;
		but[i].state = i;
		i++;
	}
	va_end(ap);
	
	return (but);
}