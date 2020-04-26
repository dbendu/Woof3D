#include "Woof3D.h"
#include "Woof_defines.h"

static void	usage(void)
{
	write(2, "usage: ./a.out [map]\n", 21);
}

static void	game_cycle(t_data data)
{
	SDL_Event	event;
	bool		quit;

	quit = false;
	while (!quit)
	{
		draw(&data);
		SDL_WaitEvent(&event);
		if (event.type == SDL_KEYDOWN)
		{
			if (event.key.keysym.sym == SDLK_ESCAPE)
				quit = true;
			else
				key_pressed(&data, event.key.keysym.sym);
		}
		else if (event.type == SDL_KEYUP)
			key_release(&data, event.key.keysym.sym);
		else if (event.type == SDL_MOUSEMOTION)
			mouse_motion(&data, &event.motion);
		else if (event.type == SDL_QUIT)
			quit = true;
	}
}

static void	print_map(t_map *map)
{
	for (int row = 0; row < vec_size(&map->map); ++row) {
		for (int col = 0; col < vec_size(&map->map[row]); ++col) {
			if (map->hero.relative_position.y == row && map->hero.relative_position.x == col)
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
		for (int i = 0; i < WIDTH * HEIGHT; ++i)
			((int32_t*)data.wnd.main_canvas->pixels)[i] = 0xff000000;
		game_cycle(data);
		woof_quit(&data);
	}
	else
		usage();
	return (0);
}
