/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: konsolka <konsolka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/26 11:05:59 by user              #+#    #+#             */
/*   Updated: 2020/05/10 11:34:02 by konsolka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIMAP_H
# define MINIMAP_H

# include <SDL2/SDL.h>
# include <stdbool.h>
# include "mouse.h"

typedef struct		s_minimap
{
	SDL_Surface		*surface;
	SDL_Rect		viewport;
	t_mouse			playerTex;
	bool			show;
}					t_minimap;

#endif
