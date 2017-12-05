/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmckinno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 15:38:30 by tmckinno          #+#    #+#             */
/*   Updated: 2017/12/01 15:38:32 by tmckinno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	plus_handler(int kc, t_evloop loop)
{
	t_state	state;

	state = (t_state)(loop->model);
	state->changed = 1;
	state->scale *= 1.01;
	printf("%f\n", state->scale);
}

void	minus_handler(int kc, t_evloop loop)
{
	t_state	state;

	state = (t_state)(loop->model);
	if (state->scale == 0)
		return ;
	state->changed = 1;
	state->scale *= 0.99;
	if (state->scale < 0)
		state->scale = 0;
	printf("%f\n", state->scale);
}

void	render_handler(t_evloop loop)
{
	t_state		state;

	state = (t_state)(loop->model);
	if (state->changed)
	{
		threaded_render(loop->window->frame, state->mode, loop->model);
		state->changed = 0;
	}
}

void	arrow_handler(int kc, t_evloop loop)
{
	t_state state;

	state = (t_state)(loop->model);
	if (kc == KEY_LEFT)
		state->offset[0] += 5;
	if (kc == KEY_RIGHT)
		state->offset[0] -= 5;
	if (kc == KEY_UP)
		state->offset[1] += 5;
	if (kc == KEY_DOWN)
		state->offset[1] -= 5;
	state->changed = 1;
}

void	pan_handler(t_point cur, t_point prev, t_evloop loop)
{
	int		delta_x;
	int		delta_y;
	t_state	state;

	state = (t_state)(loop->model);
	if ((!prev[0] && !prev[1]))
		return ;
	delta_x = cur[0] - prev[0];
	delta_y = cur[1] - prev[1];
	if (GET_KEY(loop->keys, KEY_LCTRL) || GET_KEY(loop->keys, KEY_RCTRL))
	{
		state->offset[0] -= delta_x;
		state->offset[1] += delta_y;
		state->changed = 1;
	}
	if (GET_KEY(loop->keys, KEY_LOPT) || GET_KEY(loop->keys, KEY_ROPT))
	{
		state->c[0] += (delta_x > 0) ? (0.0005) : (-0.0005);
		state->c[1] += (delta_y > 0) ? (0.0005) : (-0.0005);
		state->changed = 1;
	}
}
