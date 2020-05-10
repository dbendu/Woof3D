#include <unistd.h>
#include "Woof3D.h"
#include "WoofDefines.h"
#include "libft.h"
#include "button.h"
#include "main_menu.h"
#include "start_menu.h"
#include "quit_all.h"

void		process_input(t_data *data)
{
	SDL_Event	event;

	while (SDL_PollEvent(&event))
	{
		if (event.type == SDL_QUIT || data->gameState == Exit_button)
			data->quit = true;
		else if (event.type == SDL_KEYDOWN)
			key_pressed(data, event.key.keysym.sym);
		else if (event.type == SDL_KEYUP)
			key_release(data, event.key.keysym.sym);
		else if (event.type == SDL_MOUSEMOTION)
			mouseCapture(data, event.motion);
	}
}

void		initMap(t_data *data, t_button *button)
{
	char	*file;
	if (!button)
		data->gameState = Menu_button;
	if (button->selected)
	{
		data->gameState = Continue_button;
		file = ft_strjoin("maps/", button->name);
		if (data->map.map)
			map_quit(&data->map);
		data->map = map_init(file);
		free(file);
		button->selected = false;
		return ;
	}
	else if (button->next)
		initMap(data, button->next);
}

static void	game_cycle(t_data data)
{
	while (data.quit == false)
	{
		// draw(&data);
		if (data.gameState == Start_button)
			renderMaps(&data);
		if (data.gameState == Continue_button && data.map.map)
			draw(&data);
		else if (data.gameState == Options_button)
			drawOptions(&data);
		else if (data.gameState == Menu_button)
			drawMenu(&data);
		else if (data.gameState == -1)
			initMap(&data, data.maps);
		process_input(&data);
		playerUpdate(&data, &data.map.hero);
	}
}

static void	print_map(t_map *map)
{
	for (int row = 0; row < vec_size(&map->map); ++row) {
		for (int col = 0; col < vec_size(&map->map[row]); ++col) {
			if (map->hero.position.y / CELL_SIZE == row && map->hero.position.x / CELL_SIZE == col)
				printf("X");
			else
				printf("%c", map->map[row][col].wall ? '#' : ' ');
		}
		printf("\n");
	}
}



int main(int argc, const char **argv)
{
	t_data	data;

	data = woof_init(argv[1]);
	// print_map(&data.map);
	game_cycle(data);
	woof_quit(&data);
	return (0);
}
