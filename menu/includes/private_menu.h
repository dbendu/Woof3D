/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   private_menu.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburl <mburl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 15:12:37 by mburl             #+#    #+#             */
/*   Updated: 2020/06/29 15:12:43 by mburl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRIVATE_MENU_H
# define PRIVATE_MENU_H

# include <SDL2/SDL.h>
# include <stdbool.h>
# include "button.h"
# include "mouse.h"

# define BUTTONS_INCREASE	3

struct				s_menu
{
	SDL_Renderer	*render;

	t_button		*buttons;
	t_mouse			mouse;

	int				buttons_allocated;
	int				buttons_count;
	int				selected_ind;
	int				selected_uid;

	bool			cycling;
};

#endif
