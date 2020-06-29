/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   button.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburl <mburl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 15:01:54 by mburl             #+#    #+#             */
/*   Updated: 2020/06/29 15:07:38 by mburl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUTTON_H
# define BUTTON_H

# include <SDL2/SDL.h>
# include <SDL2/SDL_ttf.h>
# include <stdbool.h>

typedef struct s_button*	t_button;

t_button		button_create(SDL_Renderer *render, const SDL_Rect *rect,
								int32_t uid);
void			button_destroy(t_button button);
void			button_select(t_button button);
void			button_deselect(t_button button);
int32_t			button_uid(t_button button);
void			button_add_title(t_button button, const char *title,
									TTF_Font *font);
void			button_draw(t_button button);

#endif
