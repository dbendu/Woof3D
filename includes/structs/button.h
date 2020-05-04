/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   button.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: konsolka <konsolka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 13:52:16 by konsolka          #+#    #+#             */
/*   Updated: 2020/05/04 20:50:04 by konsolka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUTTON_H
# define BUTTON_H

# include <SDL2/SDL.h>
# include <stdbool.h>
# include "WoofDefines.h"
# include "data.h"

enum buttonName {Start_button, Options_button, Exit_button, Menu};

typedef struct	s_button
{
	SDL_Rect	sRect;
	SDL_Rect	dRect;
	bool		selected;
	SDL_Texture	*texture;
}				t_button;

t_button	initButton(t_data data, int x, int y);
SDL_Rect	setButton(t_button button, int x, int y);
void		drawButton(t_data *data, int buttonPressed, int press);

#endif