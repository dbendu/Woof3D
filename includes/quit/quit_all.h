/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit_all.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburl <mburl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 00:18:34 by user              #+#    #+#             */
/*   Updated: 2020/08/04 16:01:55 by mburl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUIT_ALL_H
# define QUIT_ALL_H

# include "structs/map.h"
# include "graphic/minimap.h"
# include "graphic/wnd.h"
# include "libft.h"

void	map_quit(t_map *map);
void	wnd_quit(t_wnd *wnd);
void	minimap_quit(t_minimap *minimap);

#endif
