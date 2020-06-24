#include "private_menu.h"
#include "sdl_menu.h"
#include "mouse.h"
#include <stdbool.h>

bool	menu_draw(t_menu menu)
{
	int		press;
	bool	cont;

	cont = 0;
	SDL_SetRenderDrawColor(menu->render, 0, 0, 0, 0xff);
	SDL_RenderClear(menu->render);
	press = update_mouse(&menu->mouse);
	for (int i = 0; i < menu->buttons_count; ++i) {
		cont += check_hover(menu->buttons[i], &menu->mouse.tip, press, menu);
		button_draw(menu->buttons[i]);
	}
	drawMouse(menu->render, menu->mouse);
	return (cont);
}
