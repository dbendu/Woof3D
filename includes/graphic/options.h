/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: konsolka <konsolka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/10 07:18:22 by konsolka          #+#    #+#             */
/*   Updated: 2020/05/10 11:52:09 by konsolka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPTIONS_H
# define OPTIONS_H

# include "button.h"

typedef struct	s_optionButton
{
	t_button	*button;
	int			id;
	char		c;
}				t_optionButton;

typedef struct	s_options
{
	t_optionButton	*messageButton;
	t_optionButton	*controlButton;
}				t_options;



#endif