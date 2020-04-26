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

void	key_release(t_data *data, SDL_Keycode button)
{
	if (button == 'w')
		data->keyboard.move_forvard = false;
	else if (button == 's')
		data->keyboard.move_back = false;
}

void	key_pressed(t_data *data, SDL_Keycode button)
{
	if (button == 'w')
		data->keyboard.move_forvard = true;
	else if (button == 's')
		data->keyboard.move_back = true;
	else if (button == 'd')
		data->map.hero.pov += 1;
	else if (button == 'a')
		data->map.hero.pov -= 1;
	else if (button == 'q' && data->map.hero.fov >= 30)
		data->map.hero.fov -= 1;
	else if (button == 'e' && data->map.hero.fov < 170)
		data->map.hero.fov += 1;
	else if (button == SDLK_m)
		data->wnd.minimap.show = !data->wnd.minimap.show;
	if (data->map.hero.pov >= 360 || data->map.hero.pov <= -360)
		data->map.hero.pov = 0;
	processing_input(data);
}
