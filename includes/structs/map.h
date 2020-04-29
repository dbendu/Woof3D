/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/25 17:46:37 by user              #+#    #+#             */
/*   Updated: 2020/04/29 23:11:57 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include "point.h"
# include "hero.h"

typedef struct		s_map
{
	t_vector_point	*map;
	t_hero			hero;
}					t_map;

#endif
