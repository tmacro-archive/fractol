/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmckinno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 12:03:51 by tmckinno          #+#    #+#             */
/*   Updated: 2017/10/23 12:03:53 by tmckinno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mcrlx.h"

int		on_expose(t_evloop loop)
{
	t_event ev;

	ERR_CNR((ev = create_event(EV_EXPOSE)), NULL, -1);
	enqueue(loop->events, ev, 1);
	return (0);
}

int		on_tick(t_evloop loop)
{
	static int	count;
	t_event		ev;

	if (count++ < TICK_FREQ)
		return (0);
	else
		count = 0;
	ERR_CNR((ev = create_event(EV_TICK)), NULL, -1);
	enqueue(loop->events, ev, 1);
	return (0);
}

int		on_destroy(t_evloop loop)
{
	t_event ev;

	ERR_CNR((ev = create_event(EV_EXIT)), NULL, -1);
	enqueue(loop->events, ev, 1);
	return (0);
}

void	setup_hooks(t_evloop loop, t_window window)
{
	mlx_hook(window, 2, 0, &on_key_press, loop);
	mlx_hook(window, 3, 1, &on_key_release, loop);
	mlx_hook(window, 4, 2, &on_mouse_press, loop);
	mlx_hook(window, 5, 3, &on_mouse_release, loop);
	mlx_hook(window, 6, 6, &on_mouse_motion, loop);
	mlx_hook(window, 12, 15, &on_expose, loop);
	mlx_hook(window, 17, 0, &on_destroy, loop);
	mlx_loop_hook(loop->window->display->mlx, &on_tick, loop);
}
