#ifndef PRIVATE_BUTTON_H
#define PRIVATE_BUTTON_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <stdbool.h>

struct	s_button
{
	int32_t			uid;

	SDL_Renderer	*render;
	SDL_Rect		btn_rect;

	SDL_Texture		*title;
	SDL_Rect		title_rect;

	bool			selected;
};

#endif
