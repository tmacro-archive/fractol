/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmckinno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 13:56:46 by tmckinno          #+#    #+#             */
/*   Updated: 2017/11/12 13:56:47 by tmckinno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	print_help(char *name)
{
	ft_putstr("Usage: ");
	ft_putstr(name);
	ft_putstr(" <mode> [--gradient, --sine]");
	ft_putstr(" [--start <color>] [--end <color>]\n");
}

void	e_handler(t_evloop loop)
{
	t_evloop	lp;

	lp = loop;
	REF_LOG;
	REF_CLN;
	REF_LOG;
	exit(0);
}

void	esc_handler(int c, t_evloop loop)
{
	c = 0;
	e_handler(loop);
}

void	reset_handler(int kc, t_evloop loop)
{
	t_state state;
	t_state def;

	kc = 0;
	state = (t_state)(loop->model);
	def = state->reset();
	state->scale = def->scale;
	DUP_TUPLE(state->offset, def->offset);
	DUP_TUPLE(state->c, def->c);
	state->changed = 1;
}
/*
** ft_putstr("Multiple arguments can be specified\n");
*/
