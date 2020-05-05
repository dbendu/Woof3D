/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   button.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: konsolka <konsolka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 13:52:16 by konsolka          #+#    #+#             */
/*   Updated: 2020/05/05 18:47:28 by konsolka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUTTON_H
# define BUTTON_H

# include <SDL2/SDL.h>
# include <stdbool.h>
# include "WoofDefines.h"
# include "data.h"
# include "font.h"

enum buttonName {Continue_button, Start_button, Options_button, Exit_button, Menu_button};

typedef struct	s_button
{
	t_font		font;
	SDL_Rect	dRect;
	int			state;
}				t_button;

t_button	initButton(t_data data, int x, int y);
SDL_Rect	setButton(t_button button, int x, int y);
void		drawButton(t_data *data, int buttonPressed, int press);
t_button	*startButtonsInit(t_data data, int size, ...);
void		buttonDraw(t_data *data, t_button button, SDL_Color col, int press);

#endif