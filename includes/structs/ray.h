/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburl <mburl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/27 21:38:59 by user              #+#    #+#             */
/*   Updated: 2020/08/04 07:49:25 by mburl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

# define X_SIDE	true
# define Y_SIDE	false

typedef struct	s_ray
{
	float		x;
	float		y;
	double		len;
	float		pov;
	int			wall_c;
	double		angle;
	bool		side;
}				t_ray;

#endif
