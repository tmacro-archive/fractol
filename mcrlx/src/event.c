/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmckinno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 11:42:32 by tmckinno          #+#    #+#             */
/*   Updated: 2017/10/30 11:42:33 by tmckinno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "mcrlx.h"

t_event create_event(int id)
{
    t_event fresh;

    NULL_GUARD((fresh = memalloc_inc(sizeof(struct s_event))));
    fresh->id = id;
    fresh->kc = 0;
    fresh->x = 0;
    fresh->y = 0;
    fresh->state = 0;
    return (fresh);
}
