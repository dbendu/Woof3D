/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   font.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: konsolka <konsolka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 13:42:23 by konsolka          #+#    #+#             */
/*   Updated: 2020/05/10 11:47:06 by konsolka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FONT_H
# define FONT_H
# include <SDL2/SDL.h>

typedef struct	s_font
{
	SDL_Texture	*text_texture;
	SDL_Rect	rect;
}				t_font;

#endif