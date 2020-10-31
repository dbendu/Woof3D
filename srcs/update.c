/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburl <mburl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 08:05:41 by mburl             #+#    #+#             */
/*   Updated: 2020/08/04 16:00:32 by mburl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "woof3d.h"
#include "menu/sdl_menu.h"
#include "libft.h"

void	update_position(t_data *data, int mult, int rot)
{
	float		new_fx;
	float		new_fy;

	new_fx = data->map.hero.position.x + mult *
		cos(to_rad(data->map.hero.pov + rot));
	new_fy = data->map.hero.position.y - mult *
		sin(to_rad(data->map.hero.pov + rot));
	if (data->map.map[(int)(data->map.hero.position.y / CELL_SIZE)]
			[(int)(new_fx / CELL_SIZE)].wall == false)
		data->map.hero.position.x = new_fx;
	if (data->map.map[(int)(new_fy / CELL_SIZE)]
			[(int)(data->map.hero.position.x / CELL_SIZE)].wall == false)
		data->map.hero.position.y = new_fy;
}

void	update(t_data *data)
{
	int		xrel;
	int		yrel;

	if (data->actions.move_forward) {
		if (data->actions.sonic_mode) {
			update_position(data, 16, 0);
		} else if (data->actions.run) {
			update_position(data, 4, 0);
		} else {
			update_position(data, 2, 0);
		}
	}
	if (data->actions.move_back)
		update_position(data, -2, 0);
	if (data->actions.move_left)
		update_position(data, -1, -90);
	if (data->actions.move_right)
		update_position(data, -1, 90);
	SDL_GetRelativeMouseState(&xrel, &yrel);
	data->map.hero.pov -= xrel % 360;
	if (data->map.hero.pov >= 360)
		data->map.hero.pov -= 360;
	else if (data->map.hero.pov <= 360)
		data->map.hero.pov += 360;
}
