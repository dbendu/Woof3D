/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburl <mburl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/25 17:46:37 by user              #+#    #+#             */
/*   Updated: 2020/08/04 16:02:05 by mburl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include "structs/point.h"
# include "structs/hero.h"

typedef struct		s_map
{
	t_vector_point	*map;
	t_hero			hero;
}					t_map;

#endif
