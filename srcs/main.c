#include "Woof3D.h"
#include "Woof_defines.h"

static void	usage(void)
{
	write(2, "usage: ./a.out [map]\n", 21);
}

// static void	print_map(t_map map)
// {
// 	for (size_t row = 0; row < vec_size(&map.map); ++row) {
// 		for (size_t col = 0; col < vec_size(&map.map[row]); ++col) {
// 			// printf("%zu - %zu\n", col * CELL_SIZE, row * CELL_SIZE);
// 			if (map.hero.position.y > (int)row * CELL_SIZE && map.hero.position.y < (int)(row + 1) * CELL_SIZE &&
// 				map.hero.position.x > (int)col * CELL_SIZE && map.hero.position.x < (int)(col + 1) * CELL_SIZE)
// 				printf("X");
// 			else
// 				printf("%c", map.map[row][col].wall ? '#' : ' ');
// 		}
// 		printf("\n");
// 	}
// }

static void	draw(t_wnd *wnd)
{
	SDL_Texture	*texture;

	texture = SDL_CreateTextureFromSurface(wnd->sdl.renderer, wnd->main_canvas);
	SDL_RenderSetViewport(wnd->sdl.renderer, NULL);
	SDL_RenderCopy(wnd->sdl.renderer, texture, NULL, NULL);
	SDL_DestroyTexture(texture);
	if (wnd->minimap.show)
	{
		texture = SDL_CreateTextureFromSurface(wnd->sdl.renderer, wnd->minimap.surface);
		SDL_RenderSetViewport(wnd->sdl.renderer, &wnd->minimap.viewport);
		SDL_RenderCopy(wnd->sdl.renderer, texture, NULL, NULL);
		SDL_DestroyTexture(texture);
	}
	SDL_RenderPresent(wnd->sdl.renderer);
}

static void	key_pressed(t_data *data, SDL_Keycode button)
{
	if (button == SDLK_UP)
		data->keyboard.move_forvard = true;
	else if (button == SDLK_DOWN)
		data->keyboard.move_back = true;
	else if (button == SDLK_RIGHT)
		data->keyboard.move_right = true;
	else if (button == SDLK_LEFT)
		data->keyboard.move_left = true;
	else if (button == SDLK_m)
		data->wnd.minimap.show = !data->wnd.minimap.show;
}

static void	game_cycle(t_data data)
{
	SDL_Event	event;
	bool		quit;
	int iters = 0;

	memset(data.wnd.main_canvas->pixels, 255, WIDTH * HEIGHT * 4);
	memset(data.wnd.minimap.surface->pixels, 100, MINIMAP_SZ * MINIMAP_SZ * 4);
	// quit = false;
	while (!quit)
	{
		draw(&data.wnd);
		iters += 1;
		SDL_WaitEvent(&event);
		if (event.type == SDL_KEYDOWN)
		{
			if (event.key.keysym.sym == SDLK_ESCAPE)
				quit = true;
			else
				key_pressed(&data, event.key.keysym.sym);
		}
		// else if (event.type == SDL_KEYUP)
		// 	key_release(&data, event.key.keysym.sym);
		else if (event.type == SDL_QUIT)
			quit = true;
	}
}

int main(int argc, const char **argv)
{
	t_data	data;
		SDL_Event	event;
	bool		quit;

	if (argc == 2)
	{
		data = woof_init(argv[1]);
		// game_cycle(data);
		quit = false;
		while (!quit)
		{
		mem(data.wnd, data.map);
				SDL_WaitEvent(&event);
		if (event.type == SDL_KEYDOWN)
		{
			if (event.key.keysym.sym == SDLK_ESCAPE)
				quit = true;
			else
				key_pressed(&data, event.key.keysym.sym);
		}
		// else if (event.type == SDL_KEYUP)
		// 	key_release(&data, event.key.keysym.sym);
		else if (event.type == SDL_QUIT)
			quit = true;
	}
		woof_quit(&data);
	}
	else
		usage();
	write(1, "Os\n", 3);
	return (0);
}
