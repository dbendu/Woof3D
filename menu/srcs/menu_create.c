#include "private_menu.h"
#include "sdl_menu.h"

t_menu	menu_create(SDL_Renderer *render, bool cycling)
{
	t_menu	menu;

	menu = malloc(sizeof(struct s_menu));
	menu->render = render;
	menu->cycling = cycling;
	menu->buttons_allocated = BUTTONS_INCREASE;
	menu->buttons_count = 0;
	menu->buttons = malloc(sizeof(t_button) * BUTTONS_INCREASE);
	return (menu);
}
