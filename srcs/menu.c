/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: konsolka <konsolka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 14:23:33 by konsolka          #+#    #+#             */
/*   Updated: 2020/05/05 15:37:30 by konsolka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <SDL2/SDL_image.h>
#include "data.h"
#include "WoofDefines.h"
#include "main_menu.h"
#include "button.h"
#include "font.h"
#include "Woof3D.h"

t_menu		menuInit(t_data data)
{
	t_menu	menu;

	menu.textureButton = IMG_LoadTexture(data.wnd.renderer, "res/textures/buttons.png");
	menu.button[Start_button] = initButton(data, 0, 0);
	menu.button[Options_button] = initButton(data, 0, 150);
	menu.button[Exit_button] = initButton(data, 0, 300);
	menu.button[Start_button].dRect = setButton(menu.button[Start_button], WND_WIDTH / 2 - 150, WND_HEIGHT / 2 - 180);
	menu.button[Options_button].dRect = setButton(menu.button[Options_button], WND_WIDTH / 2 - 150, WND_HEIGHT / 2);
	menu.button[Exit_button].dRect = setButton(menu.button[Exit_button], WND_WIDTH / 2 - 150, WND_HEIGHT / 2 + 180);
	menu.mouse = mouseInit(data);
	return (menu);
}

void drawMenu(t_data *data)
{
	int		buttonPressed;
	SDL_Rect	rect;
	t_font	font;
	SDL_Color	col;

	SDL_SetRenderDrawColor(data->wnd.renderer, 0x00, 0x00, 0x00, 0xff);
	col.a = 255;
	col.b = 0;
	col.g = 0;
	col.r = 255;
	font = fontInit(*data, 72, "KEK", col);
	SDL_RenderClear(data->wnd.renderer);
	// fontDraw(*data, font, 0, 0);
	rect.h = 150;
	rect.w = 300;
	rect.x = 200;
	rect.y = 200;
	buttonDraw(*data, font, rect, setColor(255, 255, 255, 255));
	buttonPressed = SDL_GetMouseState(&data->menu.mouse.cursor.x, &data->menu.mouse.cursor.y);
	data->menu.mouse.tip.x = data->menu.mouse.cursor.x;
	data->menu.mouse.tip.y = data->menu.mouse.cursor.y;
	drawButton(data, Start_button, buttonPressed);
	drawButton(data, Options_button, buttonPressed);
	drawButton(data, Exit_button, buttonPressed);
	drawMouse(*data);
	SDL_RenderPresent(data->wnd.renderer);
}