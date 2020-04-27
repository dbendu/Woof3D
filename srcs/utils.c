#include <SDL2/SDL.h>

double			ft_map(double value, double start_range, double end_range, double new_range_start, double new_range_end)
{
	return ((value - start_range) / (end_range - start_range) *
				(new_range_end - new_range_start) + new_range_start);
}

int32_t    pack_color(int alpha, int red, int green, int blue)
{
    return ((alpha << 24) | (red << 16) | (green << 8) | blue);
}
