/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburl <mburl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 08:05:41 by mburl             #+#    #+#             */
/*   Updated: 2020/08/04 08:19:19 by mburl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "woof3d.h"
#include "sdl_menu.h"
#include "libft.h"

t_position	update_position(int key, int mult, int rot)
{
	t_position	hero_pos;

	int mult = data->keyboard.key[RUN] ? 4 : 2;
	float new_fx = data->map.hero.position.x + mult * cos(to_rad(data->map.hero.pov));
	float new_fy = data->map.hero.position.y - mult * sin(to_rad(data->map.hero.pov));
	int old_x = data->map.hero.position.x / CELL_SIZE;
	int old_y = data->map.hero.position.y / CELL_SIZE;
	int new_x = new_fx / CELL_SIZE;
	int new_y = new_fy / CELL_SIZE;
	if (data->map.map[old_y][new_x].wall == false)
		data->map.hero.position.x = new_fx;
	if (data->map.map[new_y][old_x].wall == false)
		data->map.hero.position.y = new_fy;
}

void	update(t_data *data)
{
	int		xrel;
	int		yrel;

	if (data->keyboard.key[MOVE_FORWARD]) {
		int mult = data->keyboard.key[RUN] ? 4 : 2;
		float new_fx = data->map.hero.position.x + mult * cos(to_rad(data->map.hero.pov));
		float new_fy = data->map.hero.position.y - mult * sin(to_rad(data->map.hero.pov));
		int old_x = data->map.hero.position.x / CELL_SIZE;
		int old_y = data->map.hero.position.y / CELL_SIZE;
		int new_x = new_fx / CELL_SIZE;
		int new_y = new_fy / CELL_SIZE;
		if (data->map.map[old_y][new_x].wall == false) {
			data->map.hero.position.x = new_fx;
		}
		if (data->map.map[new_y][old_x].wall == false) {
			data->map.hero.position.y = new_fy;
		}
	}
	if (data->keyboard.key[MOVE_BACK]) {
		float new_fx = data->map.hero.position.x - cos(to_rad(data->map.hero.pov));
		float new_fy = data->map.hero.position.y + sin(to_rad(data->map.hero.pov));
		int old_x = data->map.hero.position.x / CELL_SIZE;
		int old_y = data->map.hero.position.y / CELL_SIZE;
		int new_x = new_fx / CELL_SIZE;
		int new_y = new_fy / CELL_SIZE;
		if (data->map.map[old_y][new_x].wall == false) {
			data->map.hero.position.x = new_fx;
		}
		if (data->map.map[new_y][old_x].wall == false) {
			data->map.hero.position.y = new_fy;
		}
	}
	if (data->keyboard.key[TURN_LEFT])
	{
		float new_fx = data->map.hero.position.x - cos(to_rad(data->map.hero.pov - 90));
		float new_fy = data->map.hero.position.y + sin(to_rad(data->map.hero.pov - 90));
		int old_x = data->map.hero.position.x / CELL_SIZE;
		int old_y = data->map.hero.position.y / CELL_SIZE;
		int new_x = new_fx / CELL_SIZE;
		int new_y = new_fy / CELL_SIZE;
		if (data->map.map[old_y][new_x].wall == false) {
			data->map.hero.position.x = new_fx;
		}
		if (data->map.map[new_y][old_x].wall == false) {
			data->map.hero.position.y = new_fy;
		}
	}
	if (data->keyboard.key[TURN_RIGHT])
	{
		float new_fx = data->map.hero.position.x - cos(to_rad(data->map.hero.pov + 90));
		float new_fy = data->map.hero.position.y + sin(to_rad(data->map.hero.pov + 90));
		int old_x = data->map.hero.position.x / CELL_SIZE;
		int old_y = data->map.hero.position.y / CELL_SIZE;
		int new_x = new_fx / CELL_SIZE;
		int new_y = new_fy / CELL_SIZE;
		if (data->map.map[old_y][new_x].wall == false) {
			data->map.hero.position.x = new_fx;
		}
		if (data->map.map[new_y][old_x].wall == false) {
			data->map.hero.position.y = new_fy;
		}
	}
	SDL_GetRelativeMouseState(&xrel, &yrel);
	data->map.hero.pov -= xrel;
	if (data->map.hero.pov >= 360)
		data->map.hero.pov -= 360;
	else if (data->map.hero.pov <= 360)
		data->map.hero.pov += 360;
}
