/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   button_deselect.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburl <mburl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 15:02:02 by mburl             #+#    #+#             */
/*   Updated: 2020/06/29 15:04:02 by mburl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private_button.h"
#include "button.h"

inline void	button_deselect(t_button button)
{
	button->selected = false;
}
