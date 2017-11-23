#include "fractol.h"
// int	gen_color(int z)
// {
// 	int r;
// 	int g;
// 	int b;

// 	r = sin(1.666 * z + 0) * 200 * 55;
// 	g = sin(2.666 * z + 2) * 200 * 55;
// 	b = sin(4.666 * z + 4) * 200 * 55;
// 	return (pack_color(r, g, b));
// }

// int		continuous_color(double z)
// {
// 	int r;
// 	int g;
// 	int b;

// 	r = sin(0.016 * z + 0) * 127.5 + 127.5;
// 	g = sin(0.013 * z + 2) * 127.5 + 127.5;
// 	b = sin(0.01 * z + 4) * 127.5 + 127.5;
// 	return (pack_color(r, g, b));
// }

// int     iter_point(t_point pos, t_point_d c, int limit)
// {
//     double 	x;
//     double	y;
//     double	tmp;
// 	int		q;

// 	x = 0;
// 	y = 0;
// 	q = 0;
// 	while (x * x + y * y <= 4 && q < limit)
// 	{
// 		tmp = x * x - y * y + c[0];
// 		y = 2 * x * y + c[1];
// 		x = tmp;
// 		q++;
// 	}
// 	if (q < limit)
// 		return (continuous_color(q + 1.0 - (log(2) / sqrt(x * x + y * y)) / log (2)));
// 	return (pack_color(0, 0, 0));
// }

// int		mandel_iter_limit(double scale)
// {
// 	double	ans;

// 	ans = ceil(sqrt(fabs(2.0 * sqrt( fabs(1 - sqrt(5 * scale))))) * 66.5);
// 	// printf("iter: %f\n", ans);
// 	return ((int)ans - 25);
// }

// void    render_mandelbrot(t_buffer buffer, void *data)
// {
//     t_point		pos;
// 	t_point_d	c;
// 	t_state		state;
// 	t_point		offset;

// 	state = (t_state)data;
// 	// printf("tl: %i, %i - rndros: %i, %i - scale: %f - iter count: %i\n", buffer->tl[0], buffer->tl[1], buffer->rndros[0], buffer->rndros[1], state->scale, mandel_iter_limit(state->scale));
// 	pos[0] = buffer->tl[0];
// 	while (pos[0] < buffer->tl[0] + buffer->size[0])
// 	{
// 		pos[1] = buffer->tl[1];
// 		while (pos[1] < buffer->tl[1] + buffer->size[1])
// 		{
// 			offset[0] = pos[0] + state->offset[0];
// 			offset[1] = pos[1] + state->offset[1];
// 			c[0] = offset[0] * state->scale / (double)(buffer->frame->window->width);
// 			c[1] = offset[1] * state->scale / (double)(buffer->frame->window->height);
// 			buf_set_pixel(buffer, pos[0], pos[1], iter_point(offset, c, mandel_iter_limit(state->scale)));			
// 			pos[1] += 1;
// 		}
// 		pos[0] += 1;
// 	}
// }

// void    render_mandelbrot(t_buffer buffer, void *data)
// {
//     t_fract     fract;
//     t_point		pos;
// 	t_state		state;
//     int         iter;
// 	t_cplx		scale;

// 	state = (t_state)data;
// 	scale.x = state->scale / (double)(buffer->frame->window->width);
// 	scale.y = state->scale / (double)(buffer->frame->window->height);
// 	// printf("tl: %i, %i - rndros: %i, %i - scale: %f - iter count: %i\n", buffer->tl[0], buffer->tl[1], buffer->rndros[0], buffer->rndros[1], state->scale, mandel_iter_limit(state->scale));
// 	pos[0] = buffer->tl[0] + state->offset[0];
// 	while (pos[0] < buffer->tl[0] + buffer->size[0] + state->offset[0])
// 	{
//     	pos[1] = buffer->tl[1] + state->offset[1];
// 		while (pos[1] < buffer->tl[1] + buffer->size[1] + state->offset[1])
// 		{
// 			fract.c.x = pos[0] * scale.x;
// 			fract.c.y = pos[1] * scale.y;
// 			fract.z.x = 0;
// 			fract.z.y = 0;
//             iter = 0;
//             while (fract.z.x * fract.z.x + fract.z.y * fract.z.y <= 4 && iter < mandel_iter_limit(state->scale))
//             {
//                 fract.tmp = fract.z.x * fract.z.x - fract.z.y * fract.z.y + fract.c.x;
//                 fract.z.y = 2 * fract.z.x * fract.z.y + fract.c.y;
//                 fract.z.x = fract.tmp;
//                 iter++;
//             }
//             if (iter < mandel_iter_limit(state->scale))
// 			    buf_set_pixel(buffer, pos[0] - state->offset[0], pos[1] - state->offset[1], gen_color(iter));
//             else
//                 buf_set_pixel(buffer, pos[0] - state->offset[0], pos[1] - state->offset[1], pack_color(0, 0, 0));
// 			pos[1] += 1;
// 		}
// 		pos[0] += 1;
// 	}
// }

// t_state	init_mandelbrot(void)
// {
// 	t_state	state;

// 	NULL_GUARD((state = (t_state)memalloc(sizeof(struct s_state))));
// 	state->scale = 4.0;
// 	state->offset[0] = 0;
// 	state->offset[1] = 0;
// 	state->changed = 1;
// 	state->mode = &render_mandelbrot;
// 	return (state);
// }