/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_ext.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmckinno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 17:44:05 by tmckinno          #+#    #+#             */
/*   Updated: 2017/12/04 17:44:07 by tmckinno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mcrlx.h"

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
	REF_DEC(event);
}
