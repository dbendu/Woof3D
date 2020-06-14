#include "private_menu.h"
#include "sdl_menu.h"

void	menu_destroy(t_menu menu)
{
	for (int btn = 0; btn < menu->buttons_count; ++btn) {
		button_destroy(menu->buttons[btn]);
	}
	free(menu->buttons);
	free(menu);
}
