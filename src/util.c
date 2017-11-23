/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmckinno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 13:56:46 by tmckinno          #+#    #+#             */
/*   Updated: 2017/11/12 13:56:47 by tmckinno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void    iter_grid(t_point start, t_point max, void (*f)(int, int, void*), void *data)
{
    int x;
    int y;

    x = start[0];
    while (x < max[0])
    {
        y = start[1];
        while (y < max[1])
        {
            f(x, y, data);
            y++;
        }
        x++;
    }
}