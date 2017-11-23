#include "fractol.h"
#include <stdio.h>
#include "clct.h"

int		main(int ac, char **av)
{
	t_args		args;

	args = parse_args(ac, av);
	// if (args->error)
	// 	log_error(args->error);
	if (!args->error && args->mandel)
		create_app(init_mandelbrot());
	if (!args->error && args->julia)
		create_app(init_julia());
	if (!args->error && (args->julia || args->mandel))
		mcrlx_start();
	return (0);
}