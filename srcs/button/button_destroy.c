/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   button_destroy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburl <mburl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 15:02:03 by mburl             #+#    #+#             */
/*   Updated: 2020/08/04 15:56:50 by mburl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "button/private_button.h"
#include "button/button.h"

inline void	button_destroy(t_button button)
{
	if (button->title)
		SDL_DestroyTexture(button->title);
	free(button);
}
