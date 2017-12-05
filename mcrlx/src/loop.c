/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmckinno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 14:23:10 by tmckinno          #+#    #+#             */
/*   Updated: 2017/10/21 14:23:12 by tmckinno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mcrlx.h"
#include "clct.h"
#include "keys.h"

t_evloop	create_loop(t_window win, void *model)
{
	t_evloop	loop;

	NULL_GUARD((loop = memalloc(sizeof(struct s_evloop))));
	loop->window = win;
	REF_INC((loop->model = model));
	loop->on_init = NULL;
	loop->on_exit = NULL;
	loop->on_expose = NULL;
	loop->on_tick = NULL;
	loop->on_mouse_motion = NULL;
	REF_INC((loop->events = create_queue()));
	REF_INC((loop->handlers = init_handlers()));
	null_ptr_array((void**)loop->on_key_press, MAX_KC);
	null_ptr_array((void**)loop->on_key_release, MAX_KC);
	null_ptr_array((void**)loop->on_mouse_press, MAX_MOUSE);
	null_ptr_array((void**)loop->on_mouse_release, MAX_MOUSE);
	zero_int_array(loop->keys, MAX_KC);
	zero_int_array(loop->mouse, MAX_MOUSE);
	setup_hooks(loop, win->window);
	return (loop);
}

void		*evloop(void *lp)
{
	t_event		event;
	t_evloop	loop;
	int			i;

	i = 0;
	loop = (t_evloop)lp;
	if (loop->on_init)
		loop->on_init(lp);
	while (1)
	{
		if ((event = dequeue(loop->events, 1)))
		{
			loop->handlers[event->id](event, loop);
		}
		if (i++ == 50000000)
		{
			REF_SWP;
			REF_LOG;
			i = 0;
		}
	}
}

void		register_init_hook(t_evloop loop, t_genhandler handler)
{
	loop->on_init = handler;
}

void		register_exit_hook(t_evloop loop, t_genhandler handler)
{
	loop->on_exit = handler;
}
