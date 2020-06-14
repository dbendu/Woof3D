#include "private_menu.h"
#include "sdl_menu.h"

void	menu_draw(t_menu menu)
{
	SDL_SetRenderDrawColor(menu->render, 0, 0, 0, 0xff);
	SDL_RenderClear(menu->render);
	for (int i = 0; i < menu->buttons_count; ++i) {
		button_draw(menu->buttons[i]);
	}
	SDL_RenderPresent(menu->render);
}
