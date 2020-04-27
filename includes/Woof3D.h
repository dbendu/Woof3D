/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Woof3D.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/25 17:28:08 by user              #+#    #+#             */
/*   Updated: 2020/04/27 22:29:06 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOOF3D_h
# define WOOF3D_h

# include "data.h"
# include "ray.h"

void	woof_quit(t_data *data);
void	ft_exit(const char *str);
void	draw(t_data *data);
void		playerUpdate(t_data *data, t_hero *hero);
int32_t    pack_color(int alpha, int red, int green, int blue);
double			ft_map(double value, double start_range, double end_range, double new_range_start, double new_range_end);
t_ray	*raycast(float pov, float fov, int max_len, const t_map *map);

#endif
