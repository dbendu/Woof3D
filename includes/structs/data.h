/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: konsolka <konsolka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/26 12:44:06 by user              #+#    #+#             */
/*   Updated: 2020/05/07 00:00:03 by konsolka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_H
# define DATA_H

# include <stdbool.h>
# include "wnd.h"
# include "keyboard.h"
# include "map.h"
# include "minimap.h"
# include "main_menu.h"
# include "ray.h"
# include "start_menu.h"

typedef struct		s_data
{
	t_wnd			wnd;
	t_keyboard		keyboard;
	t_map			map;
	t_minimap		minimap;
	t_menu			menu;
	t_start_menu	*maps;
	bool			quit;
	int				gameState;
	int				mapsCount;
}					t_data;

#endif
