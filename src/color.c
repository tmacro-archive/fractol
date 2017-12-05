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

int	cont_color(double z)
{
	int r;
	int g;
	int b;

	r = sin(0.016 * z + 0) * 127.5 + 127.5;
	g = sin(0.013 * z + 2) * 127.5 + 127.5;
	b = sin(0.01 * z + 4) * 127.5 + 127.5;
	return (pack_color(r, g, b));
}

int	gen_color(int z)
{
	int r;
	int g;
	int b;

	r = sin(1.666 * z + 0) * 200 * 55;
	g = sin(2.666 * z + 2) * 200 * 55;
	b = sin(4.666 * z + 4) * 200 * 55;
	return (pack_color(r, g, b));
}

int	colr(t_state state, int step)
{
	t_color	color;

	if (!step)
		return (pack_color(0,0,0));

	color = step_to_color(state->cstart, state->cend, step);
	return (pack_color(color.rgb.r, color.rgb.g, color.rgb.b));
}