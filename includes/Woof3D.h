/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Woof3D.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/25 17:28:08 by user              #+#    #+#             */
/*   Updated: 2020/04/26 14:37:51 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOOF3D_h
# define WOOF3D_h

# include "data.h"

void	woof_quit(t_data *data);
void	ft_exit(const char *str);
void	draw(t_data *data);
void		playerUpdate(t_data *data, t_hero *hero);

#endif
