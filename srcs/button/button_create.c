/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   button_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburl <mburl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 15:02:00 by mburl             #+#    #+#             */
/*   Updated: 2020/08/04 15:56:50 by mburl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "button/private_button.h"
#include "button/button.h"

t_button	button_create(SDL_Renderer *render, const SDL_Rect *rect,
							int32_t uid)
{
	t_button	button;

	button = malloc(sizeof(struct s_button));
	button->render = render;
	button->btn_rect = *rect;
	button->title = NULL;
	button->uid = uid;
	button->selected = false;
	return (button);
}
