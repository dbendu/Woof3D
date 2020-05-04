/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_menu.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: konsolka <konsolka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 02:18:20 by konsolka          #+#    #+#             */
/*   Updated: 2020/05/04 20:37:50 by konsolka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_MENU_H
# define MAIN_MENU_H

# include <SDL2/SDL.h>
# include "data.h"
# include "button.h"
# include "mouse.h"

typedef struct	s_menu
{
	SDL_Texture		*textureButton;
	t_button		button[3];
	t_mouse			mouse;
}				t_menu;

t_menu		menuInit(t_data data);
void		drawMenu(t_data *data);

#endif