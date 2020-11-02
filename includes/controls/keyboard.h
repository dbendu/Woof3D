/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/26 12:45:42 by user              #+#    #+#             */
/*   Updated: 2020/06/19 16:06:37 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYBOARD_H
# define KEYBOARD_H

# include <SDL2/SDL_scancode.h>

# define MOVE_FORWARD	(SDL_SCANCODE_W)
# define MOVE_LEFT		(SDL_SCANCODE_A)
# define MOVE_BACK		(SDL_SCANCODE_S)
# define MOVE_RIGHT		(SDL_SCANCODE_D)

# define RUN			(SDL_SCANCODE_LSHIFT)
# define SONIC_MODE		(SDL_SCANCODE_LCTRL)

# define ESC			(SDL_SCANCODE_ESCAPE)

typedef const uint8_t*	t_keyboard;

#endif
