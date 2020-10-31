/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburl <mburl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/26 12:44:06 by user              #+#    #+#             */
/*   Updated: 2020/08/04 16:02:49 by mburl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_H
# define DATA_H

# include <SDL2/SDL_ttf.h>
# include <stdbool.h>
#include "actions.h"
# include "controls/keyboard.h"
# include "graphic/minimap.h"
# include "graphic/wnd.h"
# include "structs/map.h"
# include "structs/ray.h"
# include "menu/sdl_menu.h"

typedef struct		s_menus
{
	TTF_Font		*big;
	t_menu			main;
	t_menu			pause;
}					t_menus;

# define MAIN_MENU_BUTTONS	3
# define PAUSE_MENU_BUTTONS	3

# define BUTTON_GAME			0
# define BUTTON_SETTINGS		1
# define BUTTON_EXIT			2
# define BUTTON_CONTINUE		3
# define BUTTON_TO_MAIN			4

typedef struct		s_data
{
	t_wnd			wnd;
	t_keyboard		keyboard;
	t_actions		actions;
	t_map			map;
	t_minimap		minimap;
	t_menus			menus;
}					t_data;

#endif
