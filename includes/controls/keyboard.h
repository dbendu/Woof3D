/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/26 12:45:42 by user              #+#    #+#             */
/*   Updated: 2020/04/27 01:17:13 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYBOARD_H
# define KEYBOARD_H

# define MOVE_FORVARD	(1L << 0)
# define MOVE_BACK		(1L << 1)
# define MOVE_LEFT		(1L << 2)
# define MOVE_RIGHT		(1L << 3)

typedef struct	s_keyboard
{
	bool		move_forvard;
	bool		move_back;
	bool		move_left;
	bool		move_right;
}				t_keyboard;

void			key_pressed(t_data *data, SDL_Keycode button);
void			key_release(t_data *data, SDL_Keycode button);

#endif
