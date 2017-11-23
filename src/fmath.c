/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fmath.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmckinno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 13:47:12 by tmckinno          #+#    #+#             */
/*   Updated: 2017/11/12 13:47:14 by tmckinno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


t_cplx  cplx_add(t_cplx a, t_cplx b)
{
    t_cplx  ans;

    ans.x = a.x + b.x;
    ans.y = a.y + b.y;
    return (ans);
}

t_cplx cplx_sqr(t_cplx a)
{
    t_cplx ans;

    ans.x = a.x * a.x - a.y * a.y;
    ans.y = 2 * a.x * a.y;
    return (ans);
}

