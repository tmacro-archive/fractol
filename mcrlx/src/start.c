/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmckinno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 18:13:33 by tmckinno          #+#    #+#             */
/*   Updated: 2017/12/04 18:13:35 by tmckinno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mcrlx.h"

void		*mcrlx_start_inner(void *display)
{
	mlx_loop(((t_display)display)->mlx);
	return (NULL);
}

pthread_t	mcrlx_start(void)
{
	t_display	display;
	pthread_t	thread;
	int			i;

	display = get_display();
	i = 0;
	while (i < display->count)
		pthread_create(&thread, NULL, &evloop, display->windows[i++]->loop);
	mlx_loop(display->mlx);
	return (thread);
}
