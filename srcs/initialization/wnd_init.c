/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wnd_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: konsolka <konsolka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 23:36:21 by user              #+#    #+#             */
/*   Updated: 2020/05/10 11:57:43 by konsolka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <SDL2/SDL.h>
#include "WoofDefines.h"
#include "ft_utils.h"
#include "wnd.h"

static void	check_args(const char *title, int width, int height)
{
	if (!title || *title == '\0')
		ft_error(SDL_GetError(), "woof_init/wnd_init", 0);
	if (width < WND_MIN_WIDTH || height < WND_MIN_HEIGHT)
		ft_error("too small window", "woof_init/wnd_init", 0);
}

t_wnd		wnd_init(const char *title, int width, int height)
{
	t_wnd	wnd;

	check_args(title, width, height);
	if (SDL_CreateWindowAndRenderer(width, height, 0, &wnd.window,
														&wnd.renderer) < 0)
		ft_error(SDL_GetError(), "woof_init/wnd_init", 0);
	// SDL_SetHintWithPriority(SDL_HINT_MOUSE_RELATIVE_MODE_WARP, "1", SDL_HINT_OVERRIDE);
	// if (SDL_SetRelativeMouseMode(SDL_TRUE) < 0)
	// 	ft_error(SDL_GetError(), "SDL_SetRelativeMouseMode", 0);
	SDL_SetWindowTitle(wnd.window, title);
	wnd.main_canvas = SDL_GetWindowSurface(wnd.window);
	if (wnd.main_canvas == NULL)
		ft_error(SDL_GetError(), "woof_init/wnd_init", 0);
	SDL_ShowCursor(1);
	return (wnd);
}
