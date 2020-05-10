/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: konsolka <konsolka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/10 07:15:44 by konsolka          #+#    #+#             */
/*   Updated: 2020/05/10 08:11:58 by konsolka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <SDL2/SDL.h>
#include "WoofDefines.h"
#include "data.h"
#include "Woof3D.h"
#include "options.h"
#include "button.h"

t_options		initOptions(t_data data)
{
	t_options		options;
	int				i;
	SDL_Rect		rect;

	i = 0;
	rect = setRect(WND_WIDTH / 4 - 100, WND_HEIGHT / 4, 200, 100);
	options.controlButton = (t_optionButton *)malloc(sizeof(t_optionButton));
	options.messageButton = (t_optionButton *)malloc(sizeof(t_optionButton));
	options.messageButton->button = startButtonsInit(data, 4,
			buttonInitData(rect, xyInit(1, 1), 0),
				"move forward",
				"move left",
				"move right",
				"move back");
	rect.x = WND_WIDTH * 3 / 4 - 100;
	rect.w = 100;
	rect.h = 100;
	options.controlButton->button = startButtonsInit(data, 4, buttonInitData(rect, xyInit(1, 1), 0), "w", "a", "d", "s");
	while (i < 4)
	{
		options.messageButton->id = i;
		options.controlButton->id = i;
		i++;
	}
	return (options);
}


void	drawOptions(t_data *data)
{
	int		buttonPressed;

	SDL_SetRenderDrawColor(data->wnd.renderer, 0x00, 0x00, 0x00, 0xff);
	SDL_RenderClear(data->wnd.renderer);
	buttonPressed = SDL_GetMouseState(&data->menu.mouse.cursor.x, &data->menu.mouse.cursor.y);
	data->menu.mouse.tip.x = data->menu.mouse.cursor.x;
	data->menu.mouse.tip.y = data->menu.mouse.cursor.y;
	renderButtons(data, data->options.messageButton->button, 0);
	renderButtons(data, data->options.controlButton->button, 0);
	drawMouse(*data);
	SDL_RenderPresent(data->wnd.renderer);

}