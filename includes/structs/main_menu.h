/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_menu.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: konsolka <konsolka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 02:18:20 by konsolka          #+#    #+#             */
/*   Updated: 2020/05/10 11:46:12 by konsolka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_MENU_H
# define MAIN_MENU_H

# include "mouse.h"
# include "button.h"

typedef struct	s_menu
{
	t_button		*button;
	t_mouse			mouse;
}				t_menu;

#endif