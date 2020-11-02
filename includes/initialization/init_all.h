/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_all.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburl <mburl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 23:55:20 by user              #+#    #+#             */
/*   Updated: 2020/11/02 16:12:01 by mburl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_ALL_H
# define INIT_ALL_H

# include "graphic/wnd.h"
# include "structs/map.h"
# include "libft.h"
# include "graphic/minimap.h"
# include "controls/keyboard.h"
# include "woofdefines.h"
# include "structs/actions.h"

t_wnd		wnd_init(void);
t_map		map_init(const char *filename);
t_keyboard	keyboard_init(void);
t_minimap	minimap_init(void);
t_actions	actions_init(void);

#endif
