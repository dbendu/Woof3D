/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   button.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: konsolka <konsolka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 13:52:16 by konsolka          #+#    #+#             */
/*   Updated: 2020/05/10 07:41:17 by konsolka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUTTON_WOOF_H
# define BUTTON_WOOF_H

# include <SDL2/SDL.h>
# include <stdbool.h>
# include "data.h"
# include "WoofDefines.h"
# include "font.h"

enum buttonName {Continue_button, Start_button, Options_button, Exit_button,
	Menu_button, Update_button};

typedef struct	s_button
{
	t_font		font;
	SDL_Rect	dRect;
	char		*name;
	int			state;
	bool		selected;
	struct s_button	*next;
}				t_button;

typedef struct	s_buttonInit
{
	SDL_Rect	rect;
	t_point_xy	shift;
	bool		map;
}				t_buttonInit;

t_button	initButton(t_data data, int x, int y);
SDL_Rect	setButton(t_button button, int x, int y);
void		buttonDraw(t_data *data, t_button *button, SDL_Color col, int press);
t_buttonInit	buttonInitData(SDL_Rect rect, t_point_xy shift, bool map);
t_button	*startButtonsInit(t_data data, int size, t_buttonInit init, ...);
void		renderButtons(t_data *data, t_button *button, int buttonPress);

#endif