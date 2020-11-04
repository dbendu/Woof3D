/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburl <mburl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 20:53:47 by mburl             #+#    #+#             */
/*   Updated: 2020/11/02 20:54:12 by mburl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOOF3D_ACTIONS_H
# define WOOF3D_ACTIONS_H

# include <stdbool.h>

typedef struct		s_actions
{
	bool			move_forward;
	bool			move_back;
	bool			move_left;
	bool			move_right;

	bool			run;
	bool			sonic_mode;

	bool			to_pause;
	bool			to_main;
	bool			exit;
	bool			to_game;

	bool			last_show_status;
	bool			show_minimap;
}					t_actions;

#endif
