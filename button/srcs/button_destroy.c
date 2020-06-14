#include "private_button.h"
#include "button.h"

inline
void	button_destroy(t_button button)
{
	if (button->title) {
		SDL_DestroyTexture(button->title);
	}
	free(button);
}
