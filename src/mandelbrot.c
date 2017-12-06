/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmckinno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 15:40:03 by tmckinno          #+#    #+#             */
/*   Updated: 2017/12/01 15:40:04 by tmckinno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		iter_point(t_point_d c, int limit)
{
	double	x;
	double	y;
	double	tmp;
	int		q;

	x = 0;
	y = 0;
	q = 0;
	while (x * x + y * y <= 4 && q < limit)
	{
		tmp = x * x - y * y + c[0];
		y = 2 * x * y + c[1];
		x = tmp;
		q++;
	}
	if (q < limit)
		return (q);
	return (0);
}

int		mandel_iter_limit(double scale)
{
	double	ans;

	ans = ceil(sqrt(fabs(2.0 * sqrt(fabs(1 - sqrt(5 * scale / 200))))) * 66.5);
	return ((int)ans);
}

void	render_mandelbrot(t_buffer buf, void *data)
{
	t_point		pos;
	t_point_d	c;
	t_state		st;
	int			i;

	st = (t_state)data;
	i = mandel_iter_limit(st->scale);
	pos[0] = buf->tl[0];
	while (pos[0] < buf->tl[0] + buf->size[0])
	{
		pos[1] = buf->tl[1];
		while (pos[1] < buf->tl[1] + buf->size[1])
		{
			c[0] = ((st->offset[0] + pos[0]) / st->scale);
			c[1] = ((st->offset[1] + pos[1]) / st->scale);
			if ((!(pos[0] % 10) || !(pos[1] % 10)) && DEBUG_GRID_ENABLED)
				buf_set_pixel(buf, pos[0], pos[1], pack_color(252, 67, 73));
			else
				buf_set_pixel(buf, pos[0], pos[1], colr(st, iter_point(c, i)));
			pos[1] += 1;
		}
		pos[0] += 1;
	}
}

t_state	init_mandelbrot(void)
{
	t_state	state;

	NULL_GUARD((state = (t_state)memalloc_inc(sizeof(struct s_state))));
	state->scale = 500.0;
	state->offset[0] = 0;
	state->offset[1] = 0;
	state->changed = 1;
	state->mode = &render_mandelbrot;
	state->c[0] = 0;
	state->c[1] = 0;
	return (state);
}
