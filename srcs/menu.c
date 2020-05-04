/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: konsolka <konsolka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 14:23:33 by konsolka          #+#    #+#             */
/*   Updated: 2020/05/04 17:50:01 by konsolka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <SDL2/SDL_image.h>
#include "data.h"
#include "WoofDefines.h"
#include "main_menu.h"
#include "button.h"

t_menu		menuInit(t_data data)
{
	t_menu	menu;

	menu.textureButton = IMG_LoadTexture(data.wnd.renderer, "textures/buttons.png");
	menu.button[Start_button] = initButton(data, 0, 0);
	menu.button[Options_button] = initButton(data, 0, 150);
	menu.button[Exit_button] = initButton(data, 0, 300);
	menu.button[Start_button].dRect = setButton(menu.button[Start_button], WND_WIDTH / 2 - 150, WND_HEIGHT / 2 - 180);
	menu.button[Options_button].dRect = setButton(menu.button[Options_button], WND_WIDTH / 2 - 150, WND_HEIGHT / 2);
	menu.button[Exit_button].dRect = setButton(menu.button[Exit_button], WND_WIDTH / 2 - 150, WND_HEIGHT / 2 + 180);
	menu.mouse = mouseInit(data);
	return (menu);
}

void drawMenu(t_data data)
{
	int		x;
	int		y;

	SDL_RenderClear(data.wnd.renderer);
	SDL_GetMouseState(&data.menu.mouse.cursor.x, &data.menu.mouse.cursor.y);
	data.menu.mouse.tip.x = data.menu.mouse.cursor.x;
	data.menu.mouse.tip.y = data.menu.mouse.cursor.y;
	drawButton(data, data.menu.button[Start_button]);
	drawButton(data, data.menu.button[Options_button]);
	drawButton(data, data.menu.button[Exit_button]);
	drawMouse(data);
	SDL_RenderPresent(data.wnd.renderer);
}