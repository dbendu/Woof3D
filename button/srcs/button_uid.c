/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   button_uid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburl <mburl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 15:02:09 by mburl             #+#    #+#             */
/*   Updated: 2020/06/29 15:07:17 by mburl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private_button.h"
#include "button.h"

inline int32_t		button_uid(t_button button)
{
	return (button->uid);
}
