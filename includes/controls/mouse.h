/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/26 12:42:36 by user              #+#    #+#             */
/*   Updated: 2020/04/27 01:56:57 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOUSE_H
# define MOUSE_H

# include <stdbool.h>

typedef struct	s_mouse
{
	bool		left_button;
	bool		right_button;
	int			x;
}				t_mouse;

typedef struct s_data t_data;

void	move_mouse(t_data *data);
void	mouse_motion(t_data *data, const SDL_MouseMotionEvent *m);

#endif
