#include "private_menu.h"
#include "sdl_menu.h"

void	menu_select_button(t_menu menu, int32_t uid)
{
	int	btn_ind;

	btn_ind = 0;
	while (btn_ind < menu->buttons_count &&
		   uid != button_uid(menu->buttons[btn_ind])) {
		btn_ind += 1;
	}
	if (btn_ind != menu->buttons_count && btn_ind != menu->selected_ind) {
		button_deselect(menu->buttons[menu->selected_ind]);
		button_select(menu->buttons[btn_ind]);
		menu->selected_ind = btn_ind;
		menu->selected_uid = uid;
	}
}
