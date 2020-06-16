#include <stdbool.h>
#include "private_button.h"
#include "button.h"
#include <SDL2/SDL.h>
#include "data.h"
#include "private_menu.h"

void	check_hover(t_button button, SDL_Rect *rect)
{
	if (SDL_HasIntersection(&button->btn_rect, rect))
		button_select(button);
	else if (button->selected)
		button_deselect(button);
}