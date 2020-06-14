#include "data.h"
#include "WoofDefines.h"
#include "init_all.h"

double	clampYaw(double y)
{
	double temp = (y + 180.0f) / 360.0f;
	return y - ((int)temp - (temp < 0.0f ? 1 : 0)) * 360.0f;
}


void	mouseCapture(t_data *data, SDL_MouseMotionEvent mouse)
{
	double		deltaX;
	const double sensitivity = 0.001f;
	double		yaw = 0.0;

	deltaX = (double)(mouse.xrel - WND_WIDTH);
	// deltaY = (double)(mouse.y - WND_HEIGHT / 2);
	yaw = clampYaw(yaw + sensitivity * deltaX);
	data->map.hero.pov += yaw;
	printf("x = %d, y = %d\t\t\tyaw = %f\n\n", mouse.xrel, mouse.xrel, yaw);
}
