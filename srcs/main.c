#include "Woof3D.h"
#include "Woof_defines.h"

static void	usage(void)
{
	write(2, "usage: ./a.out [map]\n", 21);
}

void		processInput(t_data *data)
{
	SDL_Event	event;

	while (SDL_PollEvent(&event))
	{
		if (event.type == SDL_QUIT)
			data->quit = true;
		else if (event.type == SDL_KEYDOWN)
			key_pressed(data, event.key.keysym.sym);
		else if (event.type == SDL_KEYUP)
			key_release(data, event.key.keysym.sym);
	}
}

static void	game_cycle(t_data data)
{
	while (data.quit == false)
	{
		draw(&data);
		processInput(&data);
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

	if (argc == 2)
	{
		data = woof_init(argv[1]);
		print_map(&data.map);
		game_cycle(data);
		woof_quit(&data);
	}
	else
		usage();
	return (0);
}
