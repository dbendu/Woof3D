/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: konsolka <konsolka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/25 17:28:33 by user              #+#    #+#             */
/*   Updated: 2020/04/28 08:55:38 by konsolka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_H
# define POINT_H

# include <stdbool.h>

typedef struct	s_point
{
	int			x;
	int			y;
	int			wall_c;
	bool		wall;
}				t_point;

typedef struct	s_point_xy
{
	int			x;
	int			y;
}				t_point_xy;

typedef t_point	*t_vector_point;

#endif
