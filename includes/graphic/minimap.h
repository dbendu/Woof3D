/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/26 11:05:59 by user              #+#    #+#             */
/*   Updated: 2020/04/26 13:19:04 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIMAP_H
# define MINIMAP_H

# include <SDL2/SDL.h>
# include <stdbool.h>

typedef struct		s_minimap
{
	SDL_Surface		*surface;
	SDL_Rect		viewport;
	bool			show;
}					t_minimap;

// void		minimap_draw(const t_minimap *minimap, SDL_Renderer *renderer);

#endif
