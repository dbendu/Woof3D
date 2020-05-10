/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: konsolka <konsolka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 23:59:04 by user              #+#    #+#             */
/*   Updated: 2020/05/10 11:54:23 by konsolka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "input.h"
#include "Woof3D.h"

t_map	map_init(const char *filename)
{
	return (get_input(filename));
}
