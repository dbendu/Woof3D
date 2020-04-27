/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/26 15:30:39 by user              #+#    #+#             */
/*   Updated: 2020/04/27 02:15:50 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"
#include "controls_utils.h"

void	key_pressed(t_data *data, SDL_Keycode button)
{
	if (button == SDLK_a)
		data->keyboard.key[0] = true;
	else if (button == SDLK_w)
		data->keyboard.key[1] = true;
	else if (button == SDLK_d)
		data->keyboard.key[2] = true;
	else if (button == SDLK_s)
		data->keyboard.key[3] = true;
	else if (button == 'q' && data->map.hero.fov >= 30)
		data->map.hero.fov -= 1;
	else if (button == 'e' && data->map.hero.fov < 170)
		data->map.hero.fov += 1;
	else if (button == SDLK_m)
		data->wnd.minimap.show = !data->wnd.minimap.show;
	else if (button == SDLK_ESCAPE)
		data->quit = true;
	if (data->map.hero.pov >= 360 || data->map.hero.pov <= -360)
		data->map.hero.pov = 0;
}

void			key_release(t_data *data, SDL_Keycode button)
{
	if (button == SDLK_a)
		data->keyboard.key[0] = false;
	else if (button == SDLK_w)
		data->keyboard.key[1] = false;
	else if (button == SDLK_d)
		data->keyboard.key[2] = false;
	else if (button == SDLK_s)
		data->keyboard.key[3] = false;
}