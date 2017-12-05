/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmckinno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 17:38:56 by tmckinno          #+#    #+#             */
/*   Updated: 2017/12/04 17:38:58 by tmckinno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mcrlx.h"

t_event		create_event(int id)
{
	t_event fresh;

	NULL_GUARD((fresh = memalloc_inc(sizeof(struct s_event))));
	fresh->id = id;
	fresh->kc = 0;
	fresh->x = 0;
	fresh->y = 0;
	fresh->state = 0;
	return (fresh);
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
