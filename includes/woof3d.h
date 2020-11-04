/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   woof3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburl <mburl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/25 17:28:08 by user              #+#    #+#             */
/*   Updated: 2020/11/04 14:32:36 by mburl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOOF3D_H
# define WOOF3D_H

# include "structs/data.h"
# include "woofdefines.h"
# include "structs/hero.h"

t_data		woof_init(const char *filename);
void		woof_quit(t_data *data);

void		draw(t_data *data);

t_ray		*raycast(float pov, t_position start, t_vector_point *map);

void		main_menu_cycle(t_data *data);
void		game_cycle(t_data *data);
void		pause_cycle(t_data *data);
SDL_Color	init_sdl_color(int r, int g, int b, int a);
void		update(t_data *data);
void		draw_map(SDL_Renderer *render,
							t_position start, t_vector_point *map);
void		draw_rays(SDL_Renderer *render, t_ray *rays, t_position start);
void		handle_key_press(t_keyboard *keyboard, SDL_Keycode key);
void		handle_key_release(t_keyboard *keyboard, SDL_Keycode key);
void		draw_vis(t_wnd *sdl, t_ray *rays, t_point **map);
int			check_vals(int a, int b, t_point **map);
void		ft_putchar(char c);
void		ft_putnbr(int n);

#endif
