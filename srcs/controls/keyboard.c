/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: konsolka <konsolka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/26 15:30:39 by user              #+#    #+#             */
/*   Updated: 2020/04/28 10:20:37 by konsolka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"
#include "Woof_defines.h"
#include "controls_utils.h"

void	key_pressed(t_data *data, SDL_Keycode button)
{
	if (button == 'w')
		data->keyboard.key[MOVE_FORWARD] = true;
	else if (button == 's')
		data->keyboard.key[MOVE_BACK] = true;
	else if (button == 'a')
		data->keyboard.key[TURN_LEFT] = true;
	else if (button == 'd')
		data->keyboard.key[TURN_RIGHT] = true;
	else if (button == 'q')
		data->keyboard.key[FOV_DECREASE] = true;
	else if (button == 'e')
		data->keyboard.key[FOV_INCREASE] = true;
	else if (button == 'm')
		data->wnd.minimap.show = !data->wnd.minimap.show;
	else if (button == SDLK_ESCAPE)
		data->quit = true;
	else if (button == SDLK_LSHIFT)
		data->map.hero.speed = HERO_RUN_SPEED;
}

void			key_release(t_data *data, SDL_Keycode button)
{
	if (button == 'w')
		data->keyboard.key[MOVE_FORWARD] = false;
	else if (button == 's')
		data->keyboard.key[MOVE_BACK] = false;
	if (button == 'a')
		data->keyboard.key[TURN_LEFT] = false;
	else if (button == 'd')
		data->keyboard.key[TURN_RIGHT] = false;
	else if (button == 'q')
		data->keyboard.key[FOV_DECREASE] = false;
	else if (button == 'e')
		data->keyboard.key[FOV_INCREASE] = false;
	else if (button == SDLK_LSHIFT)
		data->map.hero.speed = HERO_STEP_SPEED;
}
