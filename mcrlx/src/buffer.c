/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmckinno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/17 11:18:18 by tmckinno          #+#    #+#             */
/*   Updated: 2017/10/17 11:18:36 by tmckinno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mcrlx.h"
#include "clct.h"
#include "logr.h"

t_buffer	create_buffer(void)
{
	t_buffer	fresh;

	NULL_GUARD((fresh = (t_buffer)memalloc_inc(sizeof(struct s_buffer))));
	SET_TUPLE(fresh->rndros, 0, 0);
	SET_TUPLE(fresh->tl, 0, 0);
	fresh->changed = 0;
	return (fresh);
}

void		init_buffer(t_buffer buf, t_frame frame, t_point pos, int len)
{
	SET_TUPLE(buf->rndros,
		lroundf((double)frame->window->width / (double)len) * (double)pos[0],
		lroundf((double)frame->window->height / (double)len) * pos[1]);
	SET_TUPLE(buf->tl,
		buf->rndros[0] - lroundf((double)frame->window->width / 2.0),
		buf->rndros[1] - lroundf((double)frame->window->height / 2.0));
	SET_TUPLE(buf->size,
		lroundf((double)frame->window->width / (double)len),
		lroundf((double)frame->window->height / (double)len));
	buf->frame = frame;
}

t_buffer	*create_buffers(t_frame f, int len)
{
	t_point		pos;
	t_buffer	*bufs;
	t_image		image;

	NULL_GUARD((image = create_image(f->window->width, f->window->height)));
	NULL_GUARD((bufs = (t_buffer*)memalloc_inc(sizeof(t_buffer) * len * len)));
	pos[0] = 0;
	while (pos[0] < len)
	{
		pos[1] = 0;
		while (pos[1] < len)
		{
			*bufs = create_buffer();
			(*bufs)->image = image;
			init_buffer(*bufs, f, pos, len);
			pos[1] += 1;
			bufs++;
		}
		pos[0] += 1;
	}
	return (bufs - (len * len));
}

void		draw_buffer(t_buffer buffer)
{
	int	err;

	err = pthread_mutex_lock(&buffer->frame->lock);
	if (!err)
	{
		draw_image(buffer->frame->window, buffer->image,\
					buffer->rndros[0], buffer->rndros[1]);
		buffer->changed = 0;
		pthread_mutex_unlock(&buffer->frame->lock);
	}
}

void		buf_set_pixel(t_buffer buffer, int x, int y, int color)
{
	img_set_pixel(buffer->image, x - buffer->tl[0] + buffer->rndros[0],\
					y - buffer->tl[1] + buffer->rndros[1], color);
	buffer->changed = 1;
}
