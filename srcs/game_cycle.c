#include "Woof3D.h"
#include "menu.h"
#include "libft.h"

static
void	handle_key_press(t_keyboard *keyboard, SDL_Keycode key)
{
	if (key == SDLK_w) {
		keyboard->key[MOVE_FORWARD] = true;
	} else if (key == SDLK_s) {
		keyboard->key[MOVE_BACK] = true;
	} else if (key == SDLK_a) {
		keyboard->key[TURN_LEFT] = true;
	} else if (key == SDLK_d) {
		keyboard->key[TURN_RIGHT] = true;
	}
}

static
void	handle_key_release(t_keyboard *keyboard, SDL_Keycode key)
{
	if (key == SDLK_w) {
		keyboard->key[MOVE_FORWARD] = false;
	} else if (key == SDLK_s) {
		keyboard->key[MOVE_BACK] = false;
	} else if (key == SDLK_a) {
		keyboard->key[TURN_LEFT] = false;
	} else if (key == SDLK_d) {
		keyboard->key[TURN_RIGHT] = false;
	}
}



void	setup_color(SDL_Renderer *render, t_point *point)
{
	switch (point->wall_c) {
		case 1:
			SDL_SetRenderDrawColor(render, 0xff, 0, 0, 0xff);
			break;
		case 2:
			SDL_SetRenderDrawColor(render, 0, 0xff, 0, 0xff);
			break;
		case 3:
			SDL_SetRenderDrawColor(render, 0, 0, 0xff, 0xff);
			break;
		case 4:
			SDL_SetRenderDrawColor(render, 0xff, 0, 0xff, 0xff);
			break;
		case 0:
			SDL_SetRenderDrawColor(render, 0xff, 0xff, 0xff, 0xff);
			break;
		default:
			SDL_SetRenderDrawColor(render, 0xff, 0xff, 0, 0xff);
			break;
	}
}

void	draw_vis(SDL_Renderer *render, t_ray *rays, int fov, t_vector_point *map)
{
	const int wall_height = 60;
	const float distance = WND_WIDTH / 2 / tan(to_rad(fov / 2));

	for (int x = 0; x < WND_WIDTH; ++x) {
		int height = wall_height / rays[x].len * distance;
		int up = WND_HEIGHT / 2 - height / 2;
		int down = up + height;
		setup_color(render, &map[(int)rays[x].y / CELL_SIZE][(int)rays[x].x / CELL_SIZE]);
		SDL_RenderDrawLine(render, x, up, x, down);
	}
}

void	draw_map(SDL_Renderer *render, t_vector_point *map)
{
	SDL_Rect	rect;

	rect.h = CELL_SIZE - 1;
	rect.w = CELL_SIZE - 1;
	rect.y = 1;
	for (int y = 0; y < vec_size(&map); ++y) {
		rect.x = 1;
		for (int x = 0; x < vec_size(&map[y]); ++x) {
			if (!map[y][x].wall) {
				SDL_SetRenderDrawColor(render, 0x78, 0x78, 0x78, 0xff);
				SDL_RenderFillRect(render, &rect);
			} else {
				SDL_SetRenderDrawColor(render, 0xff, 0xff, 0xff, 0xff);
				SDL_RenderFillRect(render, &rect);
			}
			rect.x += CELL_SIZE;
		}
		rect.y += CELL_SIZE;
	}
}

void	draw_rays(SDL_Renderer *render, t_ray *rays, t_position start)
{
	SDL_SetRenderDrawColor(render, 0xff, 0, 0, 0xff);
	for (int x = 0; x < WND_WIDTH; ++x) {
		SDL_RenderDrawLine(render, start.x, start.y,
						   rays[x].x, rays[x].y);
	}
}

#include <time.h>

