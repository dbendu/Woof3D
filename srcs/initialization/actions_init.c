/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburl <mburl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 20:17:32 by mburl             #+#    #+#             */
/*   Updated: 2020/11/02 20:46:22 by mburl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "initialization/initialization.h"
#include "ft_memory.h"

t_actions	actions_init(void)
{
	t_actions actions;

	ft_memset(&actions, 0, sizeof(t_actions));
	return (actions);
}
