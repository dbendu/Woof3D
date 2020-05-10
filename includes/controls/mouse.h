/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: konsolka <konsolka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 17:09:32 by konsolka          #+#    #+#             */
/*   Updated: 2020/05/10 11:48:23 by konsolka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOUSE_H
# define MOUSE_H

# include <SDL2/SDL.h>

typedef struct	s_mouse
{
	SDL_Rect	cursor;
	SDL_Rect	tip;
	SDL_Texture	*texture;
}				t_mouse;



#endif