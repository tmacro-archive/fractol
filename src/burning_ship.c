/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmckinno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 17:04:45 by tmckinno          #+#    #+#             */
/*   Updated: 2017/12/04 17:04:47 by tmckinno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		bship_iter(t_point_d c, int limit)
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
		y = 2 * fabs(x * y) + c[1];
		x = tmp;
		q++;
	}
	if (q < limit)
		return (cont_color(q + 1.0 - (log(2) / sqrt(x * x + y * y)) / log(2)));
	return (pack_color(0, 0, 0));
}

int		bship_iter_limit(double scale)
{
	double	ans;

	ans = ceil(sqrt(fabs(2.0 * sqrt(fabs(1 - sqrt(5 * scale / 200))))) * 66.5);
	return ((int)ans);
}

void	render_bship(t_buffer buffer, void *data)
{
	t_point		pos;
	t_point_d	c;
	t_state		st;
	int			iters;

	st = (t_state)data;
	iters = bship_iter_limit(st->scale);
	pos[0] = buffer->tl[0];
	while (pos[0] < buffer->tl[0] + buffer->size[0])
	{
		pos[1] = buffer->tl[1];
		while (pos[1] < buffer->tl[1] + buffer->size[1])
		{
			c[0] = ((st->offset[0] + pos[0]) / st->scale) + st->zoomc[0];
			c[1] = ((st->offset[1] + pos[1]) / st->scale) + st->zoomc[1];
			if ((!(pos[0] % 10) || !(pos[1] % 10)) && DEBUG_GRID_ENABLED)
				buf_set_pixel(buffer, pos[0], pos[1], pack_color(252, 67, 73));
			else
				buf_set_pixel(buffer, pos[0], pos[1], bship_iter(c, iters));
			pos[1] += 1;
		}
		pos[0] += 1;
	}
}

t_state	init_bship(void)
{
	t_state	state;

	NULL_GUARD((state = (t_state)memalloc(sizeof(struct s_state))));
	state->scale = 4310.766732;
	state->offset[0] = -6995;
	state->offset[1] = -445;
	state->changed = 1;
	state->mode = &render_bship;
	state->c[0] = 0;
	state->c[1] = 0;
	return (state);
}
