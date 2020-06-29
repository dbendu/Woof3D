/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Woof3D.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburl <mburl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/25 17:28:08 by user              #+#    #+#             */
/*   Updated: 2020/06/29 15:26:02 by mburl            ###   ########.fr       */
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

void	main_menu_cycle(t_data *data);
void	game_cycle(t_data *data);
void	pause_cycle(t_data *data);
SDL_Color init_SDL_Color(int r, int g, int b, int a);

#endif
