/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmckinno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 12:41:12 by tmckinno          #+#    #+#             */
/*   Updated: 2017/12/04 12:41:14 by tmckinno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		jitr(t_point_d z, t_point_d c, int limit)
{
	double		x;
	double		y;
	t_point_d	squared;
	int			q;

	x = z[0];
	y = z[1];
	SET_TUPLE(squared, x * x, y * y);
	q = 0;
	while (squared[0] + squared[1] <= 4 && q < limit)
	{
		y = x * y;
		y = y + y + c[1];
		x = squared[0] - squared[1] + c[0];
		SET_TUPLE(squared, x * x, y * y);
		q++;
	}
	if (q < limit)
		return (q);
	return (0);
}

int		julia_iter_limit(double scale)
{
	double	ans;

	ans = ceil(sqrt(fabs(2.0 * sqrt(fabs(1 - sqrt(5 * scale / 200))))) * 66.5);
	return ((int)ans);
}

void	render_julia(t_buffer buf, void *data)
{
	t_point		pos;
	t_point_d	c;
	t_state		st;
	int			i;

	st = (t_state)data;
	i = julia_iter_limit(st->scale);
	pos[0] = buf->tl[0];
	while (pos[0] < buf->tl[0] + buf->size[0])
	{
		pos[1] = buf->tl[1];
		while (pos[1] < buf->tl[1] + buf->size[1])
		{
			c[0] = (st->offset[0] + pos[0]) / st->scale;
			c[1] = (st->offset[1] + pos[1]) / st->scale;
			if ((!(pos[0] % 10) || !(pos[1] % 10)) && DEBUG_GRID_ENABLED)
				buf_set_pixel(buf, pos[0], pos[1], pack_color(252, 67, 73));
			else
				buf_set_pixel(buf, pos[0], pos[1], colr(st, jitr(c, st->c, i)));
			pos[1] += 1;
		}
		pos[0] += 1;
	}
}

t_state	init_julia(void)
{
	t_state	state;

	NULL_GUARD((state = (t_state)memalloc_inc(sizeof(struct s_state))));
	state->scale = 500.0;
	state->offset[0] = 0;
	state->offset[1] = 0;
	state->changed = 1;
	state->mode = &render_julia;
	state->c[0] = -0.725000;
	state->c[1] = 0.188150;
	return (state);
}
