/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburl <mburl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 15:25:24 by mburl             #+#    #+#             */
/*   Updated: 2020/11/02 16:24:43 by mburl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs/data.h"
#include "woofdefines.h"
#include "initialization/init_all.h"
#include "controls/mouse.h"
#include <SDL2/SDL_image.h>
#include <SDL2/SDL.h>

int			update_mouse(t_mouse *mouse)
{
	int		pressed;

	pressed = SDL_GetMouseState(&mouse->cursor.x, &mouse->cursor.y);
	mouse->tip.x = mouse->cursor.x;
	mouse->tip.y = mouse->cursor.y;
	return (pressed);
}

t_mouse		mouse_init(SDL_Renderer *render)
{
	t_mouse		m;

	m.texture = IMG_LoadTexture(render, "./res/textures/cursor.png");
	m.cursor.h = 50;
	m.cursor.w = 50;
	m.cursor.x = 0;
	m.cursor.y = 0;
	m.tip.h = 1;
	m.tip.w = 1;
	m.tip.x = 0;
	m.tip.y = 0;
	return (m);
}

void		draw_mouse(SDL_Renderer *render, t_mouse mouse)
{
	if (SDL_RenderCopy(render, mouse.texture, NULL, &mouse.cursor) < 0)
		ft_error(SDL_GetError(), "cannot render the mouse", 0);
}
