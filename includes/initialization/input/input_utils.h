/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_utils.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/25 17:56:55 by user              #+#    #+#             */
/*   Updated: 2020/04/30 00:11:39 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_UTILS_H
# define INPUT_UTILS_H

# include "hero.h"
# include "point.h"
# include "libft.h"

t_vector_char	*read_file(const char *filename);
t_vector_point	*convert_file_to_map(const t_vector_char *lines);
t_hero			init_hero(t_point hero_position);
t_point			find_hero_position(const t_vector_char *lines);

#endif
