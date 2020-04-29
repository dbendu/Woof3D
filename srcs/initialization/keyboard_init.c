/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 23:35:16 by user              #+#    #+#             */
/*   Updated: 2020/04/29 23:58:28 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_all.h"

t_keyboard	keyboard_init(void)
{
	t_keyboard	keyboard;

	ft_memset(&keyboard, 0, sizeof(t_keyboard));
	return (keyboard);
}
