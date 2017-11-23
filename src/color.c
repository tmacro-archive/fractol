#include "fractol.h"

int		continuous_color(double z)
{
	int r;
	int g;
	int b;

	r = sin(0.016 * z + 0) * 127.5 + 127.5;
	g = sin(0.013 * z + 2) * 127.5 + 127.5;
	b = sin(0.01 * z + 4) * 127.5 + 127.5;
	return (pack_color(r, g, b));
}