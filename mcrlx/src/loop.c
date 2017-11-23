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

t_evloop    create_loop(t_window win, void *model)
{
	t_evloop    loop;
	
	NULL_GUARD((loop = memalloc(sizeof(struct s_evloop))));
	loop->window = win;
	REF_INC((loop->model = model));
	loop->on_init = NULL;
	loop->on_exit = NULL;
	loop->on_expose = NULL;
	loop->on_tick = NULL;
	loop->on_mouse_motion = NULL;
	REF_INC((loop->events = create_queue()));
	// printf("lock id: %i\n", loop->events->lock);
	REF_INC((loop->handlers = init_handlers()));
	// printf("lock id: %i\n", loop->events->lock);
	null_ptr_array((void**)loop->on_key_press, MAX_KC);
	null_ptr_array((void**)loop->on_key_release, MAX_KC);
	null_ptr_array((void**)loop->on_mouse_press, MAX_MOUSE);
	null_ptr_array((void**)loop->on_mouse_release, MAX_MOUSE);
	zero_int_array(loop->keys, MAX_KC);
	zero_int_array(loop->mouse, MAX_MOUSE + 2);
	// printf("l %p, w %i\n", loop->events, loop->events->lock);
	setup_hooks(loop, win->window);
	return (loop);
}

void		*evloop(void *lp)
{
	t_event		event;
	t_evloop	loop;
	int  i;

	i = 0;
	loop = (t_evloop)lp;
	printf("starting event loop\n");
	if (loop->on_init)
		loop->on_init(lp);
	// printf("lock id loop: %i\n", loop->events->lock);
	while (1)
	{
		// printf("events: %p\n", loop->events);
		if ((event = dequeue(loop->events, 1)))
		{
			// printf("Got Event %i\n", event->id);
			loop->handlers[event->id](event, loop);
		}
		// printf("%p\n", event)
		if (i++ == 50000000)
		{
			REF_SWP;
			REF_LOG;
			i = 0;
		}
	}
}

void		*mcrlx_start_inner(void *display)
{
	mlx_loop(((t_display)display)->mlx);
	return (NULL);
}

pthread_t	mcrlx_start(void)
{
	t_display	display;
	pthread_t	thread;
	int			i;

	display = get_display();
	// pthread_create(&thread, NULL, &mcrlx_start_inner, display);
	i = 0;
	while (i < display->count)
		pthread_create(&thread, NULL, &evloop, display->windows[i++]->loop);
			// pthread_create((ids + buffer), NULL, &iter_func_wrapper, (void*)rdata);
	mlx_loop(display->mlx);
	return (thread);
}

void		register_tick_hook(t_evloop loop, t_genhandler handler)
{
	loop->on_tick = handler;
}

void		register_expose_hook(t_evloop loop, t_genhandler handler)
{
	loop->on_expose = handler;
}

void		register_init_hook(t_evloop loop, t_genhandler handler)
{
	loop->on_init = handler;
}

void		register_exit_hook(t_evloop loop, t_genhandler handler)
{
	loop->on_exit = handler;
}

void		register_key_hook(t_evloop loop, t_keyhandler handler, int kc, int state)
{
	if (state)
		loop->on_key_press[kc] = handler;
	else
		loop->on_key_release[kc] = handler;
}

void		register_mouse_hook(t_evloop loop, t_mousehandler handler,
								int btn, int state)
{
	if (state)
		loop->on_mouse_press[btn] = handler;
	else
		loop->on_mouse_release[btn] = handler;
}

void		register_motion_hook(t_evloop loop, t_motionhandler handler)
{
	loop->on_mouse_motion = handler;
}