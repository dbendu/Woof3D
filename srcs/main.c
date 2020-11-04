/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburl <mburl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 15:00:40 by mburl             #+#    #+#             */
/*   Updated: 2020/11/04 12:27:31 by mburl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "woof3d.h"
#include "woofdefines.h"
#include "libft.h"

static void	usage(void)
{
	write(2, "usage: ./wolf3d [map]\n", 22);
}

int			main(int argc, const char **argv)
{
	t_data	data;

	if (argc == 2)
	{
		data = woof_init(argv[1]);
		main_menu_cycle(&data);
		woof_quit(&data);
	}
	else
		usage();
	return (0);
}
