/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmckinno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 12:28:54 by tmckinno          #+#    #+#             */
/*   Updated: 2017/10/28 12:28:57 by tmckinno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fractol.h"

void	create_app(t_state state)
{
	t_window	win;

	int		size[2] = {1500, 1000};
	REF_INC((win = create_window(size, "Hello World!", SEG_9 , state)));
	register_tick_hook(win->loop, &render_handler);
	register_key_hook(win->loop, &plus_handler, KEY_NUM_PLUS, 1);
	register_key_hook(win->loop, &minus_handler, KEY_NUM_MINUS, 1);
	register_key_hook(win->loop, &plus_handler, KEY_MOUSE_SCROLL_UP, 1);
	register_key_hook(win->loop, &minus_handler, KEY_MOUSE_SCROLL_DN, 1);
	register_key_hook(win->loop, &esc_handler, KEY_ESC, 0);
	register_motion_hook(win->loop, &offset_handler);
}