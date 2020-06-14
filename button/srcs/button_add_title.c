#include "private_button.h"
#include "button.h"

void	button_add_title(t_button button, const char *title, TTF_Font *font)
{
	SDL_Surface	*text_srf;
	SDL_Color	fgcolor = {0x0, 0x0, 0x0, 0xff};

	if (button->title) {
		SDL_DestroyTexture(button->title); // clean previous title
	}
	text_srf = TTF_RenderText_Blended(font, title, fgcolor);
	button->title = SDL_CreateTextureFromSurface(button->render, text_srf);
	SDL_FreeSurface(text_srf);
	SDL_QueryTexture(button->title, NULL, NULL, &button->title_rect.w,
												&button->title_rect.h);
	button->title_rect.x = button->btn_rect.x +
						   button->btn_rect.w / 2 - button->title_rect.w / 2;
	button->title_rect.y = button->btn_rect.y +
						   button->btn_rect.h / 2 - button->title_rect.h / 2;
}
