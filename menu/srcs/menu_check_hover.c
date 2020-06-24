#include <stdbool.h>
#include "private_button.h"
#include "button.h"
#include <SDL2/SDL.h>
#include "data.h"
#include "private_menu.h"

bool	check_hover(t_button button, SDL_Rect *rect, int press, t_menu menu)
{
	if (SDL_HasIntersection(&button->btn_rect, rect))
	{
		button_select(button);
		if (press)
		{
			menu->selected_uid = button_uid(button);
			return (true);
		}
	}
	else if (button->selected)
		button_deselect(button);
	return (false);
}