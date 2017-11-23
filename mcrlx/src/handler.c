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

# include "mcrlx.h"


void	init_handler(t_event event, t_evloop loop)
{
	if(loop->on_init)
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

void	mouse_handler(t_event event, t_evloop loop)
{
	if (event->state)
	{
		if (loop->on_mouse_press[event->kc])
			loop->on_mouse_press[event->kc](event->kc, event->x, event->y, loop);
	}
	else
	{
		if (loop->on_mouse_release[event->kc])
			loop->on_mouse_release[event->kc](event->kc, event->x, event->y, loop);
	}
	REF_DEC(event);
}

void	motion_handler(t_event event, t_evloop loop)
{
	if (loop->on_mouse_motion)
		loop->on_mouse_motion(event->mpos_cur, event->mpos_prev, loop);
	REF_DEC(event);
}

void	tick_handler(t_event event, t_evloop loop)
{
	if (loop->on_tick)
		loop->on_tick(loop);
	// printf("TICK!!\n");
	REF_DEC(event);
}

t_handlers	init_handlers(void)
{
	t_handlers	handlers;

	handlers = (t_handlers)memalloc(sizeof(t_handler) * MAX_EVENTS);
	handlers[EV_INIT] = &init_handler;
	handlers[EV_EXIT] = &exit_handler;
	handlers[EV_EXPOSE] = &expose_handler;
	handlers[EV_KEY] = &key_handler;
	handlers[EV_MOUSE] = &mouse_handler;
	handlers[EV_MOTION] = &motion_handler;
	handlers[EV_TICK] = &tick_handler;
	return (handlers);
}