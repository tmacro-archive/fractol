/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmckinno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 11:32:10 by tmckinno          #+#    #+#             */
/*   Updated: 2017/10/30 11:32:11 by tmckinno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mcrlx.h"

void	init_handler(t_event event, t_evloop loop)
{
	if (loop->on_init)
		loop->on_init(loop);
	REF_DEC(event);
}

void	exit_handler(t_event event, t_evloop loop)
{
	if (loop->on_exit)
		loop->on_exit(loop);
	REF_DEC(event);
}

void	expose_handler(t_event event, t_evloop loop)
{
	if (loop->on_expose)
		loop->on_expose(loop);
	REF_DEC(event);
}

void	key_handler(t_event event, t_evloop loop)
{
	if (event->state)
	{
		if (loop->on_key_press[event->kc])
			loop->on_key_press[event->kc](event->kc, loop);
	}
	else
	{
		if (loop->on_key_release[event->kc])
			loop->on_key_release[event->kc](event->kc, loop);
	}
	REF_DEC(event);
}

void	mouse_handler(t_event event, t_evloop lp)
{
	if (event->state)
	{
		if (lp->on_mouse_press[event->kc])
			lp->on_mouse_press[event->kc](event->kc, event->x, event->y, lp);
	}
	else
	{
		if (lp->on_mouse_release[event->kc])
			lp->on_mouse_release[event->kc](event->kc, event->x, event->y, lp);
	}
	REF_DEC(event);
}
