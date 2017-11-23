/* ************************************************************************** */
/*                                                                            */
/*   mandel_new.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmckinno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 13:41:40 by tmckinno          #+#    #+#             */
/*   Updated: 2017/11/14 13:41:42 by tmckinno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "fmath.h"

t_state	init_mandelbrot(void)
{
	t_state	state;

	NULL_GUARD((state = (t_state)memalloc(sizeof(struct s_state))));
	state->scale = 4.0;
	state->offset[0] = 0;
	state->offset[1] = 0;
	state->changed = 1;
	state->mode = &render_mandelbrot;
	return (state);
}



void	init_mandel_fract(t_fract *fract, t_point pos, double scale, t_point size)
{
	fract->c.x = pos[0] * scale / (double)size[0];
	fract->c.y = pos[1] * scale / (double)size[1];
	fract->z.x = 0.0;
	fract->z.y = 0.0;
}

int		mandel_iter_point(t_fract *fract, int limit)
{
	int		iters;
	t_cplx	z;
	t_cplx	c;
	double	tmp;

	z = fract->z;
	c = fract->c;
	iters = 0;
	while (z.x * z.x + z.y * z.y <= 4 && iters < limit)
	{
		// z = cplx_add(cplx_sqr(z), c);
		tmp = z.x * z.x - z.y * z.y + c.x;
		z.y = 2 * z.x * z.y + c.y;
		z.x = tmp;
		iters++;
	}
	if (iters < limit)
		return (continuous_color(iters + 1.0 - (log(2) / sqrt(z.x * z.x + z.y * z.y)) / log (2)));
	return (pack_color(0, 0, 0));
}

void	render_mandelbrot_inner(int x, int y, void *data)
{
	t_fseed	*seed;
	t_point	pos;

	seed = (t_fseed*)data;
	SET_TUPLE(pos, x + seed->state->offset[0], y + seed->state->offset[1]);
	seed->fract.c.x = pos[0] * seed->state->scale / (double)seed->buf->frame->window->width;
	seed->fract.c.y = pos[1] * seed->state->scale / (double)seed->buf->frame->window->width;
	seed->fract.z.x = 0.0;
	seed->fract.z.y = 0.0;
	buf_set_pixel(seed->buf, x, y, mandel_iter_point(&seed->fract, 100));
}

void	render_mandelbrot(t_buffer buffer, void *data)
{
	t_state state;
	t_point max;
	t_fseed seed;

	state = (t_state)data;
	max[0] = buffer->tl[0] + buffer->size[0];
	max[1] = buffer->tl[1] + buffer->size[1];
	seed.state = state;
	seed.buf = buffer;
	iter_grid(buffer->tl, max, render_mandelbrot_inner, &seed);
}
