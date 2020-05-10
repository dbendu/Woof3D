#include "data.h"
#include "WoofDefines.h"

#include <SDL2/SDL_image.h>
#include <SDL2/SDL.h>
#include "ft_utils.h"
#include "mouse.h"

double	clampYaw(double y)
{
	double temp = (y + 180.0f) / 360.0f;
	return y - ((int)temp - (temp < 0.0f ? 1 : 0)) * 360.0f;
}


void	mouseCapture(t_data *data, SDL_MouseMotionEvent mouse)
{
	// if (mouse.xrel != -1 || mouse.xrel != 1)
	// 	mouse.xrel = 0;
	data->map.hero.pov -= mouse.xrel;
	if (data->map.hero.pov >= 360)
		data->map.hero.pov -= 360;
	else if (data->map.hero.pov < 0)
		data->map.hero.pov += 360;
	// printf("xrel = %d\n", mouse.x);
}

t_mouse		mouseInit(t_data data, const char *path, int w, int h)
{
	t_mouse		m;

	m.texture = IMG_LoadTexture(data.wnd.renderer, path);
	m.cursor.h = h;
	m.cursor.w = w;
	m.cursor.x = 0;
	m.cursor.y = 0;
	m.tip.h = 1;
	m.tip.w = 1;
	m.tip.x = 0;
	m.tip.y = 0;
	return (m);
}

void	drawMouse(t_data data, t_mouse mouse)
{
	if (SDL_RenderCopy(data.wnd.renderer, mouse.texture, NULL, &mouse.cursor) < 0)
		ft_error(SDL_GetError(), "cannot render the mouse", 0);
}