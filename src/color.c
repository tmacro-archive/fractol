/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmckinno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 15:37:33 by tmckinno          #+#    #+#             */
/*   Updated: 2017/12/01 15:37:34 by tmckinno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_color	sine_gen(t_color s, t_color e, int z)
{
	t_color color;

	color.r = sin(s.r + e.r * z) * 127.5 + 127.5;
	color.g = sin(s.g + e.g * z) * 127.5 + 127.5;
	color.b = sin(s.b + e.b * z) * 127.5 + 127.5;
	return (color);
}

t_color	grad_gen(t_color s, t_color e, int z)
{
	return (step_to_color(s, e, z));
}

int		colr(t_state state, int step)
{
	t_color	color;

	if (!step)
		return (pack_color(0, 0, 0));
	color = state->color(state->cstart, state->cend, step);
	return (pack_color(color.r, color.g, color.b));
}
