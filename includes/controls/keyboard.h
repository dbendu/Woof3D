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

# include <SDL2/SDL.h>

# define MOVE_FORWARD	(SDL_SCANCODE_W)
# define MOVE_LEFT		(SDL_SCANCODE_A)
# define MOVE_BACK		(SDL_SCANCODE_S)
# define MOVE_RIGHT		(SDL_SCANCODE_D)
# define RUN			(SDL_SCANCODE_LSHIFT)
# define ESC			(SDL_SCANCODE_ESCAPE)

typedef struct		s_keyboard
{
	// TODO: заменить массивом чисел?
	const uint8_t	*keys_state;
}					t_keyboard;

typedef struct s_data	t_data;

#endif
