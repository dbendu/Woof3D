/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/26 12:45:42 by user              #+#    #+#             */
/*   Updated: 2020/04/27 21:12:05 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYBOARD_H
# define KEYBOARD_H

# define KEYS_BINDED	(6)

# define MOVE_FORWARD	(0)
# define MOVE_BACK		(1)
# define TURN_LEFT		(2)
# define TURN_RIGHT		(3)
# define FOV_DECREASE	(4)
# define FOV_INCREASE	(5)

typedef struct	s_keyboard
{
	bool		key[KEYS_BINDED];
}				t_keyboard;

void			key_pressed(t_data *data, SDL_Keycode button);
void			key_release(t_data *data, SDL_Keycode button);

#endif