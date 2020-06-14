/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Woof3D.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/25 17:28:08 by user              #+#    #+#             */
/*   Updated: 2020/06/14 22:35:43 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOOF3D_h
# define WOOF3D_h

# include "data.h"
# include "WoofDefines.h"

t_data	woof_init(const char *filename);
void	woof_quit(t_data *data);

void	playerUpdate(t_data *data, t_hero *hero);
void	draw(t_data *data);

t_ray	*raycast(int fov, float pov, t_position start, t_vector_point *map);
void	mouseCapture(t_data *data, SDL_MouseMotionEvent mouse);

void	main_menu_cycle(t_data *data);
void	game_cycle(t_data *data);
void	pause_cycle(t_data *data);
// void	settings_cycle(t_data *data);

#endif
