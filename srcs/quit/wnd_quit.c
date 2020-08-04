/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wnd_quit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburl <mburl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 00:21:46 by user              #+#    #+#             */
/*   Updated: 2020/08/04 16:01:12 by mburl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "quit/quit_all.h"

void	wnd_quit(t_wnd *wnd)
{
	SDL_DestroyRenderer(wnd->renderer);
	SDL_DestroyWindow(wnd->window);
}
