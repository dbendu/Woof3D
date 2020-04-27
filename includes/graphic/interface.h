/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interface.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/26 14:59:02 by user              #+#    #+#             */
/*   Updated: 2020/04/26 15:00:09 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERFACE_H
# define INTERFACE_H

# include <SDL2/SDL.h>
# include <stdbool.h>

typedef struct		s_interface
{
	SDL_Surface		*surface;
	SDL_Rect		viewport;
	bool			show;
}					t_interface;

#endif
