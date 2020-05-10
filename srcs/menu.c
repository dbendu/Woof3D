/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: konsolka <konsolka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 14:23:33 by konsolka          #+#    #+#             */
/*   Updated: 2020/05/10 12:19:59 by konsolka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <SDL2/SDL_image.h>
#include "data.h"
#include "WoofDefines.h"
#include "button.h"
#include "font.h"
#include "Woof3D.h"
#include "main_menu.h"

void drawMenu(t_data *data)
{
	int		buttonPressed;

	SDL_SetRenderDrawColor(data->wnd.renderer, 0x00, 0x00, 0x00, 0xff);
	SDL_RenderClear(data->wnd.renderer);
	buttonPressed = SDL_GetMouseState(&data->menu.mouse.cursor.x, &data->menu.mouse.cursor.y);
	data->menu.mouse.tip.x = data->menu.mouse.cursor.x;
	data->menu.mouse.tip.y = data->menu.mouse.cursor.y;
	if (data->map.map)
		buttonDraw(data, &data->menu.button[Continue_button], setColor(45, 138, 41, 255), buttonPressed);
	renderButtons(data, data->menu.button, buttonPressed);
	drawMouse(*data, data->menu.mouse);
	SDL_RenderPresent(data->wnd.renderer);
}