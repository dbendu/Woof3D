/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_viz.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburl <mburl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 12:26:04 by mburl             #+#    #+#             */
/*   Updated: 2020/11/04 11:54:41 by mburl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "woof3d.h"
#include "menu/sdl_menu.h"
#include "libft.h"
#include <time.h>

static inline float	calc_tx_y(float wnd_y, t_wnd *sdl,
										double len)
{
	return (-wnd_y * sdl->textures[0].h /
				(float)(CELL_SIZE / len *
				(WND_WIDTH / 2 / tan(to_rad(HERO_FOV / 2)))));
}

static inline float	calc_wnd_y(double len)
{
	return ((WND_HEIGHT / 2) - ((CELL_SIZE / len *
			(WND_WIDTH / 2 / tan(to_rad(HERO_FOV / 2)))) / 2));
}

static inline float	calc_down(double len)
{
	return ((WND_HEIGHT / 2) - ((CELL_SIZE / len *
			(WND_WIDTH / 2 / tan(to_rad(HERO_FOV / 2)))) / 2) +
			(CELL_SIZE / len * (WND_WIDTH / 2 /
			tan(to_rad(HERO_FOV / 2)))));
}

void				draw_vis_while(t_wnd *sdl, t_ray *rays,
									t_point **map, int x)
{
	int			tx_x;
	uint32_t	*src_pixels;
	int			down;
	float		tx_y;
	float		wnd_y;

	src_pixels = sdl->textures[map[(int)rays[x].y / CELL_SIZE]
		[(int)rays[x].x / CELL_SIZE].wall_c - 1].pixels;
	down = calc_down(rays[x].len);
	wnd_y = calc_wnd_y(rays[x].len);
	tx_y = 0;
	tx_x = rays[x].side == X_SIDE ? ((int)rays[x].x % sdl->textures[0].w) :
		((int)rays[x].y % sdl->textures[0].w);
	tx_y += wnd_y < 0 ? calc_tx_y(wnd_y, sdl, rays[x].len) : tx_y;
	wnd_y = wnd_y < 0 ? -1 : wnd_y - 1;
	down = down > WND_HEIGHT ? WND_HEIGHT : down;
	while (++wnd_y < down)
	{
		((uint32_t *)(sdl->main_canvas->pixels))
			[(int)wnd_y * WND_WIDTH + x] = src_pixels[(int)tx_y *
				sdl->textures[0].w + tx_x];
		tx_y += sdl->textures[0].h / (float)(CELL_SIZE / rays[x].len *
			(WND_WIDTH / 2 / tan(to_rad(HERO_FOV / 2))));
	}
}

void				draw_vis(t_wnd *sdl, t_ray *rays, t_point **map)
{
	int			x;

	x = -1;
	while (++x < WND_WIDTH)
	{
		if (!check_vals(rays[x].y / CELL_SIZE, rays[x].x / CELL_SIZE, map))
			continue ;
		draw_vis_while(sdl, rays, map, x);
	}
}
