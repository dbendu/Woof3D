#include "private_menu.h"
#include "sdl_menu.h"
#include "mouse.h"

void	menu_draw(t_menu menu)
{
	SDL_SetRenderDrawColor(menu->render, 0, 0, 0, 0xff);
	SDL_RenderClear(menu->render);
	update_mouse(&menu->mouse);
	for (int i = 0; i < menu->buttons_count; ++i) {
		check_hover(menu->buttons[i], &menu->mouse.tip);
		button_draw(menu->buttons[i]);
	}
	drawMouse(menu->render, menu->mouse);
}
