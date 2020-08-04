/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   woof_quit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburl <mburl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 00:15:02 by user              #+#    #+#             */
/*   Updated: 2020/08/04 16:01:12 by mburl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "quit/quit.h"
#include "quit/quit_all.h"

void	woof_quit(t_data *data)
{
	map_quit(&data->map);
	minimap_quit(&data->minimap);
	wnd_quit(&data->wnd);
	SDL_Quit();
}
