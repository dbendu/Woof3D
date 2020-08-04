/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   button_select.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburl <mburl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 15:02:07 by mburl             #+#    #+#             */
/*   Updated: 2020/06/29 15:03:41 by mburl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private_button.h"
#include "button.h"

inline void		button_select(t_button button)
{
	button->selected = true;
}
