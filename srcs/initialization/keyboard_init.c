/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: konsolka <konsolka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 23:35:16 by user              #+#    #+#             */
/*   Updated: 2020/05/10 12:22:02 by konsolka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "keyboard.h"
#include "ft_memory.h"

t_keyboard	keyboard_init(void)
{
	t_keyboard	keyboard;

	ft_memset(&keyboard, 0, sizeof(t_keyboard));
	return (keyboard);
}
