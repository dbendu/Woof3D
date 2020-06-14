#include "Woof3D.h"
#include "sdl_menu.h"

static
void	handle_event(const SDL_Event *event, t_data *data)
{
	int32_t		uid;

	switch (event->type) {
		case SDL_QUIT:
			data->jumps.exit = true;
			break;
		case SDL_KEYDOWN:
			switch (event->key.keysym.sym) {
				case SDLK_ESCAPE:
					data->jumps.exit = true;
					break;
				case SDLK_DOWN:
					menu_select_next(data->menus.main);
					break;
				case SDLK_UP:
					menu_select_prev(data->menus.main);
					break;
				case SDLK_RETURN:
					uid = menu_selected_uid(data->menus.main);
					switch (uid) {
						case BUTTON_EXIT:
							data->jumps.exit = true;
							break;
						case BUTTON_SETTINGS:
							printf("Settings unavailable now\n");
							break;
						case BUTTON_GAME:
							game_cycle(data);
							data->jumps.to_main = false;
							break;
						default:
							break;
					}
			}
			break;
	}
}

void	main_menu_cycle(t_data *data)
{
	SDL_Event	event;

	while (true)
	{
		menu_draw(data->menus.main);
		SDL_WaitEvent(&event);
		handle_event(&event, data);
		if (data->jumps.exit)
			break;
	}
}
