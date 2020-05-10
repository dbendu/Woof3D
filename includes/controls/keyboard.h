/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: konsolka <konsolka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/26 12:45:42 by user              #+#    #+#             */
/*   Updated: 2020/05/10 11:53:33 by konsolka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYBOARD_H

# include <stdbool.h>

# define KEYBOARD_H
# define KEYS_BINDED	(6)
# define TURN_LEFT		(0)
# define MOVE_FORWARD	(1)
# define TURN_RIGHT		(2)
# define MOVE_BACK		(3)
# define FOV_DECREASE	(4)
# define FOV_INCREASE	(5)

typedef struct	s_keyboard
{
	bool		key[KEYS_BINDED];
}				t_keyboard;

#endif
