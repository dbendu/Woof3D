/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_menu.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburl <mburl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 15:12:56 by mburl             #+#    #+#             */
/*   Updated: 2020/06/29 15:23:04 by mburl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SDL_MENU_H
# define SDL_MENU_H

# include <SDL2/SDL.h>
# include <stdbool.h>
# include "button.h"

typedef struct s_menu*	t_menu;

t_menu		menu_create(SDL_Renderer *render, bool cycling);
void		menu_destroy(t_menu menu);

void		menu_add_button(t_menu menu, t_button button);
void		menu_select_button(t_menu menu, int32_t button_uid);
void		menu_select_next(t_menu menu);
void		menu_select_prev(t_menu menu);
int32_t		menu_selected_uid(t_menu menu);

bool		check_hover(t_button button, SDL_Rect *rect,
							int press, t_menu menu);
bool		menu_draw(t_menu menu);

#endif
