#include "private_menu.h"
#include "sdl_menu.h"

static
t_button	*increase(t_button *buttons, int count)
{
	const int	new_size = count + BUTTONS_INCREASE;
	t_button	*new_buttons;

	new_buttons = malloc(sizeof(t_button) * new_size);
	for (int i = 0; i < count; ++i) {
		new_buttons[i] = buttons[i];
	}
	free(buttons);
	return (new_buttons);
}

void		menu_add_button(t_menu menu, t_button button)
{
	if (menu->buttons_count == menu->buttons_allocated) {
		menu->buttons = increase(menu->buttons,
								 menu->buttons_count);
	}
	menu->buttons[menu->buttons_count] = button;
	if (menu->buttons_count == 0) {
		button_select(menu->buttons[0]);
		menu->selected_ind = 0;
		menu->selected_uid = button_uid(button);
	}
	menu->buttons_count += 1;
}
