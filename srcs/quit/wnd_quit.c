/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wnd_quit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 00:21:46 by user              #+#    #+#             */
/*   Updated: 2020/04/30 00:22:17 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "quit_all.h"

void	wnd_quit(t_wnd *wnd)
{
	SDL_DestroyRenderer(wnd->renderer);
	SDL_DestroyWindow(wnd->window);
}