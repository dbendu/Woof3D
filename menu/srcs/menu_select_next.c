#include "private_menu.h"
#include "sdl_menu.h"

void	menu_select_next(t_menu menu)
{
	if (menu->selected_ind != menu->buttons_count - 1 ||
		menu->cycling)
	{
		button_deselect(menu->buttons[menu->selected_ind]);
		if (menu->selected_ind == menu->buttons_count - 1) {
			menu->selected_ind = 0;
		} else {
			menu->selected_ind += 1;
		}
		button_select(menu->buttons[menu->selected_ind]);
		menu->selected_uid = button_uid(menu->buttons[menu->selected_ind]);
	}
}
