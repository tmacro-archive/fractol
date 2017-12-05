/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   register.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmckinno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 17:53:35 by tmckinno          #+#    #+#             */
/*   Updated: 2017/12/04 17:53:37 by tmckinno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mcrlx.h"
#include "clct.h"
#include "keys.h"

void		register_tick_hook(t_evloop loop, t_genhandler handler)
{
	loop->on_tick = handler;
}

void		register_expose_hook(t_evloop loop, t_genhandler handler)
{
	loop->on_expose = handler;
}

void		register_key_hook(t_evloop loop, t_keyhandler handler,\
								int kc, int state)
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