static
void	render(t_data *data, bool map)
{
	SDL_SetRenderDrawColor(data->wnd.renderer, 0, 0, 0, 0xff);
	SDL_RenderClear(data->wnd.renderer);
	static const SDL_Rect	up = {0, 0, WND_WIDTH, WND_HEIGHT / 2};
	static const SDL_Rect	down = {0, WND_HEIGHT / 2, WND_WIDTH, WND_HEIGHT / 2};
	SDL_SetRenderDrawColor(data->wnd.renderer, 0, 0xde, 0xff, 0xff);
	SDL_RenderFillRect(data->wnd.renderer, &up);
	SDL_SetRenderDrawColor(data->wnd.renderer, 0x57, 0x57, 0x57, 0xff);
	SDL_RenderFillRect(data->wnd.renderer, &down);
	int fov = 60;


	t_ray *rays = raycast(fov, data->map.hero.pov, data->map.hero.position, data->map.map);


	draw_vis(data->wnd.renderer, rays, fov, data->map.map);
	if (map) {
		draw_map(data->wnd.renderer, data->map.map);
		draw_rays(data->wnd.renderer, rays, data->map.hero.position);
	}


	free(rays);

	SDL_RenderPresent(data->wnd.renderer);
}

static
void	update(t_data *data)
{
	if (data->keyboard.key[MOVE_FORWARD]) {
		float new_fx = data->map.hero.position.x + 2 * cos(to_rad(data->map.hero.pov));
		float new_fy = data->map.hero.position.y - 2 * sin(to_rad(data->map.hero.pov));
		int old_x = data->map.hero.position.x / CELL_SIZE;
		int old_y = data->map.hero.position.y / CELL_SIZE;
		int new_x = new_fx / CELL_SIZE;
		int new_y = new_fy / CELL_SIZE;
		if (data->map.map[old_y][new_x].wall == false) {
			data->map.hero.position.x = new_fx;
		}
		if (data->map.map[new_y][old_x].wall == false) {
			data->map.hero.position.y = new_fy;
		}
	}
	if (data->keyboard.key[MOVE_BACK]) {
		float new_fx = data->map.hero.position.x - cos(to_rad(data->map.hero.pov));
		float new_fy = data->map.hero.position.y + sin(to_rad(data->map.hero.pov));
		int old_x = data->map.hero.position.x / CELL_SIZE;
		int old_y = data->map.hero.position.y / CELL_SIZE;
		int new_x = new_fx / CELL_SIZE;
		int new_y = new_fy / CELL_SIZE;
		if (data->map.map[old_y][new_x].wall == false) {
			data->map.hero.position.x = new_fx;
		}
		if (data->map.map[new_y][old_x].wall == false) {
			data->map.hero.position.y = new_fy;
		}
	}
	if (data->keyboard.key[TURN_LEFT]) {
		data->map.hero.pov += 1.3;
		if (data->map.hero.pov >= 360) {
			data->map.hero.pov -= 360;
		}
	}
	if (data->keyboard.key[TURN_RIGHT]) {
		data->map.hero.pov -= 1.3;
		if (data->map.hero.pov < 0) {
			data->map.hero.pov += 360;
		}
	}
}

static
void	event_handle(const SDL_Event *event, t_data *data)
{
	switch (event->type) {
		case SDL_QUIT:
			data->jumps.exit = true;
			break;
		case SDL_KEYDOWN:
			switch (event->key.keysym.sym) {
				case SDLK_ESCAPE:
					pause_cycle(data);
					break;
				default:
					handle_key_press(&data->keyboard, event->key.keysym.sym);
					break;
			}
			break;
		case SDL_KEYUP:
			handle_key_release(&data->keyboard, event->key.keysym.sym);
			break;
	}
}

void	game_cycle(t_data *data)
{
	SDL_Event	event;
	bool		draw_map = false;

	while (true) {
		SDL_PollEvent(&event);
		if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_m) {
			draw_map = !draw_map;
		} else {
			event_handle(&event, data);
		}
		if (data->jumps.to_main || data->jumps.exit)
			break ;
		update(data);
		render(data, draw_map);
		SDL_Delay(7);
	}
}
