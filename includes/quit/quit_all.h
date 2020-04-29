/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit_all.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 00:18:34 by user              #+#    #+#             */
/*   Updated: 2020/04/30 00:22:20 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUIT_ALL_H
# define QUIT_ALL_H

# include "map.h"
# include "minimap.h"
# include "wnd.h"
# include "libft.h"

void	map_quit(t_map *map);
void	wnd_quit(t_wnd *wnd);
void	minimap_quit(t_minimap *minimap);

#endif
