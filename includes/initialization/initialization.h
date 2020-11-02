/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburl <mburl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 23:31:44 by user              #+#    #+#             */
/*   Updated: 2020/11/02 16:13:42 by mburl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INITIALIZATION_H
# define INITIALIZATION_H

# include "graphic/wnd.h"
# include "structs/data.h"
# include "graphic/minimap.h"
# include "controls/keyboard.h"

t_data		woof_init(const char *filename);

#endif
