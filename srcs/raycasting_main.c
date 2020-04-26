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
	win->surface = NULL;
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
	for (size_t row = 0; row < vec_size(&map.map); ++row) {
		for (size_t col = 0; col < vec_size(&map.map[row]); ++col) {
			if (map.hero.position.y > (int)row * CELL_SIZE && map.hero.position.y < (int)(row + 1) * CELL_SIZE &&
				map.hero.position.x > (int)col * CELL_SIZE && map.hero.position.x < (int)(col + 1) * CELL_SIZE)
			{
				SDL_RenderDrawLine(win->renderer, col * rect.w, row * rect.w,
					(col + 1) * rect.w, (row + 1) * rect.w);
				SDL_RenderDrawLine(win->renderer, (col + 1) * rect.w, row * rect.w,
					col * rect.w, (row + 1) * rect.w);
			}
			else if (map.map[row][col].wall)
			{
				rect.y = row * CELL_SIZE;
				rect.x = col * CELL_SIZE;
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
	double	a;
	double	rayx;
	double	rayy;

	a = -FOV / 2;
	a *= 3.14 / 180;
	while (a < ((FOV * 3.14) / 360 ))
	{
		rayx = map.hero.position.x;
		rayy = map.hero.position.y;
		while (0 <= rayx && rayx <= WIDTH &&
			0 <= rayy && rayy <= HEIGHT)
		{
			if (map.map[(int)(rayy / CELL_SIZE)][(int)(rayx / CELL_SIZE)].wall)
			{
				SDL_RenderDrawLine(win->renderer, (int)(map.hero.position.x),
					(int)(map.hero.position.y),
					(int)(rayx), (int)(rayy));
					break ;
			}
			rayx += cos(a) * 0.5;
			rayy += sin(a) * 0.5;
		}
		a += 3.14 / 180;
	}

}

void		run(t_map map)
{
	t_window	*win;
	win = sdl_intial();
	SDL_SetRenderDrawColor(win->renderer, 255, 255, 255, 255);
	while (win->state)
	{
		proccesInput(win);
		// SDL_RenderDrawLine(win->renderer, 0, 0, 200, 200);
		drawmap(map, win);
		raycast(map, win);
		SDL_RenderPresent(win->renderer);
	}
}

