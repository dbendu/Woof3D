#include "Woof3D.h"
#include "sdl_menu.h"
#include <stdio.h>

static
void	handle_event(t_data *data)
{
	int32_t		uid;

	uid = menu_selected_uid(data->menus.main);
	switch (uid)
	{
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

void	main_menu_cycle(t_data *data)
{
	bool		ev;
	SDL_Event	event;

	while (true)
	{
		ev = menu_draw(data->menus.main);
		SDL_UpdateWindowSurface(data->wnd.window);
		SDL_WaitEvent(&event);
		(void)event;
		if (ev)
			handle_event(data);
		if (data->jumps.exit)
			break;
	}
}
