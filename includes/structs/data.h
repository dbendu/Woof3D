/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/26 12:44:06 by user              #+#    #+#             */
/*   Updated: 2020/06/14 22:38:41 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_H
# define DATA_H

# include <SDL2/SDL_ttf.h>
# include <stdbool.h>
# include "keyboard.h"
# include "minimap.h"
# include "wnd.h"
# include "map.h"
# include "ray.h"
# include "sdl_menu.h"

typedef struct		s_menus
{
	TTF_Font		*big;
	t_menu			main;
	t_menu			pause;
	t_menu			settings;
}					t_menus;

#define MAIN_MENU_BUTTONS	3
#define PAUSE_MENU_BUTTONS	3

#define BUTTON_GAME			0
#define BUTTON_SETTINGS		1
#define BUTTON_EXIT			2
#define BUTTON_CONTINUE		3
#define BUTTON_TO_MAIN		4

typedef struct		s_jumps
{
	bool			exit;
	bool			to_main;
	bool			to_game;
}					t_jumps;

typedef struct		s_data
{
	t_wnd			wnd;
	t_keyboard		keyboard;
	t_map			map;
	t_minimap		minimap;
	t_menus			menus;
	t_jumps			jumps;
	bool			quit;
}					t_data;

#endif
