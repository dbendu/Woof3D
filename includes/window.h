#ifndef WINDOW_H
# define WINDOW_H

# include <SDL2/SDL.h>
# include <stdbool.h>
typedef	struct	s_window
{
	SDL_Window		*window;
	SDL_Surface		*surface;
	SDL_Renderer	*renderer;
	bool			state;
}				t_window;

#endif