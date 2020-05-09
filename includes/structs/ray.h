/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: konsolka <konsolka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/27 21:38:59 by user              #+#    #+#             */
/*   Updated: 2020/05/09 09:08:10 by konsolka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

typedef struct	s_ray
{
	float		x;
	float		y;
	double		len;
	float		pov;
	int			wall_c;
	double		angle;
	int			side;
}				t_ray;

#endif
