/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_menu.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: konsolka <konsolka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 18:01:05 by konsolka          #+#    #+#             */
/*   Updated: 2020/05/07 02:41:25 by konsolka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <dirent.h>
#include "data.h"
#include "libft.h"
#include <errno.h>
#include "Woof3D.h"

void		deleteMaps(t_data *data)
{
	t_start_menu	*temp;

	while(data->maps)
	{
		temp = data->maps;
		data->maps = data->maps->next;
		free(temp->name);
		free(temp);
	}
}

void		startMenu(t_data *data)
{
	DIR		*dir;
	struct dirent	*entry;
	t_start_menu	*new;
	int				count;
	t_point_xy		xy;
	int				shift;
	int				rem;

	deleteMaps(data);
	count = 0;
	if (!(dir = opendir("maps/")))
		ft_error(NULL, "opendir", errno);
	rem = 0;
	shift = 0;
	while ((entry = readdir(dir)))
	{
		if (entry->d_type == 8)
		{
			shift = count / 6;
			rem = count % 6;
			xy.x = WND_WIDTH / 10 + 200 * shift + 10 * shift;
			xy.y = WND_HEIGHT / 10 + 100 * rem + 10 * rem;
			new = (t_start_menu *)malloc(sizeof(t_start_menu));
			new->name = ft_strdup(entry->d_name);
			if (!(new->but = startButtonsInit(*data, 1, xy, new->name)))
				ft_error(NULL, "maps button", 0);
			new->next = data->maps;
			data->maps = new;
			count++;
		}
	}
	closedir(dir);
	data->mapsCount = count;
	data->gameState = Start_button;
}

void		renderButtonMaps(t_data *data, t_start_menu *maps, int buttonPress)
{
	if (!maps)
		return ;
	printf("%s\n", maps->name);
	if (maps->next)
		renderButtonMaps(data, maps->next, buttonPress);
	buttonDraw(data, maps->but[0], setColor(45, 138, 41, 255), 0);
}

void		renderMaps(t_data *data)
{
	int			buttonPressed;

	if (!data->maps || data->gameState == Update_button)
		startMenu(data);
	if (SDL_SetRenderDrawColor(data->wnd.renderer, 0x00, 0x00, 0x00, 0xff) < 0)
		ft_error(SDL_GetError(), "renderMaps/SDL_SetRenderDrawColor", 0);
	if (SDL_RenderClear(data->wnd.renderer) < 0)
		ft_error(SDL_GetError(), "renderMaps/SDL_RenderClear", 0);
	buttonPressed = SDL_GetMouseState(&data->menu.mouse.cursor.x, &data->menu.mouse.cursor.y);
	data->menu.mouse.tip.x = data->menu.mouse.cursor.x;
	data->menu.mouse.tip.y = data->menu.mouse.cursor.y;
	renderButtonMaps(data, data->maps, buttonPressed);
	drawMouse(*data);
	SDL_RenderPresent(data->wnd.renderer);
}