/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   font.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: konsolka <konsolka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 13:42:23 by konsolka          #+#    #+#             */
/*   Updated: 2020/05/09 06:10:55 by konsolka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FONT_H
# define FONT_H
# include <SDL2/SDL.h>
# include "data.h"

typedef struct	s_font
{
	SDL_Texture	*text_texture;
	SDL_Rect	rect;
}				t_font;

t_font	fontInit(t_data data, int font_size, const char *message, SDL_Color color);
void		fontDraw(t_data data, t_font font, int x, int y);

#endif