/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_menu.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: konsolka <konsolka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 18:01:05 by konsolka          #+#    #+#             */
/*   Updated: 2020/05/06 18:16:16 by konsolka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <dirent.h>
#include "data.h"
#include "libft.h"
#include <errno.h>

void		startMenu(t_data *data)
{
	DIR		*dir;
	struct dirent	*entry;

	if (!(dir = opendir("maps/")))
		ft_error(NULL, "opendir", errno);
	while ((entry = readdir(dir)))
		printf("%s, %d\n", entry->d_name, entry->d_type);
	closedir(dir);
}