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

// t_buffer	create_buffer(t_frame frame, int x, int y, int len)
// {
// 	t_buffer	buf;
// 	t_image		img;
// 	int			width;
// 	int			height;

// 	width = lroundf((float)frame->window->width / (float)len);
// 	height = lroundf((float)frame->window->width / (float)len);
// 	NULL_GUARD((img = create_image(width, height)));
// 	NULL_GUARD((buf = (t_buffer)memalloc(sizeof(struct s_buffer))));
// 	REF_INC((buf->image = img));
// 	buf->rndros[0] = x * width;
// 	buf->rndros[1] = y * height;
// 	buf->tl[0] = buf->rndros[0] - lroundf((float)frame->window->width / 2.0);
// 	buf->tl[1] = buf->rndros[1] - lroundf((float)frame->window->height / 2.0);
// 	// buf->x_offset = x * width;
// 	// buf->y_offset = y * height;
// 	buf->frame = frame;
// 	buf->changed = 0;
// 	return (buf);

// }

t_buffer	create_buffer(void)
{
	t_buffer	fresh;

	NULL_GUARD((fresh = (t_buffer)memalloc(sizeof(struct s_buffer))));
	SET_TUPLE(fresh->rndros, 0, 0);
	SET_TUPLE(fresh->tl, 0, 0);
	fresh->changed = 0;
	return (fresh);
}

t_buffer	*create_buffers(t_frame f, int len)
{
	int			p;
	int			q;
	t_buffer	*bufs;
	t_image		image;

	NULL_GUARD((image = create_image(f->window->width, f->window->height)));
	REF_INC(image);
	NULL_GUARD((bufs = (t_buffer*)memalloc(sizeof(t_buffer) * len * len)));
	p = 0;
	while (p < len)
	{
		q = 0;
		while (q < len)
		{
			REF_INC((*bufs = create_buffer()));
			SET_TUPLE((*bufs)->rndros, 
				lroundf((float)f->window->width / (float)len) * p,
				lroundf((float)f->window->height / (float)len) * q);
			SET_TUPLE((*bufs)->tl, 
				(*bufs)->rndros[0] - lroundf((float)f->window->width / 2.0),
				(*bufs)->rndros[1] - lroundf((float)f->window->height / 2.0));
			SET_TUPLE((*bufs)->size,
				lroundf((float)f->window->width / (float)len),
				lroundf((float)f->window->height / (float)len));
			(*bufs)->frame = f;
			(*bufs)->image = image;
			q++;
			bufs++;
		}
		p++;
	}
	return (bufs - (len * len));
}

// t_buffer    *create_buffers(t_frame frame, int len)
// {
// 	int				p;
// 	int				q;
// 	t_buffer		*buffers;
// 	int				pos;

// 	NULL_GUARD((buffers = (t_buffer*)memalloc(sizeof(t_buffer) * (len * len))));
// 	pos = 0;
// 	REF_INC((buffers[pos++] = create_buffer(frame, 0, 0, len)));
// 	q = 1;
// 	while (q < len)
// 	{
// 		p = 0;
// 		while (p < q)
// 		{
// 			REF_INC((buffers[pos++] = create_buffer(frame, p, q, len)));
// 			REF_INC((buffers[pos++] = create_buffer(frame, q, p, len)));
// 			p++;
// 		}
// 			REF_INC((buffers[pos++] = create_buffer(frame, q, q, len)));
// 		q++;
// 	}
// 	return (buffers);
// }

void	draw_buffer(t_buffer buffer)
{
	int	err;

	err = pthread_mutex_lock(&buffer->frame->lock);
	printf("err: %i\n", err);
	if (!err)
	{
		draw_image(buffer->frame->window, buffer->image, buffer->rndros[0], buffer->rndros[1]);
		buffer->changed = 0;
		pthread_mutex_unlock(&buffer->frame->lock);
	}
}

void	buf_set_pixel(t_buffer buffer, int x, int y, int color)
{
	img_set_pixel(buffer->image, x - buffer->tl[0] + buffer->rndros[0], y - buffer->tl[1] + buffer->rndros[1], color);
	buffer->changed = 1;
}