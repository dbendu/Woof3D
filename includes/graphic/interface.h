/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interface.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/26 11:07:51 by user              #+#    #+#             */
/*   Updated: 2020/04/26 11:47:44 by user             ###   ########.fr       */
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
	bool			exist;
}					t_interface;

t_interface			interface_create(void);
void				interface_destroy(t_interface *interface);
void				interface_draw(const t_interface *interface,
									SDL_Renderer *renderer);

#endif
