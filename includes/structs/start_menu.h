/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_menu.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: konsolka <konsolka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 18:13:11 by konsolka          #+#    #+#             */
/*   Updated: 2020/05/10 11:43:38 by konsolka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef START_MENU_H
# define START_MENU_H

# include "button.h"

typedef struct	s_start_menu
{
	char				*name;
	t_button			*but;
	struct s_start_menu	*next;
}				t_start_menu;


#endif