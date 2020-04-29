/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   woof_quit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 00:15:02 by user              #+#    #+#             */
/*   Updated: 2020/04/30 00:22:28 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "quit.h"
#include "quit_all.h"

void	woof_quit(t_data *data)
{
	map_quit(&data->map);
	minimap_quit(&data->minimap);
	wnd_quit(&data->wnd);
	SDL_Quit();
}
