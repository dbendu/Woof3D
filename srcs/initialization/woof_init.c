/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   woof_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 23:33:46 by user              #+#    #+#             */
/*   Updated: 2020/04/29 23:58:54 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "initialization.h"
#include "WoofDefines.h"
#include "init_all.h"
#include "libft.h"

static void	sdl_init(void)
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
		ft_error(SDL_GetError(), "woof_init", 0);
}

t_data	woof_init(const char *filename)
{
	t_data	data;

	sdl_init();
	data.keyboard = keyboard_init();
	data.wnd = wnd_init(WND_TITLE, WND_WIDTH, WND_HEIGHT);
	data.minimap = minimap_init();
	data.map = map_init(filename);
	// data.map = get_input(filename);
	data.quit = false;
	return (data);
}
