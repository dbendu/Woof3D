/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburl <mburl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 23:59:04 by user              #+#    #+#             */
/*   Updated: 2020/08/04 15:59:24 by mburl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "initialization/init_all.h"
#include "initialization/input/input.h"

t_map	map_init(const char *filename)
{
	return (get_input(filename));
}
