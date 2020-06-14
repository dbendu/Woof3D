#include "Woof3D.h"
#include "menu.h"

static
void	input_handle(const SDL_Event *event, t_data *data)
{
	int32_t	uid;

	switch (event->type) {
		case SDL_QUIT:
			data->jumps.exit = true;
			break;
		case SDL_KEYDOWN:
			switch (event->key.keysym.sym) {
				case SDLK_ESCAPE:
					data->jumps.to_game = true;
					break;
				case SDLK_DOWN:
					menu_select_next(data->menus.pause);
					break;
				case SDLK_UP:
					menu_select_prev(data->menus.pause);
					break;
				case SDLK_RETURN:
					uid = menu_selected_uid(data->menus.pause);
					switch (uid) {
						case BUTTON_CONTINUE:
							data->jumps.to_game = true;
							break;
						case BUTTON_TO_MAIN:
							data->jumps.to_main = true;
							break;
						case BUTTON_EXIT:
							data->jumps.exit = true;
							break;
						default:
							break;
					}
			}
	}
}

void	pause_cycle(t_data *data)
{
	SDL_Event	event;

	while (true)
	{
		menu_draw(data->menus.pause);
		SDL_WaitEvent(&event);
		input_handle(&event, data);
		if (data->jumps.exit) {
			//TODO: exit
			exit(0);
		} else if (data->jumps.to_game || data->jumps.to_main) {
			break;
		}
	}
	data->jumps.to_game = false;
	menu_select_button(data->menus.pause, BUTTON_CONTINUE);
}
