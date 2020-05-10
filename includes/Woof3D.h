/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Woof3D.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: konsolka <konsolka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/25 17:28:08 by user              #+#    #+#             */
/*   Updated: 2020/05/10 07:46:31 by konsolka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOOF3D_h
# define WOOF3D_h

# include "data.h"
# include "WoofDefines.h"

t_data	woof_init(const char *filename);
void	woof_quit(t_data *data);

void	playerUpdate(t_data *data, t_hero *hero);
void	draw(t_data *data);

t_ray	*raycast(float pov, t_map *map);
SDL_Color	setColor(int r, int g, int b, int a);
SDL_Rect	setRect(int x, int y, int w, int h);
t_point_xy	xyInit(int x, int y);

void	mouseCapture(t_data *data, SDL_MouseMotionEvent mouse);
char	*ft_strjoin(char const *s1, char const *s2);


#endif
