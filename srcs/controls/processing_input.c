/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processing_input.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/26 15:32:17 by user              #+#    #+#             */
/*   Updated: 2020/04/27 01:40:19 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Woof_defines.h"
#include "controls_utils.h"

// void	processing_input(t_data *data)
// {
// 	if (!(data->keyboard.move_back ^ data->keyboard.move_forvard))
// 		return ;
// 	float	new_absolute_x;
// 	float	new_absolute_y;
// 	if (data->keyboard.move_forvard)
// 	{
// 		new_absolute_x = data->map.hero.absolute_position.x + cos(data->map.hero.pov * 3.14 / 180);
// 		new_absolute_y = data->map.hero.absolute_position.y + sin(data->map.hero.pov * 3.14 / 180);
// 	}
// 	else
// 	{
// 		new_absolute_x = data->map.hero.absolute_position.x - cos(data->map.hero.pov * 3.14 / 180) / 2; // slowly than face forward
// 		new_absolute_y = data->map.hero.absolute_position.y - sin(data->map.hero.pov * 3.14 / 180) / 2;
// 	}
// 	const int	new_relative_x = new_absolute_x / CELL_SIZE;
// 	const int	new_relative_y = new_absolute_y / CELL_SIZE;

// 	if (!data->map.map[new_relative_y][data->map.hero.relative_position.x].wall)
// 	{
// 		data->map.hero.relative_position.y = new_relative_y;
// 		data->map.hero.absolute_position.y = new_absolute_y;
// 	}
// 	if (!data->map.map[data->map.hero.relative_position.y][new_relative_x].wall)
// 	{
// 		data->map.hero.relative_position.x = new_relative_x;
// 		data->map.hero.absolute_position.x = new_absolute_x;
// 	}



// 	// printf("%f - %f\n", data->map.hero.absolute_position.y, data->map.hero.absolute_position.x);
// 	(void)data;
// }
