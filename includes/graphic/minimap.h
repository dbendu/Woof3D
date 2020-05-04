/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: konsolka <konsolka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/26 11:05:59 by user              #+#    #+#             */
/*   Updated: 2020/05/03 13:55:34 by konsolka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIMAP_H
# define MINIMAP_H

# include <SDL2/SDL.h>
# include <stdbool.h>
# include "WoofDefines.h"

typedef struct		s_minimap
{
	SDL_Surface		*surface;
	SDL_Rect		viewport;
	bool			show;
}					t_minimap;

#endif
