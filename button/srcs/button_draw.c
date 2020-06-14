#include "private_button.h"
#include "button.h"

void	button_draw(const t_button button)
{
	if (button->selected) {
		SDL_SetRenderDrawColor(button->render, 0xff, 0xff, 0xff, 0xff);
	} else {
		SDL_SetRenderDrawColor(button->render, 0x67, 0x67, 0x67, 0xff);
	}
	SDL_RenderFillRect(button->render, &button->btn_rect);
	SDL_SetRenderDrawColor(button->render, 0x0, 0x0, 0x0, 0x0);
	SDL_RenderDrawRect(button->render, &button->btn_rect);
	if (button->title) {
		SDL_RenderCopy(button->render, button->title,
					   NULL, &button->title_rect);
	}
}
