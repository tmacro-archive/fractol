/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fmath.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmckinno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 13:40:16 by tmckinno          #+#    #+#             */
/*   Updated: 2017/11/12 13:40:18 by tmckinno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FMATH_H
# define FMATH_H

struct s_cplx;
struct s_fract;

typedef struct s_cplx	t_cplx;
typedef struct s_fract  t_fract;

struct					s_cplx
{
	double				x;
	double				y;
};

struct				  	s_fract
{
	t_cplx				c;
	t_cplx				z;
	double				tmp;
};

t_cplx					cplx_add(t_cplx a, t_cplx b);
t_cplx					cplx_sub(t_cplx a, t_cplx b);
t_cplx					cplx_mul(t_cplx a, t_cplx b);
t_cplx					cplx_sqr(t_cplx a);
t_cplx					cplx_squrt(t_cplx a);
#endif