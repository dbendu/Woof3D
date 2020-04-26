#include "map.h"
#include "point.h"
#include "window.h"
#include <SDL2/SDL.h>
#include "Woof3D.h"
#include "Woof_defines.h"
#include <math.h>

t_window	*sdl_intial()
{
	t_window	*win;

	win = (t_window *)malloc(sizeof(*win));
	win->state = true;
	win->window = NULL;
	win->surface	= NULL;
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
		ft_exit(SDL_GetError());
	if (!(win->window = SDL_CreateWindow(TITLE, SDL_WINDOWPOS_UNDEFINED,
			SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN)))
		ft_exit(SDL_GetError());
	if (!(win->surface = SDL_GetWindowSurface(win->window)))
		ft_exit(SDL_GetError());
	win->renderer = SDL_CreateRenderer(win->window, -1, NULL);
	return (win);
}

void	proccesInput(t_window *win)
{
	SDL_Event	event;

	while (SDL_PollEvent(&event))
	{
		if (event.type == SDL_QUIT)
			win->state = 0;
	}
}

void		drawmap(t_map map, t_window *win)
{
	SDL_Rect	rect;
	rect.w = CELL_SIZE;
	rect.h = CELL_SIZE;
	printf("HERO: %d-%d\n", map.hero.position.x, map.hero.position.y);
	for (size_t row = 0; row < vec_size(&map.map); ++row) {
		for (size_t col = 0; col < vec_size(&map.map[row]); ++col) {
			// printf("%zu - %zu\n", col * CELL_SIZE, row * CELL_SIZE);
			if (map.hero.position.y > (int)row * CELL_SIZE && map.hero.position.y < (int)(row + 1) * CELL_SIZE &&
				map.hero.position.x > (int)col * CELL_SIZE && map.hero.position.x < (int)(col + 1) * CELL_SIZE)
			{
				SDL_RenderDrawLine(win->renderer, col * rect.w, row * rect.w,
					(col + 1) * rect.w, (row + 1) * rect.w);
				SDL_RenderDrawLine(win->renderer, (col + 1) * rect.w, row * rect.w,
					col * rect.w, (row + 1) * rect.w);
			}
				// printf("X");
			else if (map.map[row][col].wall)
			{
				rect.x = row * rect.w;
				rect.y = col * rect.w;
				SDL_RenderDrawRect(win->renderer, &rect);
			}
		}
	}
}


/*
	needs to work on this. It dosen't work because i need to calculate somehow
	if pixel is drawen; or cast my rayy and rayx to x and y now it casted in
	x and y in pixels
*/
void		raycast(t_map map, t_window *win)
{
	SDL_Rect	rect;
	int		a;
	double	rayx;
	double	rayy;

	a = 0;
	rect.w = (int)(WIDTH / vec_size(&map.map[0]));
	rect.h = (int)(HEIGHT / vec_size(&map.map));
	rect.w = (rect.h < rect.w) ? rect.h : rect.w;
	rect.h = (rect.w < rect.h) ? rect.w : rect.h;
	while (a < 181)
	{
		rayx = map.hero.position.x  * rect.w;
		rayy = map.hero.position.y  * rect.w;
		while (rect.w <= rayx && rayx <= WIDTH &&
			rect.w <= rayy && rayy <= HEIGHT)
		{
			// rayx += cos(a) * 0.5;
			// rayy += sin(a) * 0.5;
			if (map.map[(int)(rayy / rect.w)][(int)(rayx / rect.w)].wall)
			{
				write(1, "OK\n", 3);
				SDL_RenderDrawLine(win->renderer, (int)(map.hero.position.x * rect.w),
					(int)(map.hero.position.y * rect.w),
					(int)(rayx * rect.w), (int)(rayy * rect.w));
			}
		}
		a++;
	}

}

void		run(t_map map)
{
	t_window	*win;
	win = sdl_intial();
	SDL_SetRenderDrawColor(win->renderer, 255, 255, 255, 255);
	bool quit = false;
	bool draw = true;
	SDL_Event	event;
	while (!quit)
	{
		SDL_WaitEvent(&event);
		if (event.type == SDL_QUIT)
			quit = true;
		if (draw)
		{
			drawmap(map, win);
			// raycast(map, win);
			SDL_RenderPresent(win->renderer);
			draw = false;
		}
	}
}
