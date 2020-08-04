/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_all.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburl <mburl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 23:55:20 by user              #+#    #+#             */
/*   Updated: 2020/08/04 07:58:19 by mburl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_ALL_H
# define INIT_ALL_H

# include "wnd.h"
# include "map.h"
# include "libft.h"
# include "minimap.h"
# include "keyboard.h"
# include "woofdefines.h"

t_wnd		wnd_init(const char *title, int width, int height);
t_map		map_init(const char *filename);
t_keyboard	keyboard_init(void);
t_minimap	minimap_init(void);

#endif
