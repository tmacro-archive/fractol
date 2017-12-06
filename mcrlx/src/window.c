/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmckinno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/13 15:00:55 by tmckinno          #+#    #+#             */
/*   Updated: 2017/10/13 15:00:58 by tmckinno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mcrlx.h"
#include "clct.h"

t_display	create_display(void)
{
	t_display	freshmeat;

	NULL_GUARD((freshmeat = (t_display)memalloc_inc(sizeof(struct s_display))));
	freshmeat->mlx = mlx_init();
	freshmeat->count = 0;
	return (freshmeat);
}

t_display	get_display(void)
{
	static t_display	display;

	if (display == NULL)
		display = create_display();
	return (display);
}

t_window	get_window(int index)
{
	t_display	display;

	NULL_GUARD((display = get_display()));
	if (index >= 0 && index < display->count)
		return (display->windows[index]);
	return (NULL);
}

t_window	create_window(t_point size, char *title, int segments, void *data)
{
	t_display	display;
	t_window	new;

	NULL_GUARD((display = get_display()));
	NULL_GUARD((new = (t_window)memalloc_inc(sizeof(struct s_window))));
	new->window = mlx_new_window(display->mlx, size[0], size[1], title);
	new->width = size[0];
	new->height = size[1];
	new->display = display;
	REF_INC((new->frame = create_frame(new, segments)));
	REF_INC((new->loop = create_loop(new, data)));
	display->windows[display->count] = new;
	display->count++;
	return (new);
}
