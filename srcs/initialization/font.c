/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   font.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: konsolka <konsolka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 13:43:25 by konsolka          #+#    #+#             */
/*   Updated: 2020/05/05 17:48:31 by konsolka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "libft.h"
#include "data.h"
#include "font.h"

t_font	fontInit(t_data data, int font_size, const char *message, SDL_Color color)
{
	t_font		ret;
	TTF_Font	*font;
	SDL_Surface	*surf;

	if (!(font = TTF_OpenFont("res/font/VINERITC.TTF", font_size)))
		ft_error(TTF_GetError(), "TTF_OpenFont", 0);
	if (!(surf = TTF_RenderText_Solid(font, message, color)))
		ft_error(TTF_GetError(), "TTF_RenderText_Solid", 0);
	if (!(ret.text_texture = SDL_CreateTextureFromSurface(data.wnd.renderer, surf)))
		ft_error(TTF_GetError(), "SDL_CreateTextureFromSurface", 0);
	SDL_FreeSurface(surf);
	if (SDL_QueryTexture(ret.text_texture, NULL, NULL, &ret.rect.w, &ret.rect.h) < 0)
		ft_error(SDL_GetError(), "SDL_QueryTexture", 0);
	ret.rect.x = 0;
	ret.rect.y = 0;
	return (ret);
}

void		fontDraw(t_data data, t_font font, int x, int y)
{
	font.rect.x = x;
	font.rect.y = y;
	SDL_RenderCopy(data.wnd.renderer, font.text_texture, NULL, &font.rect);
}