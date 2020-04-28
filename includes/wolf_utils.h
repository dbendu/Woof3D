/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_utils.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: konsolka <konsolka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/03 12:29:25 by user              #+#    #+#             */
/*   Updated: 2020/04/28 08:37:51 by konsolka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_UTILS_H
# define WOLF_UTILS_H

# define FT_BIG_ENDIAN		(1)
# define FT_LITTLE_ENDIAN	(0)

# define GNL_EOF			(0)
# define GNL_OK				(1)
# define GNL_BUF			(1024)

# define PI					3.14159265358979323846

# include <stdlib.h>
# include <unistd.h>
# include "ft_types.h"
# include "ft_string.h"
# include "ft_memory.h"

// int			ft_min(int a, int b);
// int			ft_max(int a, int b);
// void		ft_swap(void *restrict ptr1, void *restrict ptr2, size_t bytes);
// void		ft_assert(bool expr, const char *msg);
// void		ft_error(const char *msg, const char *func, int code);
// int			bytes_order(void);
// int			gnl(const int fd, char **line, bool *is_newline_found);
// int			ft_atoi(const char *str);
// char		*ft_itoa(int64_t num, char *str, unsigned radix);
// void		*ft_calloc(size_t elems, size_t elem_size);
// char		*ft_memitoa(int64_t num, char *str,
// 						unsigned base, unsigned is_upper);
// char		*convert_num_to_bits_str(void *data, size_t typesize);
// double		to_ang(double rad);
double		to_rad(double angle);

#endif
