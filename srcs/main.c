/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburl <mburl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 15:00:40 by mburl             #+#    #+#             */
/*   Updated: 2020/06/29 15:00:41 by mburl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "Woof3D.h"
#include "WoofDefines.h"
#include "libft.h"

static void	usage(void)
{
	write(2, "usage: ./a.out [map]\n", 21);
}


int main(int argc, const char **argv)
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
