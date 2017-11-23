/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmckinno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 11:06:51 by tmckinno          #+#    #+#             */
/*   Updated: 2017/10/19 11:06:53 by tmckinno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "mcrlx.h"


pthread_mutex_t	*get_render_lock(void)
{
	static pthread_mutex_t	render_lock;
	static int				initd;

	if(!initd)
	{
		pthread_mutex_init(&render_lock, NULL);
		initd = 1;
	}
	return (&render_lock);
}

void			render(t_frame frame, t_render rdr, void *data)
{
	iter_frame(frame, rdr, data);
	draw_frame(frame);
}

void			threaded_render(t_frame frame, t_render rdr, void *data)
{
	
	// if (!pthread_mutex_trylock(get_render_lock()))
	// {
		// printf("unlocked\n");
		if (!pthread_mutex_trylock(&frame->lock))
		{
			iter_frame_t(frame, rdr, data);
			pthread_mutex_unlock(&frame->lock);
		// printf("done rendering\n");
			draw_frame(frame);
		}
		// pthread_mutex_unlock(get_render_lock());
	// }
	// else
		// printf("locked\n");
		
}