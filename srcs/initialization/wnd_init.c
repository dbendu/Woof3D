/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wnd_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 23:36:21 by user              #+#    #+#             */
/*   Updated: 2020/04/29 23:58:06 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_all.h"


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
	int		ret;

	check_args(title, width, height);
	ret = SDL_CreateWindowAndRenderer(width, height, 0, &wnd.window,
														&wnd.renderer);
	if (ret < 0)
		ft_error(SDL_GetError(), "woof_init/wnd_init", 0);
	SDL_SetWindowTitle(wnd.window, title);
	wnd.main_canvas = SDL_GetWindowSurface(wnd.window);
	if (wnd.main_canvas == NULL)
		ft_error(SDL_GetError(), "woof_init/wnd_init", 0);
	return (wnd);
}
