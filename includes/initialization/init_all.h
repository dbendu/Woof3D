/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_all.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 23:55:20 by user              #+#    #+#             */
/*   Updated: 2020/04/30 00:10:42 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_ALL
# define INIT_ALL

# include "wnd.h"
# include "map.h"
# include "libft.h"
# include "minimap.h"
# include "keyboard.h"
# include "WoofDefines.h"

t_wnd		wnd_init(const char *title, int width, int height);
t_map		map_init(const char *filename);
t_keyboard	keyboard_init(void);
t_minimap	minimap_init(void);

#endif
