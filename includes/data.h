/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/26 12:44:06 by user              #+#    #+#             */
/*   Updated: 2020/04/26 13:04:43 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_H
# define DATA_H

# include "wnd.h"
# include "map.h"
# include "mouse.h"
# include "keyboard.h"

typedef struct		s_data
{
	t_wnd			wnd;
	t_mouse			mouse;
	t_keyboard		keyboard;
	t_map			map;
}					t_data;

t_data	woof_init(const char *map);
void	woof_quit(t_data *data);

#endif
