/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   woof_quit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: konsolka <konsolka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 00:15:02 by user              #+#    #+#             */
/*   Updated: 2020/05/04 02:27:41 by konsolka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "quit.h"
#include "quit_all.h"

void	woof_quit(t_data *data)
{
	map_quit(&data->map);
	SDL_DestroyTexture(data->menu.textureButton);
	minimap_quit(&data->minimap);
	wnd_quit(&data->wnd);
	SDL_Quit();
}
