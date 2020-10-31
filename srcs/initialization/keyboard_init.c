/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburl <mburl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 23:35:16 by user              #+#    #+#             */
/*   Updated: 2020/08/04 15:59:24 by mburl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "initialization/init_all.h"

t_keyboard	keyboard_init(void)
{
	t_keyboard	keyboard;

	keyboard.keys_state = SDL_GetKeyboardState(NULL);
	return (keyboard);
}
