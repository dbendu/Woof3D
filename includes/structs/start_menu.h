/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_menu.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: konsolka <konsolka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 18:13:11 by konsolka          #+#    #+#             */
/*   Updated: 2020/05/07 17:20:54 by konsolka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef START_MENU_H
# define START_MENU_H

# include "data.h"
# include "button.h"

typedef struct	s_start_menu
{
	char				*name;
	t_button			*but;
	struct s_start_menu	*next;
}				t_start_menu;

void		renderMaps(t_data *data);

#endif