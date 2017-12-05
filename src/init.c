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

void	create_app(t_state state, char *title)
{
	t_window	win;
	int			size[2];

	size[0] = WINDOW_WIDTH;
	size[1] = WINDOW_HEIGHT;
	REF_INC((win = create_window(size, title, SEG_256, state)));
	register_tick_hook(win->loop, &render_handler);
	register_key_hook(win->loop, &plus_handler, KEY_NUM_PLUS, 1);
	register_key_hook(win->loop, &minus_handler, KEY_NUM_MINUS, 1);
	register_key_hook(win->loop, &plus_handler, KEY_MOUSE_SCROLL_UP, 1);
	register_key_hook(win->loop, &minus_handler, KEY_MOUSE_SCROLL_DN, 1);
	register_key_hook(win->loop, &esc_handler, KEY_ESC, 0);
	register_key_hook(win->loop, &arrow_handler, KEY_UP, 1);
	register_key_hook(win->loop, &arrow_handler, KEY_DOWN, 1);
	register_key_hook(win->loop, &arrow_handler, KEY_LEFT, 1);
	register_key_hook(win->loop, &arrow_handler, KEY_RIGHT, 1);
	register_exit_hook(win->loop, &e_handler);
	register_motion_hook(win->loop, &pan_handler);
}
