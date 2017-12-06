/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmckinno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/17 11:18:40 by tmckinno          #+#    #+#             */
/*   Updated: 2017/10/17 11:18:42 by tmckinno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mcrlx.h"
#include "clct.h"

/*
** Creates a reusable frame
** segments specifies the number of buffers that the frame will be sliced into.
** segements should be one of: SEG_4 SEG_16 SEG_64
*/

t_frame	create_frame(t_window window, int segments)
{
	t_frame	fresh;

	NULL_GUARD((fresh = (t_frame)memalloc(sizeof(struct s_frame))));
	fresh->window = window;
	fresh->segments = segments;
	fresh->buffers = create_buffers(fresh, segments);
	pthread_mutex_init(&fresh->lock, NULL);
	return (fresh);
}

void	draw_frame(t_frame frame)
{
	int	buffer;
	int	fail;

	buffer = 0;
	fail = pthread_mutex_trylock(&frame->lock);
	if (fail)
		return ;
	if ((*(frame->buffers))->changed)
		draw_image(frame->window, (*(frame->buffers))->image, 0, 0);
	pthread_mutex_unlock(&frame->lock);
}

void	iter_frame(t_frame frame, t_render f, void *data)
{
	int buffer;

	buffer = 0;
	while (buffer < frame->segments * frame->segments)
		f(frame->buffers[buffer++], data);
}

void	*iter_func_wrapper(void *data)
{
	t_rndrdata	d;

	d = (t_rndrdata)data;
	d->func(d->buffer, d->data);
	REF_DEC(data);
	return (NULL);
}

void	iter_frame_t(t_frame frame, t_render f, void *data)
{
	int			buffer;
	int			count;
	pthread_t	*ids;
	t_rndrdata	rdata;

	count = frame->segments * frame->segments;
	ids = memalloc_inc(sizeof(pthread_t) * count);
	buffer = 0;
	while (buffer < count)
	{
		rdata = (t_rndrdata)memalloc_inc(sizeof(struct s_rndrdata));
		rdata->buffer = frame->buffers[buffer];
		rdata->data = data;
		rdata->func = f;
		pthread_create((ids + buffer), NULL, &iter_func_wrapper, (void*)rdata);
		buffer++;
	}
	while (--buffer >= 0)
		pthread_join(ids[buffer], NULL);
	REF_DEC(ids);
}
