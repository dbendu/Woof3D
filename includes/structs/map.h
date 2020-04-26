/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/25 17:46:37 by user              #+#    #+#             */
/*   Updated: 2020/04/25 18:14:22 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include "point.h"
# include "libft.h"
# include "hero.h"

typedef struct		s_map
{
	t_vector_point	*map;
	t_hero			hero;
}					t_map;

#endif
