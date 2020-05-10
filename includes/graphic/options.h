/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: konsolka <konsolka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/10 07:18:22 by konsolka          #+#    #+#             */
/*   Updated: 2020/05/10 08:02:39 by konsolka         ###   ########.fr       */
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

t_options		initOptions(t_data data);
void	drawOptions(t_data *data);

#endif