/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interface_destroy.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/26 11:47:07 by user              #+#    #+#             */
/*   Updated: 2020/04/26 11:59:02 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "interface.h"

void				interface_destroy(t_interface *interface)
{
	if (interface->exist)
	{
		SDL_FreeSurface(interface->surface);
		interface->exist = false;
	}
}
