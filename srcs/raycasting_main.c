#include "map.h"
#include "point.h"
#include "wnd.h"
#include <SDL2/SDL.h>
#include "Woof3D.h"
#include "Woof_defines.h"
#include <math.h>


// void		drawmap(t_map map, t_window *win)
// {
// 	SDL_Rect	rect;
// 	rect.w = CELL_SIZE;
// 	rect.h = CELL_SIZE;
// 	for (size_t row = 0; row < vec_size(&map.map); ++row) {
// 		for (size_t col = 0; col < vec_size(&map.map[row]); ++col) {
// 			if (map.hero.position.y > (int)row * CELL_SIZE && map.hero.position.y < (int)(row + 1) * CELL_SIZE &&
// 				map.hero.position.x > (int)col * CELL_SIZE && map.hero.position.x < (int)(col + 1) * CELL_SIZE)
// 			{
// 				SDL_RenderDrawLine(win->renderer, col * rect.w, row * rect.w,
// 					(col + 1) * rect.w, (row + 1) * rect.w);





// 				SDL_RenderDrawLine(win->renderer, (col + 1) * rect.w, row * rect.w,
// 					col * rect.w, (row + 1) * rect.w);
// 			}
// 			else if (map.map[row][col].wall)
// 			{
// 				rect.y = row * CELL_SIZE;
// 				rect.x = col * CELL_SIZE;
// 				SDL_RenderDrawRect(win->renderer, &rect);
// 			}
// 		}
// 	}
// }


/*
	if you need start angle just add in t_point_d
	int a;
	and then in code
	scene[i].a = a * 180 / 3.14;
	thus you will have start angle
*/
double		*raycast(t_map map)
{
	int			i;
	double	a;
	double	rayx;
	double	rayy;
	double	*scene;

	scene = (double *)malloc(sizeof(double) * FOV);
	a = map.hero.pov - FOV / 2;
	a *= 3.14 / 180;
	i = 0;
	while (a < ((((FOV / 2 + map.hero.pov) * 3.14) / 180 )))
	{
		rayx = map.hero.position.x;
		rayy = map.hero.position.y;
		while (0 <= rayx && rayx <= WIDTH &&
			0 <= rayy && rayy <= HEIGHT)
		{
			if (map.map[(int)(rayy / CELL_SIZE)][(int)(rayx / CELL_SIZE)].wall)
			{
				scene[i] = sqrt(pow(rayx, 2) + pow(rayy, 2));
				break ;
			}
			rayx += cos(a) * 0.5;
			rayy += sin(a) * 0.5;
		}
		a += 3.14 / 180;
		i++;
	}
	return (scene);
}

double			ft_map(double value, double start_range, double end_range, double new_range_start, double new_range_end)
{
	return ((value - start_range) / (end_range - start_range) *
				(new_range_end - new_range_start) + new_range_start);
}

int32_t    pack_color(int alpha, int red, int green, int blue)
{
    return ((alpha << 24) | (red << 16) | (green << 8) | blue);
}

void	d3Render(double *scene, t_wnd win, t_map map)
{
	int		i;
	double	w;
	SDL_Rect	rect;
	int		a;
	int32_t	color;

	i = 1;
	w = WIDTH / FOV;
	rect.h = HEIGHT;
	rect.w = (int)w;
	while (i <= FOV)
	{
		rect.x = i * w;
		if (rect.x + rect.w >= WIDTH)
			rect.w = WIDTH - rect.x - 1;
		rect.y = 0;
		a = (int)ft_map(scene[i], 0.0, 800.0, 0.0, 255.0);
		color = pack_color(255, a, a, a);
		SDL_FillRect(win.main_canvas, &rect, color);
		i++;
	}
	SDL_Texture *m;
	m = SDL_CreateTextureFromSurface(win.sdl.renderer, win.main_canvas);
	SDL_RenderCopy(win.sdl.renderer, m, NULL, NULL);
	SDL_RenderPresent(win.sdl.renderer);
	SDL_DestroyTexture(m);
}

void	mem(t_wnd win, t_map map)
{
	double		*ray;
	ray = raycast(map);
	d3Render(ray, win, map);
}